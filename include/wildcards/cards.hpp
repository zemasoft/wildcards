// Copyright Tomas Zeman 2018.
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef WILDCARDS_CARDS_HPP
#define WILDCARDS_CARDS_HPP

#include <cx/utility.hpp>  // cx::pair

namespace wildcards
{

template <typename T>
struct cards;

template <>
struct cards<char> : public cx::pair<char, char>
{
  constexpr cards() : cx::pair<char, char>{'*', '?'}
  {
  }
};

template <>
struct cards<char16_t> : public cx::pair<char16_t, char16_t>
{
  constexpr cards() : cx::pair<char16_t, char16_t>{u'*', u'?'}
  {
  }
};

template <>
struct cards<char32_t> : public cx::pair<char32_t, char32_t>
{
  constexpr cards() : cx::pair<char32_t, char32_t>{U'*', U'?'}
  {
  }
};

template <>
struct cards<wchar_t> : public cx::pair<wchar_t, wchar_t>
{
  constexpr cards() : cx::pair<wchar_t, wchar_t>{L'*', L'?'}
  {
  }
};

}  // namespace wildcards

#endif  // WILDCARDS_CARDS_HPP
