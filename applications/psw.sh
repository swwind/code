#!/usr/bin/env zsh

bindkey "\e[3~" delete-char

# calculate md5 hash
md5() {
  echo -n $(echo -n $1 | md5sum | head -c 32)
}

# $1 = str, $2 = key, $3 = times
hash() {

  # return times ? hash(md5(str + key), str, times - 1) : str;

  if [[ $3 == 0 ]]
  then
    echo -n $1
  else
    echo -n $(hash $(md5 $1$2) "$1" $[$3 - 1])
  fi
}

# $1 = str1, $2 = str2, $3 = str3, $4 = type
main() {

  # const h1 = hash(str1, str2, 10);
  # const h2 = hash(str2, str3, 10);
  # const h3 = hash(str3, str1, 10);

  h1=$(hash "$1" "$2" 10)
  h2=$(hash "$2" "$3" 10)
  h3=$(hash "$3" "$1" 10)

  # const h4 = hash(str1, str3, 10);
  # const h5 = hash(str2, str1, 10);
  # const h6 = hash(str3, str2, 10);

  h4=$(hash "$1" "$3" 10)
  h5=$(hash "$2" "$1" 10)
  h6=$(hash "$3" "$2" 10)

  # const r1 = hash(md5(h1 + h2 + h3), type, 10);
  # const r2 = hash(md5(h4 + h5 + h6), type, 10);

  r1=$(hash $(md5 $h1$h2$h3) "$4" 10)
  r2=$(hash $(md5 $h4$h5$h6) "$4" 10)

  # return btoa(hash(r1, r2, 10)).slice(0, 16);

  echo -n $(echo -n $(hash $r1 $r2 10) | base64 | head -c 16)
}

# const str1 = await queryPassword('Password#1: ');
# const str2 = await queryPassword('Password#2: ');
# const str3 = await queryPassword('Password#3: ');

echo -n 'Password#1: '
read -s str1
echo

echo -n 'Password#2: '
read -s str2
echo

echo -n 'Password#3: '
read -s str3
echo

# console.log(main(str1, str2, str3, ''));

echo $(main "$str1" "$str2" "$str3" "")

# const type = await queryPassword('Website: ', false);

echo -n 'Website: '
read type

# console.log(main(str1, str2, str3, type));

result=$(main "$str1" "$str2" "$str3" "$type")

echo $result
echo -n $result | xclip -in -selection clipboard

echo 'Copied to clipboard.'
