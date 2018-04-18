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
  constexpr cards(T a, T q, T e)
      : asterisk{std::move(a)}, question_mark{std::move(q)}, escape{std::move(e)}
  {
  }

  T asterisk;
  T question_mark;
  T escape;
};

template <>
struct cards<char>
{
  constexpr cards()
  {
  }

  constexpr cards(char a, char q, char e)
      : asterisk{std::move(a)}, question_mark{std::move(q)}, escape{std::move(e)}
  {
  }

  char asterisk{'*'};
  char question_mark{'?'};
  char escape{'\\'};
};

template <>
struct cards<char16_t>
{
  constexpr cards()
  {
  }

  constexpr cards(char16_t a, char16_t q, char16_t e)
      : asterisk{std::move(a)}, question_mark{std::move(q)}, escape{std::move(e)}
  {
  }

  char16_t asterisk{u'*'};
  char16_t question_mark{u'?'};
  char16_t escape{u'\\'};
};

template <>
struct cards<char32_t>
{
  constexpr cards()
  {
  }

  constexpr cards(char32_t a, char32_t q, char32_t e)
      : asterisk{std::move(a)}, question_mark{std::move(q)}, escape{std::move(e)}
  {
  }

  char32_t asterisk{U'*'};
  char32_t question_mark{U'?'};
  char32_t escape{U'\\'};
};

template <>
struct cards<wchar_t>
{
  constexpr cards()
  {
  }

  constexpr cards(wchar_t a, wchar_t q, wchar_t e)
      : asterisk{std::move(a)}, question_mark{std::move(q)}, escape{std::move(e)}
  {
  }

  wchar_t asterisk{L'*'};
  wchar_t question_mark{L'?'};
  wchar_t escape{L'\\'};
};

template <typename T>
constexpr cards<T> make_cards(T&& c1, T&& c2)
{
  return {std::forward<T>(c1), std::forward<T>(c2)};
}

}  // namespace wildcards

#endif  // WILDCARDS_CARDS_HPP
