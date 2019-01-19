#!/usr/bin/env bash

set -e

hassubdir() {

  subdircount=`find "$1" -maxdepth 1 -type d | wc -l`

  if [ $subdircount -eq 1 ]; then
    return 0
  else
    return 1
  fi

}

find . -type d | while read dir;
do
  # echo "Checking \"$dir\""
  if hassubdir "$dir"; then
    echo ".==========================="
    echo "| "
    echo "$ packup.sh \"$dir\""
    echo "| "
    yes | packup.sh "$dir"
  fi
done

