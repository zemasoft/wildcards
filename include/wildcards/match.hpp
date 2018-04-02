// Copyright Tomas Zeman 2018.
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef WILDCARDS_MATCH_HPP
#define WILDCARDS_MATCH_HPP

#include <utility>  // std::forward

#include <wildcards/iterator.hpp>  // wildcards::begin, wildcards::end

namespace wildcards
{

namespace detail
{

template <typename SequenceIterator, typename PatternIterator>
constexpr bool match(SequenceIterator s, SequenceIterator send, PatternIterator p,
                     PatternIterator pend)
{
  if (p == pend)
  {
    return s == send;
  }

  if (*p != '*')
  {
    if (s == send)
    {
      return false;
    }

    if (*p == '?' || *s == *p)
    {
      return match(s + 1, send, p + 1, pend);
    }

    return false;
  }

  return match(s, send, p + 1, pend) || ((s != send) && match(s + 1, send, p, pend));
}

}  // namespace detail

template <typename Sequence, typename Pattern>
constexpr bool match(Sequence&& sequence, Pattern&& pattern)
{
  return detail::match(begin(std::forward<Sequence>(sequence)),
                       end(std::forward<Sequence>(sequence)), begin(std::forward<Pattern>(pattern)),
                       end(std::forward<Pattern>(pattern)));
}

}  // namespace wildcards

#endif  // WILDCARDS_MATCH_HPP
