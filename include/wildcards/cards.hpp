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
      : anything{std::move(a)}, single{std::move(s)}, escape{std::move(e)}, enum_enabled{false}
  {
  }

  constexpr cards(T a, T s, T e, T eo, T ec, T ee)
      : anything{std::move(a)},
        single{std::move(s)},
        escape{std::move(e)},
        enum_enabled{true},
        enum_open{std::move(eo)},
        enum_close{std::move(ec)},
        enum_exclusion{std::move(ee)}
  {
  }

  T anything;
  T single;
  T escape;

  bool enum_enabled;
  T enum_open;
  T enum_close;
  T enum_exclusion;
};

template <>
struct cards<char>
{
  constexpr cards()
  {
  }

  constexpr cards(char a, char s, char e)
      : anything{std::move(a)}, single{std::move(s)}, escape{std::move(e)}, enum_enabled{false}
  {
  }

  constexpr cards(char a, char s, char e, char eo, char ec, char ee)
      : anything{std::move(a)},
        single{std::move(s)},
        escape{std::move(e)},
        enum_enabled{true},
        enum_open{std::move(eo)},
        enum_close{std::move(ec)},
        enum_exclusion{std::move(ee)}
  {
  }

  char anything{'*'};
  char single{'?'};
  char escape{'\\'};

  bool enum_enabled{true};
  char enum_open{'['};
  char enum_close{']'};
  char enum_exclusion{'!'};
};

template <>
struct cards<char16_t>
{
  constexpr cards()
  {
  }

  constexpr cards(char16_t a, char16_t s, char16_t e)
      : anything{std::move(a)}, single{std::move(s)}, escape{std::move(e)}, enum_enabled{false}
  {
  }

  constexpr cards(char16_t a, char16_t s, char16_t e, char16_t eo, char16_t ec, char16_t ee)
      : anything{std::move(a)},
        single{std::move(s)},
        escape{std::move(e)},
        enum_enabled{true},
        enum_open{std::move(eo)},
        enum_close{std::move(ec)},
        enum_exclusion{std::move(ee)}
  {
  }

  char16_t anything{u'*'};
  char16_t single{u'?'};
  char16_t escape{u'\\'};

  bool enum_enabled{true};
  char16_t enum_open{u'['};
  char16_t enum_close{u']'};
  char16_t enum_exclusion{u'!'};
};

template <>
struct cards<char32_t>
{
  constexpr cards()
  {
  }

  constexpr cards(char32_t a, char32_t s, char32_t e)
      : anything{std::move(a)}, single{std::move(s)}, escape{std::move(e)}, enum_enabled{false}
  {
  }

  constexpr cards(char32_t a, char32_t s, char32_t e, char32_t eo, char32_t ec, char32_t ee)
      : anything{std::move(a)},
        single{std::move(s)},
        escape{std::move(e)},
        enum_enabled{true},
        enum_open{std::move(eo)},
        enum_close{std::move(ec)},
        enum_exclusion{std::move(ee)}
  {
  }

  char32_t anything{U'*'};
  char32_t single{U'?'};
  char32_t escape{U'\\'};

  bool enum_enabled{true};
  char32_t enum_open{U'['};
  char32_t enum_close{U']'};
  char32_t enum_exclusion{U'!'};
};

template <>
struct cards<wchar_t>
{
  constexpr cards()
  {
  }

  constexpr cards(wchar_t a, wchar_t s, wchar_t e)
      : anything{std::move(a)}, single{std::move(s)}, escape{std::move(e)}, enum_enabled{false}
  {
  }

  constexpr cards(wchar_t a, wchar_t s, wchar_t e, wchar_t eo, wchar_t ec, wchar_t ee)
      : anything{std::move(a)},
        single{std::move(s)},
        escape{std::move(e)},
        enum_enabled{true},
        enum_open{std::move(eo)},
        enum_close{std::move(ec)},
        enum_exclusion{std::move(ee)}
  {
  }

  wchar_t anything{L'*'};
  wchar_t single{L'?'};
  wchar_t escape{L'\\'};

  bool enum_enabled{true};
  wchar_t enum_open{L'['};
  wchar_t enum_close{L']'};
  wchar_t enum_exclusion{L'!'};
};

template <typename T>
constexpr cards<T> make_cards(T&& c1, T&& c2)
{
  return {std::forward<T>(c1), std::forward<T>(c2)};
}

}  // namespace wildcards

#endif  // WILDCARDS_CARDS_HPP
