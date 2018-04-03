// Copyright Tomas Zeman 2018.
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef WILDCARDS_WILDCARDS_HPP
#define WILDCARDS_WILDCARDS_HPP

#include <type_traits>  // std::remove_cv, std::remove_reference
#include <utility>      // std::declval, std::forward, std::move

#include <cx/iterator.hpp>  // cx::begin, cx::end
#include <cx/utility.hpp>   // cx::get, cx::pair

namespace wildcards
{

template <typename T>
struct cards : public cx::pair<T, T>
{
  using cx::pair<T, T>::pair;
};

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

template <typename T>
constexpr cards<T> make_cards(T&& c1, T&& c2)
{
  return cards<T>{std::forward<T>(c1), std::forward<T>(c2)};
}

namespace detail
{

template <typename I>
struct iterated_item
{
  using type = typename std::remove_cv<
      typename std::remove_reference<decltype(*std::declval<I>())>::type>::type;
};

template <typename I>
using iterated_item_t = typename iterated_item<I>::type;

template <typename C>
struct container_item
{
  using type = typename std::remove_cv<
      typename std::remove_reference<decltype(*begin(std::declval<C>()))>::type>::type;
};

template <typename C>
using container_item_t = typename container_item<C>::type;

template <typename SequenceIterator, typename PatternIterator>
constexpr bool match(SequenceIterator s, SequenceIterator send, PatternIterator p,
                     PatternIterator pend, const cards<iterated_item_t<PatternIterator>>& c)
{
  if (p == pend)
  {
    return s == send;
  }

  if (*p != cx::get<0>(c))
  {
    if (s == send)
    {
      return false;
    }

    if (*p == cx::get<1>(c) || *s == *p)
    {
      return match(s + 1, send, p + 1, pend, c);
    }

    return false;
  }

  return match(s, send, p + 1, pend, c) || ((s != send) && match(s + 1, send, p, pend, c));
}

}  // namespace detail

template <typename Sequence, typename Pattern>
constexpr bool match(
    Sequence&& sequence, Pattern&& pattern,
    const cards<detail::container_item_t<Pattern>>& c = cards<detail::container_item_t<Pattern>>())
{
  return detail::match(
      cx::begin(std::forward<Sequence>(sequence)), cx::end(std::forward<Sequence>(sequence)),
      cx::begin(std::forward<Pattern>(pattern)), cx::end(std::forward<Pattern>(pattern)), c);
}

}  // namespace wildcards

#endif  // WILDCARDS_WILDCARDS_HPP
