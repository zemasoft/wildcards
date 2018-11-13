[![language.badge]][language.url] [![standard.badge]][standard.url] [![license.badge]][license.url] [![travis.badge]][travis.url] [![appveyor.badge]][appveyor.url] [![release.badge]][release.url] [![godbolt.badge]][godbolt.url] [![wandbox.badge]][wandbox.url]

# Wildcards

## Overview

*Wildcards* is a simple C++ header-only template library which implements
a general purpose algorithm for matching using wildcards. It supports both
runtime and compile time execution.

```C++
// main.cpp

#include <wildcards.hpp>

int main()
{
  using namespace wildcards;

  static_assert(match("source.c", "*.[hc](pp|)"), "wrong file name");

  return 0;
}
```

Check what compilers output for a similar case on
[Compiler Explorer][godbolt.url]. See also more useful and complex
[examples](example) and try them online!

## Quick Start

1. Single-header approach
   * Copy [`wildcards.hpp`](single_include/wildcards.hpp) from
     [`single_include`](single_include) directory to your project's header
     search path.
   * Add `#include <wildcards.hpp>` to your source file.
   * Use `wildcards::match()`.

2. Multi-header approach
   * Add [`include`](include) directory to your project's header search path.
   * Add `#include <wildcards.hpp>` to your source file.
   * Use `wildcards::match()`.

## Portability

The library requires at least a C++11 compiler to build. It has no external
dependencies.

The following compilers are continuously tested at [Travis CI][travis.url]
and [Appveyor CI][appveyor.url].

| Compiler            | Version | Operating System    |
|---------------------|---------|---------------------|
| Xcode               | 9.0     | OS X 10.12          |
| Clang (with libcxx) | 3.9     | Ubuntu 14.04 LTS    |
| Clang (with libcxx) | 4.0     | Ubuntu 14.04 LTS    |
| Clang (with libcxx) | 5.0     | Ubuntu 14.04 LTS    |
| Clang (with libcxx) | 6.0     | Ubuntu 14.04 LTS    |
| GCC                 | 5.5     | Ubuntu 14.04 LTS    |
| GCC                 | 6.4     | Ubuntu 14.04 LTS    |
| GCC                 | 7.3     | Ubuntu 14.04 LTS    |
| GCC                 | 8.1     | Ubuntu 14.04 LTS    |
| Visual Studio       | 14 2015 | Windows Server 2016 |
| Visual Studio       | 15 2017 | Windows Server 2016 |

NOTE: Clang 3.9 works only for C++14 standard or higher.

## License

This project is licensed under the [Boost 1.0][license.url].

## Details

### Syntax

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

### Technical Notes

* *Wildcards* uses a recursive approach. Hence you can simply run out of stack
(during runtime execution) or you can exceed the maximum depth of constexpr
evaluation (during compile time execution). If so, try making the input
sequence shorter or the pattern less complex. You can also try to build using
the C++14 standard since the C++14 implementation of the library is more
effective and consumes less resources.
* The `cx` library is a byproduct created during the development of *Wildcards*
which uses some pieces from its functionality internally. More of the `cx` is
used in tests. You can use this library in exactly the same way as you use
*Wildcards* (single-header / multi-header approach) but if you are interested
only in *Wildcards*, you don't need to care/know about the `cx` at all. This
library might become a separate project in the future.

[language.url]:   https://isocpp.org/
[language.badge]: https://img.shields.io/badge/language-C++-blue.svg

[standard.url]:   https://en.wikipedia.org/wiki/C%2B%2B#Standardization
[standard.badge]: https://img.shields.io/badge/C%2B%2B-11%2F14%2F17-blue.svg

[license.url]:     http://www.boost.org/LICENSE_1_0.txt
[license.badge]:  https://img.shields.io/badge/license-Boost%201.0-blue.svg

[travis.url]:     https://travis-ci.org/zemasoft/wildcards
[travis.badge]:   https://travis-ci.org/zemasoft/wildcards.svg?branch=master

[appveyor.url]:   https://ci.appveyor.com/project/zemasoft/wildcards
[appveyor.badge]: https://ci.appveyor.com/api/projects/status/github/zemasoft/wildcards?svg=true&branch=master

[release.url]:    https://github.com/zemasoft/wildcards/releases
[release.badge]:  https://img.shields.io/github/release/zemasoft/wildcards.svg

[godbolt.url]:    https://godbolt.org/z/rGi5c2
[godbolt.badge]:  https://img.shields.io/badge/try%20it-on%20godbolt-blue.svg

[wandbox.url]:    https://github.com/zemasoft/wildcards/tree/master/example
[wandbox.badge]:  https://img.shields.io/badge/try%20it-on%20wandbox-blue.svg
