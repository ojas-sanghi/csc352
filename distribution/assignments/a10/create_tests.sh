#!/bin/bash

dirs=( read scale sum )

for part in "${dirs[@]}"
do
    dir=tests.$part
    echo "Creating directory $dir"
    mkdir -p $dir
    for size in 1 2 3 4 5 10 20 ; do
	    # compute depth cubed
	    for i in `seq 1 $size` ; do
			padded=$(printf "%02d_%02d" $size $i)
			n=t$padded.stdin
			echo "Creating file $n"
			python3 gen.py --size $size --numints $size > $dir/$n
	    done
    done
done


