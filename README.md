[![language.badge]][language.url] [![standard.badge]][standard.url] [![license.badge]][license.url] [![travis.badge]][travis.url] [![appveyor.badge]][appveyor.url] [![release.badge]][release.url] [![wandbox.badge]][wandbox.url]

# Wildcards

## Introduction

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

## Usage

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

## Example

```C++
// main.cpp

#include <wildcards.hpp>

int main()
{
  static_assert(wildcards::match("source.c", "*.[hc](pp|)"), "wrong file name");

  return 0;
}
```

This example does nothing very useful. It only demonstrates a simple usage
of the library and the iteresting fact that it can also be used at compile time.

Please see more useful and complex examples [here](example) and try them online!

## Portability

*Wildcards* requires a C++11 compiler to build. It has no external dependencies.

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

## License

This project is licensed under the [Boost 1.0][license.url].

## Technical Notes

* *Wildcards* uses a recursive approach. Hence you can simply run out of stack
(during runtime execution) or you can exceed the maximum depth of constexpr
evaluation (during compile time execution). If so, try to make the input
sequence shorter or the pattern less complex. You can also try to build using
a C++14 compiler since the C++14 implementation of the library is more effective
and consumes less resources.

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

[wandbox.url]:    https://github.com/zemasoft/wildcards/tree/master/example
[wandbox.badge]:  https://img.shields.io/badge/try%20it-on%20wandbox-blue.svg

[godbolt.url]:    https://godbolt.org/z/rGi5c2
[godbolt.badge]:  https://img.shields.io/badge/try%20it-on%20godbolt-blue.svg
