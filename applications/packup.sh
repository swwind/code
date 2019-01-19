#!/usr/bin/env bash

# 漫画压缩打包成 epub 文件
# 需要 pandoc, mogrify 以及 convert

workspace="$1"
indexfile="index.md"
bookname=$(basename "$workspace")
authorname="$USER"
currentdir="$PWD"

if [ ! -d "$workspace" ]; then
  echo "$workspace does not exist not is not a directory"
  exit 1
fi

echo "resolving directory \"$workspace\"..."
echo ""
echo "book title: $bookname"
echo "book author: $authorname"
echo ""

read -p ":: Proceed with packing? [Y/n]" goon
if [ "$goon" == "n" ] || [ "$goon" == "N" ]; then
  exit 1
fi

cd "$workspace"

if [ -f "$indexfile" ]; then
  rm "$indexfile"
fi

# convert png to jpg
if find *.png > /dev/null 2>&1; then
  echo "==> Converting png images to jpg images"
  mogrify -format jpg *.png
  rm -f *.png
  echo ":: done"
fi

images=($(find *.jpg | sort -V))
length=${#images[@]}
lenlen=${#length}

indent() {
  if [ "$1" == "0" ]; then
    echo -n
  else
    printf ' %.0s' {1..$1}
  fi
}

echo "==> Compressing jpg images (1080 x *)"

for ((i = 0; i < $length; ++ i)); do
  position=$(( $i + 1 ))
  file=${images[$i]}
  poslen=${#position}
  offset=$(indent $((lenlen - poslen)))

  echo "($offset$position,$length) converting $file"

  convert -resize 1080x "$file" "tmp-$file"
  rm "$file"
  mv "tmp-$file" "$file"
done

echo "==> Generating index file"

touch "$indexfile"

echo "% $bookname" >> "$indexfile"
echo "% $authorname" >> "$indexfile"
echo >> "$indexfile"

min() {
  echo -n $(($1 > $2 ? $2 : $1))
}

for ((i = 0; i < $length; ++ i)); do
  if [ $((i % 10)) == 0 ]; then
    echo >> "$indexfile"
    echo "# Page $((i + 1)) to $(min $((i + 10)) $length)" >> "$indexfile"
    echo >> "$indexfile"
  fi
  file=${images[$i]}
  echo "![$file](./$file)" >> "$indexfile"
done

echo "==> Packing up"

echo "$ pandoc \"$indexfile\" -o \"$bookname.epub\""
pandoc "$indexfile" -o "$bookname.epub"
echo "$ mv \"$bookname.epub\" \"$currentdir\""
mv "$bookname.epub" "$currentdir"

echo ""
echo "Done, file placed at $currentdir/$bookname.epub"
echo ""

cd "$currentdir"

read -p "Remove origin directory? [y/N]" remove
if [ "$remove" == "y" ] || [ "$remove" == "Y" ]; then
  echo "Removing \"$workspace\""
  rm -rf "$workspace"
fi
