#!/bin/bash

dir="$1"

shift

if [ "$1" != "--" ]; then
    echo "Error: Missing '--' separator"
    exit 1
fi

shift

invocation="$@"

OUTPUT_CMIN="$(mktemp -d /tmp/cmin.XXXXX)"
OUTPUT_TMIN="$(basename $dir).tmin"

mkdir $OUTPUT_TMIN

afl-cmin -i "$dir" -o "$OUTPUT_CMIN" \-\- $invocation

for file in "$OUTPUT_CMIN"/*; do
    if [ -f "$file" ]; then
        filename=$(basename "$file")
        afl-tmin -i "$file" -o "$OUTPUT_TMIN/${filename}.tmin" \-\- $invocation
    fi
done
