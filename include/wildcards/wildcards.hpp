// Copyright Tomas Zeman 2018.
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef WILDCARDS_WILDCARDS_HPP
#define WILDCARDS_WILDCARDS_HPP

#include <type_traits>  // std::remove_cv, std::remove_reference
#include <utility>      // std::declval, std::forward, std::move

#include <configuration.hpp>  // cfg_HAVE_CONSTEXPR_14
#include <cx/iterator.hpp>    // cx::begin, cx::end, cx::next

namespace wildcards
{

template <typename T>
struct cards
{
  T asterisk;
  T question_mark;
  T escape;
};

template <>
struct cards<char>
{
  char asterisk{'*'};
  char question_mark{'?'};
  char escape{'\\'};
};

template <>
struct cards<char16_t>
{
  char16_t asterisk{u'*'};
  char16_t question_mark{u'?'};
  char16_t escape{u'\\'};
};

template <>
struct cards<char32_t>
{
  char32_t asterisk{U'*'};
  char32_t question_mark{U'?'};
  char32_t escape{U'\\'};
};

template <>
struct cards<wchar_t>
{
  wchar_t asterisk{L'*'};
  wchar_t question_mark{L'?'};
  wchar_t escape{L'\\'};
};

template <typename T>
constexpr cards<T> make_cards(T&& c1, T&& c2)
{
  return cards<T>{std::forward<T>(c1), std::forward<T>(c2)};
}

namespace detail
{

template <typename It>
struct iterated_item
{
  using type = typename std::remove_cv<
      typename std::remove_reference<decltype(*std::declval<It>())>::type>::type;
};

template <typename It>
using iterated_item_t = typename iterated_item<It>::type;

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
                     PatternIterator pend, const cards<iterated_item_t<PatternIterator>>& c,
                     bool escape)
{
#if cfg_HAVE_CONSTEXPR_14

  if (p == pend)
  {
    return s == send;
  }

  if (!escape && *p == c.escape)
  {
    return match(s, send, cx::next(p), pend, c, true);
  }

  if (escape || *p != c.asterisk)
  {
    if (s == send)
    {
      return false;
    }

    if ((!escape && *p == c.question_mark) || *s == *p)
    {
      return match(cx::next(s), send, cx::next(p), pend, c, false);
    }

    return false;
  }

  return match(s, send, cx::next(p), pend, c, false) ||
         ((s != send) && match(cx::next(s), send, p, pend, c, false));

#else  // !cfg_HAVE_CONSTEXPR_14

  return p == pend ? s == send
                   : !escape && *p == c.escape
                         ? match(s, send, cx::next(p), pend, c, true)
                         :

                         escape || *p != c.asterisk
                             ? s != send && ((!escape && *p == c.question_mark) || *s == *p) &&
                                   match(cx::next(s), send, cx::next(p), pend, c, false)
                             :

                             match(s, send, cx::next(p), pend, c, false) ||
                                 ((s != send) && match(cx::next(s), send, p, pend, c, false));

#endif  // cfg_HAVE_CONSTEXPR_14
}

}  // namespace detail

template <typename Sequence, typename Pattern>
constexpr bool match(
    Sequence&& sequence, Pattern&& pattern,
    const cards<detail::container_item_t<Pattern>>& c = cards<detail::container_item_t<Pattern>>())
{
  return detail::match(
      cx::begin(std::forward<Sequence>(sequence)), cx::end(std::forward<Sequence>(sequence)),
      cx::begin(std::forward<Pattern>(pattern)), cx::end(std::forward<Pattern>(pattern)), c, false);
}

}  // namespace wildcards

#endif  // WILDCARDS_WILDCARDS_HPP
