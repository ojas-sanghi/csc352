#!/bin/bash

dirs=( "words" "paragraphs" "fold" )

for part in "${dirs[@]}"
do
    dir=tests.$part
    echo "Creating directory $dir"
    mkdir -p $dir
    for i in {1..50} ; do
        padded=$(printf "%02d" $i)
        n=t1$padded.stdin
        echo "Creating file $n"
        python3 ../a3/rnd.py --lines $i --words $i --newlines 3 > $dir/$n
    done
done


