// Copyright Tomas Zeman 2018.
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef WILDCARDS_MATCH_HPP
#define WILDCARDS_MATCH_HPP

#include <stdexcept>  // std::logic_error
#include <utility>    // std::forward

#include "config.hpp"             // cfg_HAS_CONSTEXPR14
#include "cx/functional.hpp"      // cx::equal_to
#include "cx/iterator.hpp"        // cx::cbegin, cx::cend, cx::next
#include "wildcards/cards.hpp"    // wildcards::cards
#include "wildcards/utility.hpp"  // wildcards::container_item_t, wildcards::iterated_item_t

namespace wildcards
{

namespace detail
{

constexpr bool throw_logic_error(const char* what_arg)
{
  return what_arg == nullptr ? false : throw std::logic_error(what_arg);
}

enum class is_enum_state
{
  open,
  exclusion_or_first_item,
  first_item,
  next_item
};

template <typename PatternIterator>
constexpr bool is_enum(
    PatternIterator p, PatternIterator pend,
    const cards<iterated_item_t<PatternIterator>>& c = cards<iterated_item_t<PatternIterator>>(),
    is_enum_state state = is_enum_state::open)
{
#if cfg_HAS_CONSTEXPR14

  if (p == pend)
  {
    return false;
  }

  switch (state)
  {
    case is_enum_state::open:
      if (*p == c.enum_open)
      {
        return is_enum(cx::next(p), pend, c, is_enum_state::exclusion_or_first_item);
      }

      return false;

    case is_enum_state::exclusion_or_first_item:
      if (*p == c.enum_exclusion)
      {
        return is_enum(cx::next(p), pend, c, is_enum_state::first_item);
      }

      return is_enum(cx::next(p), pend, c, is_enum_state::next_item);

    case is_enum_state::first_item:
      return is_enum(cx::next(p), pend, c, is_enum_state::next_item);

    case is_enum_state::next_item:
      if (*p == c.enum_close)
      {
        return true;
      }

      return is_enum(cx::next(p), pend, c, is_enum_state::next_item);

    default:
      return throw_logic_error("Logic error");
  }

#else  // !cfg_HAS_CONSTEXPR14

  return p != pend && (state == is_enum_state::open
                           ? *p == c.enum_open && is_enum(cx::next(p), pend, c,
                                                          is_enum_state::exclusion_or_first_item)
                           :

                           state == is_enum_state::exclusion_or_first_item
                               ? *p == c.enum_exclusion
                                     ? is_enum(cx::next(p), pend, c, is_enum_state::first_item)
                                     : is_enum(cx::next(p), pend, c, is_enum_state::next_item)
                               : state == is_enum_state::first_item
                                     ? is_enum(cx::next(p), pend, c, is_enum_state::next_item)
                                     : state == is_enum_state::next_item
                                           ? *p == c.enum_close || is_enum(cx::next(p), pend, c,
                                                                           is_enum_state::next_item)
                                           : throw std::logic_error("Logic error"));

#endif  // cfg_HAS_CONSTEXPR14
}

}  // namespace detail

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

  if (*p == c.anything)
  {
    return match(s, send, cx::next(p), pend, c, equal_to) ||
           ((s != send) && match(cx::next(s), send, p, pend, c, equal_to));
  }

  if (s != send && (*p == c.single || equal_to(*s, *p)))
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
                         : *p == c.anything
                               ? match(s, send, cx::next(p), pend, c, equal_to) ||
                                     ((s != send) && match(cx::next(s), send, p, pend, c, equal_to))
                               : s != send && (*p == c.single || equal_to(*s, *p)) &&
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
