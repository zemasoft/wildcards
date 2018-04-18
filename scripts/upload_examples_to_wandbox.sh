#!/bin/sh

readonly WANDBOX_DIR=wandbox

rm -rf "$WANDBOX_DIR"
mkdir -p "$WANDBOX_DIR"

./scripts/generate_single_include.sh

for example in $(find example -maxdepth 1 -type f -name '*.cpp'); do
  awk 'BEGIN { count1=0; count2=0 } { if ($0 ~ /^#include \"cx\//) { if (!count1) { print "#include \"cx.hpp\""; count1++ } } else if ($0 ~ /^#include \"wildcards\//) { if (!count2) { print "#include \"wildcards.hpp\""; count2++ } } else { print $0 } }' "$example" > "$WANDBOX_DIR/"$(basename "$example")
done

for example in $(find "$WANDBOX_DIR" -maxdepth 1 -type f -name '*.cpp'); do
  EXAMPLE_URL=$(scripts/send_to_wandbox.py single_include "$example" | sed -e 's/.*\(http:\/\/[^ '"'"']*\).*/\1/')
  echo "$example: $EXAMPLE_URL"
done
