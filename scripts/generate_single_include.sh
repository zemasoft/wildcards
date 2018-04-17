#!/bin/sh

scripts/GenSingleHeader.py -Iinclude include/wildcards/wildcards.hpp > single_include/wildcards_tmp.hpp
gcc -fpreprocessed -dD -E -P single_include/wildcards_tmp.hpp > single_include/wildcards.hpp 2> /dev/null
rm -f single_include/wildcards_tmp.hpp
