// Copyright Tomas Zeman 2018.
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef WILDCARDS_CARDS_HPP
#define WILDCARDS_CARDS_HPP

#include <utility>  // std::move

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

  constexpr cards(char c1, char c2) : cx::pair<char, char>{std::move(c1), std::move(c2)}
  {
  }
};

template <>
struct cards<char16_t> : public cx::pair<char16_t, char16_t>
{
  constexpr cards() : cx::pair<char16_t, char16_t>{u'*', u'?'}
  {
  }

  constexpr cards(char16_t c1, char16_t c2)
      : cx::pair<char16_t, char16_t>{std::move(c1), std::move(c2)}
  {
  }
};

template <>
struct cards<char32_t> : public cx::pair<char32_t, char32_t>
{
  constexpr cards() : cx::pair<char32_t, char32_t>{U'*', U'?'}
  {
  }

  constexpr cards(char32_t c1, char32_t c2)
      : cx::pair<char32_t, char32_t>{std::move(c1), std::move(c2)}
  {
  }
};

template <>
struct cards<wchar_t> : public cx::pair<wchar_t, wchar_t>
{
  constexpr cards() : cx::pair<wchar_t, wchar_t>{L'*', L'?'}
  {
  }

  constexpr cards(wchar_t c1, wchar_t c2) : cx::pair<wchar_t, wchar_t>{std::move(c1), std::move(c2)}
  {
  }
};

}  // namespace wildcards

#endif  // WILDCARDS_CARDS_HPP
