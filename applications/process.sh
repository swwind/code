#!/bin/bash

for i in {01..31}
do
  mv acg.gy_$i.jpg $i.jpg
  jpegoptim $i.jpg
  convert -resize x200 $i.jpg $i-thumbnail.jpg
done

# 02-thumbnail.jpg --> 2-thumbnail.jpg

for i in $(find . | grep -G "0[0-9]-thumbnail.jpg$")
do
  mv $i $(dirname $i)/$(basename $i | cut -d'0' -f2)
done

# 02.jpg --> 2.jpg

for i in $(find . | grep -G "0[0-9].jpg$")
do
  mv $i $(dirname $i)/$(basename $i | cut -d'0' -f2)
done
