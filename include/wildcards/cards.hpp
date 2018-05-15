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
      : anything{std::move(a)}, single{std::move(s)}, escape{std::move(e)}, set_enabled{false}
  {
  }

  constexpr cards(T a, T s, T e, T so, T sc, T sn)
      : anything{std::move(a)},
        single{std::move(s)},
        escape{std::move(e)},
        set_enabled{true},
        set_open{std::move(so)},
        set_close{std::move(sc)},
        set_not{std::move(sn)}
  {
  }

  T anything;
  T single;
  T escape;

  bool set_enabled;
  T set_open;
  T set_close;
  T set_not;
};

enum class cards_type
{
  standard,
  extended
};

template <>
struct cards<char>
{
  constexpr cards(cards_type type = cards_type::extended)
      : set_enabled{type == cards_type::extended}
  {
  }

  constexpr cards(char a, char s, char e)
      : anything{std::move(a)}, single{std::move(s)}, escape{std::move(e)}, set_enabled{false}
  {
  }

  constexpr cards(char a, char s, char e, char so, char sc, char sn)
      : anything{std::move(a)},
        single{std::move(s)},
        escape{std::move(e)},
        set_enabled{true},
        set_open{std::move(so)},
        set_close{std::move(sc)},
        set_not{std::move(sn)}
  {
  }

  char anything{'*'};
  char single{'?'};
  char escape{'\\'};

  bool set_enabled{true};
  char set_open{'['};
  char set_close{']'};
  char set_not{'!'};
};

template <>
struct cards<char16_t>
{
  constexpr cards(cards_type type = cards_type::extended)
      : set_enabled{type == cards_type::extended}
  {
  }

  constexpr cards(char16_t a, char16_t s, char16_t e)
      : anything{std::move(a)}, single{std::move(s)}, escape{std::move(e)}, set_enabled{false}
  {
  }

  constexpr cards(char16_t a, char16_t s, char16_t e, char16_t so, char16_t sc, char16_t sn)
      : anything{std::move(a)},
        single{std::move(s)},
        escape{std::move(e)},
        set_enabled{true},
        set_open{std::move(so)},
        set_close{std::move(sc)},
        set_not{std::move(sn)}
  {
  }

  char16_t anything{u'*'};
  char16_t single{u'?'};
  char16_t escape{u'\\'};

  bool set_enabled{true};
  char16_t set_open{u'['};
  char16_t set_close{u']'};
  char16_t set_not{u'!'};
};

template <>
struct cards<char32_t>
{
  constexpr cards(cards_type type = cards_type::extended)
      : set_enabled{type == cards_type::extended}
  {
  }

  constexpr cards(char32_t a, char32_t s, char32_t e)
      : anything{std::move(a)}, single{std::move(s)}, escape{std::move(e)}, set_enabled{false}
  {
  }

  constexpr cards(char32_t a, char32_t s, char32_t e, char32_t so, char32_t sc, char32_t sn)
      : anything{std::move(a)},
        single{std::move(s)},
        escape{std::move(e)},
        set_enabled{true},
        set_open{std::move(so)},
        set_close{std::move(sc)},
        set_not{std::move(sn)}
  {
  }

  char32_t anything{U'*'};
  char32_t single{U'?'};
  char32_t escape{U'\\'};

  bool set_enabled{true};
  char32_t set_open{U'['};
  char32_t set_close{U']'};
  char32_t set_not{U'!'};
};

template <>
struct cards<wchar_t>
{
  constexpr cards(cards_type type = cards_type::extended)
      : set_enabled{type == cards_type::extended}
  {
  }

  constexpr cards(wchar_t a, wchar_t s, wchar_t e)
      : anything{std::move(a)}, single{std::move(s)}, escape{std::move(e)}, set_enabled{false}
  {
  }

  constexpr cards(wchar_t a, wchar_t s, wchar_t e, wchar_t so, wchar_t sc, wchar_t sn)
      : anything{std::move(a)},
        single{std::move(s)},
        escape{std::move(e)},
        set_enabled{true},
        set_open{std::move(so)},
        set_close{std::move(sc)},
        set_not{std::move(sn)}
  {
  }

  wchar_t anything{L'*'};
  wchar_t single{L'?'};
  wchar_t escape{L'\\'};

  bool set_enabled{true};
  wchar_t set_open{L'['};
  wchar_t set_close{L']'};
  wchar_t set_not{L'!'};
};

template <typename T>
constexpr cards<T> make_cards(T&& a, T&& s, T&& e)
{
  return {std::forward<T>(a), std::forward<T>(s), std::forward<T>(e)};
}

template <typename T>
constexpr cards<T> make_cards(T&& a, T&& s, T&& e, T&& so, T&& sc, T&& sn)
{
  return {std::forward<T>(a),  std::forward<T>(s),  std::forward<T>(e),
          std::forward<T>(so), std::forward<T>(sc), std::forward<T>(sn)};
}

}  // namespace wildcards

#endif  // WILDCARDS_CARDS_HPP
