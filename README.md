[![Language](https://img.shields.io/badge/language-C++-blue.svg)](https://isocpp.org/)
[![Standard](https://img.shields.io/badge/C%2B%2B-11%2F14%2F17-blue.svg)](https://en.wikipedia.org/wiki/C%2B%2B#Standardization)
[![Licence](https://img.shields.io/badge/license-Boost%201.0-blue.svg)](http://www.boost.org/LICENSE_1_0.txt)
[![Travis status](https://travis-ci.org/zemasoft/wildcards.svg?branch=master)](https://travis-ci.org/zemasoft/wildcards)
[![Appveyor status](https://ci.appveyor.com/api/projects/status/github/zemasoft/wildcards?svg=true&branch=master)](https://ci.appveyor.com/project/zemasoft/wildcards)
[![Github Releases](https://img.shields.io/github/release/zemasoft/wildcards.svg)](https://github.com/zemasoft/wildcards/releases)
[![Try it online](https://img.shields.io/badge/try%20it-online-blue.svg)](https://github.com/zemasoft/wildcards/tree/master/example)

Introduction
============

Wildcards is a simple C++ library which implements matching using wildcards.

Requirements
============

Wildcards require a C++11 compiler to build.

Usage
=====

1. Single-header approach
   * Copy `wildcards.hpp` from the Wildcards single_include directory to your
     project's header search path.
   * Add `#include <wildcards.hpp>` to your source file.
   * Use `wildcards::match()`.

2. Multi-header approach
   * Add the Wildcards include directory to your project's header search path.
   * Add `#include <wildcards.hpp>` to your source file.
   * Use `wildcards::match()`.

Examples
========

```C++
// main.cpp

#include <wildcards.hpp>

int main()
{
  static_assert(wildcards::match("Hallo, World!", "H*d?"), "");

  return 0;
}
```
