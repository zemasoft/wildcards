// Copyright Tomas Zeman 2018.
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef WILDCARDS_WILDCARDS_HPP
#define WILDCARDS_WILDCARDS_HPP

#include <iterator>     // std::begin, std::end, std::next
#include <type_traits>  // std::remove_cv, std::remove_reference
#include <utility>      // std::declval, std::forward, std::get, std::pair

// Compiler detection:
// Note: MSVC supports C++14 since it supports C++17.

#ifdef _MSVC_LANG
#define wc_MSVC_LANG _MSVC_LANG
#else
#define wc_MSVC_LANG 0
#endif

#define wc_CPP11_OR_GREATER (__cplusplus >= 201103L || wc_MSVC_LANG >= 201103L)
#define wc_CPP14_OR_GREATER (__cplusplus >= 201402L || wc_MSVC_LANG >= 201703L)
#define wc_CPP17_OR_GREATER (__cplusplus >= 201703L || wc_MSVC_LANG >= 201703L)

#if defined(_MSC_VER) && !defined(__clang__)
#define wc_COMPILER_MSVC_VERSION (_MSC_VER / 100 - 5 - (_MSC_VER < 1900))
#else
#define wc_COMPILER_MSVC_VERSION 0
#endif

// Presence of C++11 language features:

#define wc_CPP11_10 (wc_CPP11_OR_GREATER || wc_COMPILER_MSVC_VERSION >= 10)
#define wc_CPP11_11 (wc_CPP11_OR_GREATER || wc_COMPILER_MSVC_VERSION >= 11)
#define wc_CPP11_12 (wc_CPP11_OR_GREATER || wc_COMPILER_MSVC_VERSION >= 12)
#define wc_CPP11_14 (wc_CPP11_OR_GREATER || wc_COMPILER_MSVC_VERSION >= 14)

// Presence of C++14 language features:

#define wc_CPP14_00 (wc_CPP14_OR_GREATER)
#define wc_CPP14_14 (wc_CPP14_OR_GREATER || wc_COMPILER_MSVC_VERSION >= 14)

#define wc_HAVE_CONSTEXPR_14 wc_CPP14_00

// Presence of C++17 language features:

#define wc_CPP17_00 (wc_CPP17_OR_GREATER)

#define wc_HAVE_CONSTEXPR_17 wc_CPP17_00

// C++ feature usage:

#if wc_HAVE_CONSTEXPR_14
#define wc_constexpr14 constexpr
#else
#define wc_constexpr14 /*constexpr*/
#endif

#if wc_HAVE_CONSTEXPR_17
#define wc_constexpr17 constexpr
#else
#define wc_constexpr17 /*constexpr*/
#endif

namespace wildcards
{

template <typename T>
struct cards;

template <>
struct cards<char> : public std::pair<char, char>
{
  wc_constexpr14 cards() : std::pair<char, char>{'*', '?'}
  {
  }
};

template <>
struct cards<char16_t> : public std::pair<char16_t, char16_t>
{
  wc_constexpr14 cards() : std::pair<char16_t, char16_t>{u'*', u'?'}
  {
  }
};

template <>
struct cards<char32_t> : public std::pair<char32_t, char32_t>
{
  wc_constexpr14 cards() : std::pair<char32_t, char32_t>{U'*', U'?'}
  {
  }
};

template <>
struct cards<wchar_t> : public std::pair<wchar_t, wchar_t>
{
  wc_constexpr14 cards() : std::pair<wchar_t, wchar_t>{L'*', L'?'}
  {
  }
};

template <typename T, typename U>
struct equal
{
  constexpr bool operator()(const T& lhs, const U& rhs) const noexcept(noexcept(lhs == rhs))
  {
    return lhs == rhs;
  }
};

namespace detail
{

template <typename C>
wc_constexpr17 auto begin(C& c) noexcept(noexcept(std::begin(c))) -> decltype(std::begin(c))
{
  return std::begin(c);
}

template <typename C>
wc_constexpr17 auto begin(const C& c) noexcept(noexcept(std::begin(c))) -> decltype(std::begin(c))
{
  return std::begin(c);
}

template <typename T, std::size_t N>
constexpr T* begin(T (&array)[N]) noexcept
{
  return array;
}

constexpr char* begin(char& c) noexcept
{
  return &c;
}

constexpr const char* begin(const char& c) noexcept
{
  return &c;
}

constexpr char16_t* begin(char16_t& c) noexcept
{
  return &c;
}

constexpr const char16_t* begin(const char16_t& c) noexcept
{
  return &c;
}

constexpr char32_t* begin(char32_t& c) noexcept
{
  return &c;
}

constexpr const char32_t* begin(const char32_t& c) noexcept
{
  return &c;
}

constexpr wchar_t* begin(wchar_t& c) noexcept
{
  return &c;
}

constexpr const wchar_t* begin(const wchar_t& c) noexcept
{
  return &c;
}

template <typename C>
wc_constexpr17 auto end(C& c) noexcept(noexcept(std::end(c))) -> decltype(std::end(c))
{
  return std::end(c);
}

template <typename C>
wc_constexpr17 auto end(const C& c) noexcept(noexcept(std::end(c))) -> decltype(std::end(c))
{
  return std::end(c);
}

template <typename T, std::size_t N>
constexpr T* end(T (&array)[N]) noexcept
{
  return array + N;
}

constexpr char* end(char& c) noexcept
{
  return &c + 1;
}

constexpr const char* end(const char& c) noexcept
{
  return &c + 1;
}

constexpr char16_t* end(char16_t& c) noexcept
{
  return &c + 1;
}

constexpr const char16_t* end(const char16_t& c) noexcept
{
  return &c + 1;
}

constexpr char32_t* end(char32_t& c) noexcept
{
  return &c + 1;
}

constexpr const char32_t* end(const char32_t& c) noexcept
{
  return &c + 1;
}

constexpr wchar_t* end(wchar_t& c) noexcept
{
  return &c + 1;
}

constexpr const wchar_t* end(const wchar_t& c) noexcept
{
  return &c + 1;
}

template <typename C>
using value_type = typename std::remove_cv<
    typename std::remove_reference<decltype(*detail::begin(std::declval<C>()))>::type>::type;

template <typename SequenceIterator, typename PatternIterator, typename Cards, typename Equal>
wc_constexpr14 bool match(SequenceIterator s, SequenceIterator send, PatternIterator p,
                          PatternIterator pend, const Cards& cards, const Equal& equal)
{
  if (p == pend)
  {
    return s == send;
  }

  if (*p != std::get<0>(cards))
  {
    if (s == send)
    {
      return false;
    }

    if (*p == std::get<1>(cards) || equal(*s, *p))
    {
      return match(std::next(s), send, std::next(p), pend, cards, equal);
    }

    return false;
  }

  return match(s, send, std::next(p), pend, cards, equal) ||
         ((s != send) && match(std::next(s), send, p, pend, cards, equal));
}

}  // namespace detail

template <typename Sequence, typename Pattern, typename Cards = cards<detail::value_type<Pattern>>,
          typename Equal = equal<detail::value_type<Sequence>, detail::value_type<Pattern>>>
wc_constexpr14 bool match(Sequence&& sequence, Pattern&& pattern, Cards&& cards = Cards(),
                          Equal&& equal = Equal())
{
  return detail::match(detail::begin(std::forward<Sequence>(sequence)),
                       detail::end(std::forward<Sequence>(sequence)),
                       detail::begin(std::forward<Pattern>(pattern)),
                       detail::end(std::forward<Pattern>(pattern)), std::forward<Cards>(cards),
                       std::forward<Equal>(equal));
}

}  // namespace wildcards

#endif  // WILDCARDS_WILDCARDS_HPP
