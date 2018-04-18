// Copyright Tomas Zeman 2018.
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef WILDCARDS_WILDCARDS_HPP
#define WILDCARDS_WILDCARDS_HPP

#include <utility>  // std::forward

#include "config.hpp"             // cfg_HAS_CONSTEXPR14
#include "cx/iterator.hpp"        // cx::begin, cx::end, cx::next
#include "wildcards/cards.hpp"    // wildcards::cards
#include "wildcards/utility.hpp"  // wildcards::container_item_t, wildcards::iterated_item_t

namespace wildcards
{

template <typename SequenceIterator, typename PatternIterator>
constexpr bool match(SequenceIterator s, SequenceIterator send, PatternIterator p,
                     PatternIterator pend, const cards<iterated_item_t<PatternIterator>>& c,
                     bool escape = false)
{
#if cfg_HAS_CONSTEXPR14

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

#else  // !cfg_HAS_CONSTEXPR14

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

#endif  // cfg_HAS_CONSTEXPR14
}

template <typename Sequence, typename Pattern>
constexpr bool match(Sequence&& sequence, Pattern&& pattern,
                     const cards<container_item_t<Pattern>>& c = cards<container_item_t<Pattern>>())
{
  return match(cx::begin(std::forward<Sequence>(sequence)),
               cx::end(std::forward<Sequence>(sequence)), cx::begin(std::forward<Pattern>(pattern)),
               cx::end(std::forward<Pattern>(pattern)), c);
}

}  // namespace wildcards

#endif  // WILDCARDS_WILDCARDS_HPP
