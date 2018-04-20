// Copyright Tomas Zeman 2018.
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef WILDCARDS_MATCH_HPP
#define WILDCARDS_MATCH_HPP

#include <utility>  // std::forward

#include "config.hpp"             // cfg_HAS_CONSTEXPR14
#include "cx/functional.hpp"      // cx::equal_to
#include "cx/iterator.hpp"        // cx::begin, cx::end, cx::next
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

  if (!escape && *p == c.escape)
  {
    return match(s, send, cx::next(p), pend, c, equal_to, true);
  }

  if (escape || *p != c.asterisk)
  {
    if (s == send)
    {
      return false;
    }

    if ((!escape && *p == c.question_mark) || equal_to(*s, *p))
    {
      return match(cx::next(s), send, cx::next(p), pend, c, equal_to, false);
    }

    return false;
  }

  return match(s, send, cx::next(p), pend, c, equal_to, false) ||
         ((s != send) && match(cx::next(s), send, p, pend, c, equal_to, false));

#else  // !cfg_HAS_CONSTEXPR14

  return p == pend
             ? s == send
             : !escape && *p == c.escape
                   ? match(s, send, cx::next(p), pend, c, equal_to, true)
                   :

                   escape || *p != c.asterisk
                       ? s != send && ((!escape && *p == c.question_mark) || equal_to(*s, *p)) &&
                             match(cx::next(s), send, cx::next(p), pend, c, equal_to, false)
                       :

                       match(s, send, cx::next(p), pend, c, equal_to, false) ||
                           ((s != send) && match(cx::next(s), send, p, pend, c, equal_to, false));

#endif  // cfg_HAS_CONSTEXPR14
}

template <typename Sequence, typename Pattern, typename EqualTo = cx::equal_to<void>>
constexpr bool match(Sequence&& sequence, Pattern&& pattern,
                     const cards<container_item_t<Pattern>>& c = cards<container_item_t<Pattern>>(),
                     const EqualTo& equal_to = EqualTo())
{
  return match(cx::begin(std::forward<Sequence>(sequence)),
               cx::end(std::forward<Sequence>(sequence)), cx::begin(std::forward<Pattern>(pattern)),
               cx::end(std::forward<Pattern>(pattern)), c, equal_to);
}

template <typename Sequence, typename Pattern, typename EqualTo = cx::equal_to<void>>
constexpr bool match(Sequence&& sequence, Pattern&& pattern, const EqualTo& equal_to)
{
  return match(cx::begin(std::forward<Sequence>(sequence)),
               cx::end(std::forward<Sequence>(sequence)), cx::begin(std::forward<Pattern>(pattern)),
               cx::end(std::forward<Pattern>(pattern)), cards<container_item_t<Pattern>>(),
               equal_to);
}

}  // namespace wildcards

#endif  // WILDCARDS_MATCH_HPP
