// Copyright Tomas Zeman 2018.
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef CONFIG_HPP
#define CONFIG_HPP

// Compiler detection:
// Note: MSVC supports C++14 since it supports C++17.

#ifdef _MSVC_LANG
#define cfg_MSVC_LANG _MSVC_LANG
#else
#define cfg_MSVC_LANG 0
#endif

#define cfg_CPP11_OR_GREATER (__cplusplus >= 201103L || cfg_MSVC_LANG >= 201103L)
#define cfg_CPP14_OR_GREATER (__cplusplus >= 201402L || cfg_MSVC_LANG >= 201703L)
#define cfg_CPP17_OR_GREATER (__cplusplus >= 201703L || cfg_MSVC_LANG >= 201703L)

#if defined(_MSC_VER) && !defined(__clang__)
#define cfg_COMPILER_MSVC_VERSION (_MSC_VER / 100 - 5 - (_MSC_VER < 1900))
#else
#define cfg_COMPILER_MSVC_VERSION 0
#endif

// Presence of C++11 language features:

#define cfg_CPP11_10 (cfg_CPP11_OR_GREATER || cfg_COMPILER_MSVC_VERSION >= 10)
#define cfg_CPP11_11 (cfg_CPP11_OR_GREATER || cfg_COMPILER_MSVC_VERSION >= 11)
#define cfg_CPP11_12 (cfg_CPP11_OR_GREATER || cfg_COMPILER_MSVC_VERSION >= 12)
#define cfg_CPP11_14 (cfg_CPP11_OR_GREATER || cfg_COMPILER_MSVC_VERSION >= 14)

// Presence of C++14 language features:

#define cfg_CPP14_00 (cfg_CPP14_OR_GREATER)
#define cfg_CPP14_14 (cfg_CPP14_OR_GREATER || cfg_COMPILER_MSVC_VERSION >= 14)

#define cfg_HAVE_CONSTEXPR_14 cfg_CPP14_00

// Presence of C++17 language features:

#define cfg_CPP17_00 (cfg_CPP17_OR_GREATER)

#define cfg_HAVE_CONSTEXPR_17 cfg_CPP17_00

// C++ feature usage:

#if cfg_HAVE_CONSTEXPR_14
#define cfg_constexpr14 constexpr
#else
#define cfg_constexpr14 /*constexpr*/
#endif

#if cfg_HAVE_CONSTEXPR_17
#define cfg_constexpr17 constexpr
#else
#define cfg_constexpr17 /*constexpr*/
#endif

#endif  // CONFIG_HPP
