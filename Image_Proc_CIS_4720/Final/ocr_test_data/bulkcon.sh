#!/bin/bash
for img in *.jpg
do
    filename=$(basename "$img")
    extension="${filename##*.}"
    filename="${filename%.*}"
    echo $filename
    convert "$img" "$filename.png"
done
