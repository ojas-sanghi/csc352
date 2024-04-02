#!/bin/bash

tgt=/tmp/gradescope.zip
dist_dir=/tmp

rm -f "$tgt"
zip -r "$tgt" setup.sh run_autograder autograder.py utilities.py gradescope.json
cp gradescope.json "$dist_dir/distribution"
(cd $dist_dir ; zip -r "$tgt" distribution)
cp "$tgt" ~/tmp
