// Copyright Tomas Zeman 2018.
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef WILDCARDS_CARDS_HPP
#define WILDCARDS_CARDS_HPP

#include <utility>  // std::forward, std::move

namespace wildcards
{

template <typename T>
struct cards
{
  constexpr cards(T a, T s, T e)
      : anything{std::move(a)}, single{std::move(s)}, escape{std::move(e)}
  {
  }

  T anything;
  T single;
  T escape;
};

template <>
struct cards<char>
{
  constexpr cards()
  {
  }

  constexpr cards(char a, char s, char e)
      : anything{std::move(a)}, single{std::move(s)}, escape{std::move(e)}
  {
  }

  char anything{'*'};
  char single{'?'};
  char escape{'\\'};
};

template <>
struct cards<char16_t>
{
  constexpr cards()
  {
  }

  constexpr cards(char16_t a, char16_t s, char16_t e)
      : anything{std::move(a)}, single{std::move(s)}, escape{std::move(e)}
  {
  }

  char16_t anything{u'*'};
  char16_t single{u'?'};
  char16_t escape{u'\\'};
};

template <>
struct cards<char32_t>
{
  constexpr cards()
  {
  }

  constexpr cards(char32_t a, char32_t s, char32_t e)
      : anything{std::move(a)}, single{std::move(s)}, escape{std::move(e)}
  {
  }

  char32_t anything{U'*'};
  char32_t single{U'?'};
  char32_t escape{U'\\'};
};

template <>
struct cards<wchar_t>
{
  constexpr cards()
  {
  }

  constexpr cards(wchar_t a, wchar_t s, wchar_t e)
      : anything{std::move(a)}, single{std::move(s)}, escape{std::move(e)}
  {
  }

  wchar_t anything{L'*'};
  wchar_t single{L'?'};
  wchar_t escape{L'\\'};
};

template <typename T>
constexpr cards<T> make_cards(T&& c1, T&& c2)
{
  return {std::forward<T>(c1), std::forward<T>(c2)};
}

}  // namespace wildcards

#endif  // WILDCARDS_CARDS_HPP
