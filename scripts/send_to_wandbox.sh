#!/bin/sh

# Copyright Tomas Zeman 2018.
# Distributed under the Boost Software License, Version 1.0.
# (See accompanying file LICENSE_1_0.txt or copy at
# http://www.boost.org/LICENSE_1_0.txt)

readonly WANDBOX_DIR="wandbox"

rm -rf "$WANDBOX_DIR"
mkdir -p "$WANDBOX_DIR/include" "$WANDBOX_DIR/tmp"

for header in $(find include -type f -name '*.hpp' -printf '%P\n'); do
  echo "#include \"$header\""
done > "$WANDBOX_DIR/tmp/wildcards.hpp"

scripts/GenSingleHeader.py -Iinclude "$WANDBOX_DIR/tmp/wildcards.hpp" > "$WANDBOX_DIR/tmp/wildcards_single_header.hpp"

gcc -fpreprocessed -dD -E -P "$WANDBOX_DIR/tmp/wildcards_single_header.hpp" > "$WANDBOX_DIR/include/wildcards_single_header.hpp" 2> /dev/null

for example in $(find example -maxdepth 1 -type f -name '*.cpp'); do
  awk 'BEGIN { count=0 } { if ($0 ~ /^#include \"config.hpp\"/ || $0 ~ /^#include \"cx\// || $0 ~ /^#include \"wildcards\//) { if (!count) { print "#include \"wildcards_single_header.hpp\""; count++ } } else { print $0 } }' "$example" > "$WANDBOX_DIR/"$(basename "$example")
done

for example in $(find "$WANDBOX_DIR" -maxdepth 1 -type f -name '*.cpp'); do
  EXAMPLE_URL=$(scripts/send_to_wandbox.py "$WANDBOX_DIR/include" "$example" | sed -e 's/.*\(http:\/\/[^ '"'"']*\).*/\1/')
  echo "$example: $EXAMPLE_URL"
done
