[![Language](https://img.shields.io/badge/language-C++-blue.svg)](https://isocpp.org/)
[![Standard](https://img.shields.io/badge/C%2B%2B-11%2F14%2F17-blue.svg)](https://en.wikipedia.org/wiki/C%2B%2B#Standardization)
[![Licence](https://img.shields.io/badge/license-Boost%201.0-blue.svg)](http://www.boost.org/LICENSE_1_0.txt)
[![Travis status](https://travis-ci.org/zemasoft/wildcards.svg?branch=master)](https://travis-ci.org/zemasoft/wildcards)
[![Appveyor status](https://ci.appveyor.com/api/projects/status/github/zemasoft/wildcards?svg=true&branch=master)](https://ci.appveyor.com/project/zemasoft/wildcards)
[![Github Releases](https://img.shields.io/github/release/zemasoft/wildcards.svg)](https://github.com/zemasoft/wildcards/releases)
[![Try it online](https://img.shields.io/badge/try%20it-online-blue.svg)](https://github.com/zemasoft/wildcards/tree/master/example)

Introduction
============

*Wildcards* is a simple C++ header-only template library which implements
a general purpose algorithm for matching using wildcards. It supports both
runtime and compile time execution.

| Pattern   | Meaning                                        |
| --------- | ---------------------------------------------- |
| `*`       | Matches everything.                            |
| `?`       | Matches any single character.                  |
| `\`       | Escape character.                              |
| `[abc]`   | Matches any character in *Set*.                |
| `[!abc]`  | Matches any character not in *Set*.            |
| `(ab\|c)` | Matches one of the sequences in *Alternative*. |

* *Set* cannot be empty. Any special character loses its special meaning in it.
* *Alternative* can contain more than two or just one sequence.
* The use of *Sets* and *Alternatives* can be switched off.
* Special characters are predefined for `char`, `char16_t`, `char32_t`
  and `wchar_t`, but can be redefined.

Requirements
============

*Wildcards* requires a C++11 compiler to build. It has no external dependencies
and has been tested with gcc 5.5, gcc 6.4, gcc 7.3, clang 4.0 (with libcxx),
clang 5.0 (with libcxx), Xcode 9.0, Visual Studio 14 2015
and Visual Studio 15 2017.

Usage
=====

1. Single-header approach
   * Copy `wildcards.hpp` from the [single_include](single_include) directory
     to your project's header search path.
   * Add `#include <wildcards.hpp>` to your source file.
   * Use `wildcards::match()`.

2. Multi-header approach
   * Add the [include](include) directory to your project's header search path.
   * Add `#include <wildcards.hpp>` to your source file.
   * Use `wildcards::match()`.

Examples
========

```C++
// main.cpp

#include <wildcards.hpp>

int main()
{
  using wildcards::match;
  
  static_assert(match("source.c", "*.([hc](pp|))"), "invalid file name");

  return 0;
}
```

See more examples [here](example) and try them online!

Technical Notes
===============

* *Wildcards* uses a recursive approach. Hence you can simply run out of stack
(during runtime execution) or you can exceed the maximum number of template
recursion depth (during compile time execution). If so, try to make the input
sequence shorter or the pattern less complex. You can also try to build using
a C++14 compiler since the C++14 implementation is more effective and consumes
less resources.
