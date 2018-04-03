// Copyright Tomas Zeman 2018.
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef WILDCARDS_MATCH_HPP
#define WILDCARDS_MATCH_HPP

#include <type_traits>  // std::remove_cv, std::remove_reference
#include <utility>      // std::declval, std::forward

#include <wildcards/cards.hpp>     // wildcards::cards
#include <wildcards/iterator.hpp>  // wildcards::begin, wildcards::end

namespace wildcards
{

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

  if (*p != get<0>(c))
  {
    if (s == send)
    {
      return false;
    }

    if (*p == get<1>(c) || *s == *p)
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
  return detail::match(begin(std::forward<Sequence>(sequence)),
                       end(std::forward<Sequence>(sequence)), begin(std::forward<Pattern>(pattern)),
                       end(std::forward<Pattern>(pattern)), c);
}

}  // namespace wildcards

#endif  // WILDCARDS_MATCH_HPP
