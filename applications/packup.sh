#!/usr/bin/env zsh

# 漫画压缩打包成 epub 文件
# 需要 pandoc, mogrify 以及 convert

set -e

workspace="$1"

showhelp() {
  echo "usage:  packup.sh [options] [dirname]"
  echo "options:"
  echo "  -h, --help     show this help page"
  exit $1
}
sizetomib() {
  printf "%0.2lf MiB" $(($1 / 1024.0 / 1024.0))
}
min() {
  echo -n $(($1 > $2 ? $2 : $1))
}
max() {
  echo -n $(($1 < $2 ? $2 : $1))
}

if [[ "$workspace" == "" ]]; then
  echo "error: no targets specified (use -h for help)"
  showhelp 1
fi

if [[ "$workspace" == "-h" ]] || [[ "$workspace" == "--help" ]]; then
  showhelp 0
fi

if [[ ! -d "$workspace" ]]; then
  echo "error: target not found: '$workspace'"
  exit 1
fi

echo "resolving directory '$workspace'..."

oldpwd="$PWD"
indexfile="index.md"
bookname=`basename "$workspace"`
authorname="$USER"
dirsize=`sizetomib $(du "$workspace" -d 0 -B 1 | cut -f1)`
filetotal=`find "$workspace" | grep -E "jpg|png" | wc -l`

if [[ "$filetotal" == "0" ]]; then
  echo "error: no images found in: '$workspace'"
  exit 1
fi

echo ""
echo "Directory (1) '$bookname'"
echo ""
echo "Total File Size:    $dirsize"
echo "Total Page Number:  $filetotal"
echo ""

read "?:: Proceed with packing? [Y/n]" goon
if [[ "$goon" == "n" ]] || [[ "$goon" == "N" ]]; then
  exit 1
fi

cd "$workspace"

# convert png to jpg
if {find * | grep -E "\\.png$" > /dev/null}; then
  echo ":: Converting png images to jpg images"
  
  pngs=(`find *.png`)
  length=${#pngs[@]}
  format="(%${#length}d/$length) mogrifing %s\n"

  for (( i = 1; i <= ${#pngs}; ++ i )); do
    file=${pngs[$i]}
    printf "$format" "$i" "$file"

    mogrify -format jpg "$file"
    rm -f "$file"
  done
fi

# resize images
echo ":: Resizing jpg images (1080x)"

images=($(find *.jpg | sort -V))
length=${#images[@]}
format="(%${#length}d/$length) converting %s\n"

for (( i = 1; i <= $length; ++ i )); do
  file=${images[$i]}

  printf "$format" "$i" "$file"

  convert -resize 1080x "$file" "tmp-$file"
  rm "$file"
  mv "tmp-$file" "$file"
done

echo ":: Generating index file"

if [ -f "$indexfile" ]; then
  rm "$indexfile"
fi
touch "$indexfile"

echo "% $bookname" >> "$indexfile"
echo "% $authorname" >> "$indexfile"
echo >> "$indexfile"

for ((i = 1; i <= $length; ++ i)); do
  if [[ $((i % 10)) -eq "1" ]]; then
    echo >> "$indexfile"
    echo "# Page $((i)) to $(min $((i + 9)) $length)" >> "$indexfile"
    echo >> "$indexfile"
  fi
  file=${images[$i]}
  echo "![$file](./$file)" >> "$indexfile"
done

echo ":: Packing up"

echo " -> pandoc '$indexfile' -o '$oldpwd/$bookname.epub'"
pandoc "$indexfile" -o "$oldpwd/$bookname.epub"
rm -f "$indexfile"

echo ""
echo ":: Finished with no error reported"
echo ""

cd "$oldpwd"

read "?:: Remove original directory? [y/N]" remove
if [[ "$remove" == "y" ]] || [[ "$remove" == "Y" ]]; then
  echo "(1/1) removing '$workspace'..."
  rm -rf "$workspace"
fi
