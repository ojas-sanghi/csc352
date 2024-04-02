#/bin/bash

root_dir=/tmp/distribution
submission_dir=../solutions/a5/
output=/tmp/results.json
metadata=./faux_metadata.json

echo "Running autograder with the following parameters:"
echo "root_dir: $root_dir"
echo "submission_dir: $submission_dir"
echo "output: $output"
echo "metadata: $metadata"

python3 $root_dir/gradescope/autograder.py \
    --root_dir $root_dir \
    --submission_dir $submission_dir \
    --output $output \
    --metadata $metadata

echo "Autograder complete. Results are in $output"
cat $output