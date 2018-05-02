// Copyright Tomas Zeman 2018.
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef WILDCARDS_MATCH_HPP
#define WILDCARDS_MATCH_HPP

#include <utility>  // std::forward

#include "config.hpp"             // cfg_HAS_CONSTEXPR14
#include "cx/functional.hpp"      // cx::equal_to
#include "cx/iterator.hpp"        // cx::cbegin, cx::cend, cx::next
#include "wildcards/cards.hpp"    // wildcards::cards
#include "wildcards/utility.hpp"  // wildcards::container_item_t, wildcards::iterated_item_t

namespace wildcards
{

template <typename SequenceIterator, typename PatternIterator,
          typename EqualTo = cx::equal_to<void>>
constexpr bool match(
    SequenceIterator s, SequenceIterator send, PatternIterator p, PatternIterator pend,
    const cards<iterated_item_t<PatternIterator>>& c = cards<iterated_item_t<PatternIterator>>(),
    const EqualTo& equal_to = EqualTo(), bool escape = false)
{
#if cfg_HAS_CONSTEXPR14

  if (p == pend)
  {
    return s == send;
  }

  if (escape)
  {
    if (s != send && equal_to(*s, *p))
    {
      return match(cx::next(s), send, cx::next(p), pend, c, equal_to);
    }

    return false;
  }

  if (*p == c.escape)
  {
    return match(s, send, cx::next(p), pend, c, equal_to, true);
  }

  if (*p == c.asterisk)
  {
    return match(s, send, cx::next(p), pend, c, equal_to) ||
           ((s != send) && match(cx::next(s), send, p, pend, c, equal_to));
  }

  if (s != send && (*p == c.question_mark || equal_to(*s, *p)))
  {
    return match(cx::next(s), send, cx::next(p), pend, c, equal_to);
  }

  return false;

#else  // !cfg_HAS_CONSTEXPR14

  return p == pend
             ? s == send
             : escape
                   ? s != send && equal_to(*s, *p) &&
                         match(cx::next(s), send, cx::next(p), pend, c, equal_to)
                   : *p == c.escape
                         ? match(s, send, cx::next(p), pend, c, equal_to, true)
                         : *p == c.asterisk
                               ? match(s, send, cx::next(p), pend, c, equal_to) ||
                                     ((s != send) && match(cx::next(s), send, p, pend, c, equal_to))
                               : s != send && (*p == c.question_mark || equal_to(*s, *p)) &&
                                     match(cx::next(s), send, cx::next(p), pend, c, equal_to);

#endif  // cfg_HAS_CONSTEXPR14
}

template <typename Sequence, typename Pattern, typename EqualTo = cx::equal_to<void>>
constexpr bool match(Sequence&& sequence, Pattern&& pattern,
                     const cards<container_item_t<Pattern>>& c = cards<container_item_t<Pattern>>(),
                     const EqualTo& equal_to = EqualTo())
{
  return match(cx::cbegin(sequence), cx::cend(std::forward<Sequence>(sequence)),
               cx::cbegin(pattern), cx::cend(std::forward<Pattern>(pattern)), c, equal_to);
}

template <typename Sequence, typename Pattern, typename EqualTo = cx::equal_to<void>>
constexpr bool match(Sequence&& sequence, Pattern&& pattern, const EqualTo& equal_to)
{
  return match(std::forward<Sequence>(sequence), std::forward<Pattern>(pattern),
               cards<container_item_t<Pattern>>(), equal_to);
}

}  // namespace wildcards

#endif  // WILDCARDS_MATCH_HPP
