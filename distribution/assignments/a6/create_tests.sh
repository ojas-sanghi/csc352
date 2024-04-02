#!/bin/bash

dirs=( "bowling" )

for part in "${dirs[@]}"
do
    dir=tests.$part
    echo "Creating directory $dir"
    mkdir -p $dir
    for i in {1..50} ; do
        padded=$(printf "%02d" $i)
        n=t1$padded.stdin
        echo "Creating file $n"
        python3 gen.py  > $dir/$n
    done
done


