// Copyright Tomas Zeman 2018.
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef WILDCARDS_MATCH_HPP
#define WILDCARDS_MATCH_HPP

#include <stdexcept>    // std::invalid_argument, std::logic_error
#include <type_traits>  // std::enable_if, std::is_same
#include <utility>      // std::forward

#include "config.hpp"             // cfg_HAS_CONSTEXPR14
#include "cx/functional.hpp"      // cx::equal_to
#include "cx/iterator.hpp"        // cx::cbegin, cx::cend, cx::next
#include "wildcards/cards.hpp"    // wildcards::cards
#include "wildcards/utility.hpp"  // wildcards::container_item_t, wildcards::iterated_item_t

namespace wildcards
{

namespace detail
{

#if !cfg_HAS_FULL_FEATURED_CONSTEXPR_SWITCH

constexpr bool throw_logic_error(const char* what_arg)
{
  return what_arg == nullptr ? false : throw std::logic_error(what_arg);
}

#endif

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

  if (!c.enum_enabled || p == pend)
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
#if cfg_HAS_FULL_FEATURED_CONSTEXPR_SWITCH
      throw std::logic_error(
          "The program execution should never end up here trowing this exception");
#else
      return throw_logic_error(
          "The program execution should never end up here trowing this exception");
#endif
  }

#else  // !cfg_HAS_CONSTEXPR14

  return c.enum_enabled && p != pend &&
         (state == is_enum_state::open
              ? *p == c.enum_open &&
                    is_enum(cx::next(p), pend, c, is_enum_state::exclusion_or_first_item)
              :

              state == is_enum_state::exclusion_or_first_item
                  ? *p == c.enum_exclusion
                        ? is_enum(cx::next(p), pend, c, is_enum_state::first_item)
                        : is_enum(cx::next(p), pend, c, is_enum_state::next_item)
                  : state == is_enum_state::first_item
                        ? is_enum(cx::next(p), pend, c, is_enum_state::next_item)
                        : state == is_enum_state::next_item
                              ? *p == c.enum_close ||
                                    is_enum(cx::next(p), pend, c, is_enum_state::next_item)
                              : throw std::logic_error("The program execution should never end up "
                                                       "here trowing this exception"));

#endif  // cfg_HAS_CONSTEXPR14
}

#if !cfg_HAS_FULL_FEATURED_CONSTEXPR_SWITCH

constexpr bool throw_invalid_argument(const char* what_arg)
{
  return what_arg == nullptr ? false : throw std::invalid_argument(what_arg);
}

#endif

enum class match_enum_state
{
  open,
  exclusion_or_first_in_item,
  first_out_item,
  skip_next_in_item,
  next_in_item,
  next_out_item
};

template <typename SequenceIterator, typename PatternIterator,
          typename EqualTo = cx::equal_to<void>>
constexpr bool match_enum(
    SequenceIterator s, SequenceIterator send, PatternIterator p, PatternIterator pend,
    const cards<iterated_item_t<PatternIterator>>& c = cards<iterated_item_t<PatternIterator>>(),
    const EqualTo& equal_to = EqualTo(), match_enum_state state = match_enum_state::open)
{
#if cfg_HAS_CONSTEXPR14

  if (!c.enum_enabled)
  {
#if cfg_HAS_FULL_FEATURED_CONSTEXPR_SWITCH
    throw std::invalid_argument("The use of enums is disabled");
#else
    return throw_invalid_argument("The use of enums is disabled");
#endif
  }

  if (p == pend)
  {
#if cfg_HAS_FULL_FEATURED_CONSTEXPR_SWITCH
    throw std::invalid_argument("The given pattern is not a valid enum");
#else
    return throw_invalid_argument("The given pattern is not a valid enum");
#endif
  }

  switch (state)
  {
    case match_enum_state::open:
      if (*p == c.enum_open)
      {
        return match_enum(s, send, cx::next(p), pend, c, equal_to,
                          match_enum_state::exclusion_or_first_in_item);
      }

#if cfg_HAS_FULL_FEATURED_CONSTEXPR_SWITCH
      throw std::invalid_argument("The given pattern is not a valid enum");
#else
      return throw_invalid_argument("The given pattern is not a valid enum");
#endif

    case match_enum_state::exclusion_or_first_in_item:
      if (*p == c.enum_exclusion)
      {
        return match_enum(s, send, cx::next(p), pend, c, equal_to,
                          match_enum_state::first_out_item);
      }

      if (s == send)
      {
        return false;
      }

      if (equal_to(*s, *p))
      {
        return match_enum(s, send, cx::next(p), pend, c, equal_to,
                          match_enum_state::skip_next_in_item);
      }

      return match_enum(s, send, cx::next(p), pend, c, equal_to, match_enum_state::next_in_item);

    case match_enum_state::first_out_item:
      if (s == send || equal_to(*s, *p))
      {
        return false;
      }

      return match_enum(s, send, cx::next(p), pend, c, equal_to, match_enum_state::next_out_item);

    case match_enum_state::skip_next_in_item:
      if (*p == c.enum_close)
      {
        if (s == send)
        {
          return true;
        }

        return match(cx::next(s), send, cx::next(p), pend, c, equal_to);
      }

      return match_enum(s, send, cx::next(p), pend, c, equal_to, state);

    case match_enum_state::next_in_item:
      if (*p == c.enum_close || s == send)
      {
        return false;
      }

      if (equal_to(*s, *p))
      {
        return match_enum(s, send, cx::next(p), pend, c, equal_to,
                          match_enum_state::skip_next_in_item);
      }

      return match_enum(s, send, cx::next(p), pend, c, equal_to, state);

    case match_enum_state::next_out_item:
      if (*p == c.enum_close)
      {
        if (s == send)
        {
          return true;
        }

        return match(cx::next(s), send, cx::next(p), pend, c, equal_to);
      }

      if (s == send || equal_to(*s, *p))
      {
        return false;
      }

      return match_enum(s, send, cx::next(p), pend, c, equal_to, state);

    default:
#if cfg_HAS_FULL_FEATURED_CONSTEXPR_SWITCH
      throw std::logic_error(
          "The program execution should never end up here trowing this exception");
#else
      return throw_logic_error(
          "The program execution should never end up here trowing this exception");
#endif
  }

#else  // !cfg_HAS_CONSTEXPR14

  return !c.enum_enabled
             ? throw std::invalid_argument("The use of enums is disabled")
             : p == pend
                   ? throw std::invalid_argument("The given pattern is not a valid enum")
                   : state == match_enum_state::open
                         ? *p == c.enum_open
                               ? match_enum(s, send, cx::next(p), pend, c, equal_to,
                                            match_enum_state::exclusion_or_first_in_item)
                               :

                               throw std::invalid_argument("The given pattern is not a valid enum")
                         :

                         state == match_enum_state::exclusion_or_first_in_item
                             ? *p == c.enum_exclusion
                                   ? match_enum(s, send, cx::next(p), pend, c, equal_to,
                                                match_enum_state::first_out_item)
                                   :

                                   s != send &&
                                       (equal_to(*s, *p)
                                            ? match_enum(s, send, cx::next(p), pend, c, equal_to,
                                                         match_enum_state::skip_next_in_item)
                                            :

                                            match_enum(s, send, cx::next(p), pend, c, equal_to,
                                                       match_enum_state::next_in_item))

                             :

                             state == match_enum_state::first_out_item
                                 ? s != send && !equal_to(*s, *p) &&
                                       match_enum(s, send, cx::next(p), pend, c, equal_to,
                                                  match_enum_state::next_out_item)

                                 :

                                 state == match_enum_state::skip_next_in_item
                                     ? *p == c.enum_close
                                           ?

                                           s == send || match(cx::next(s), send, cx::next(p), pend,
                                                              c, equal_to)
                                           :

                                           match_enum(s, send, cx::next(p), pend, c, equal_to,
                                                      state)

                                     :

                                     state == match_enum_state::next_in_item
                                         ? *p != c.enum_close && s != send &&
                                               (equal_to(*s, *p)
                                                    ?

                                                    match_enum(s, send, cx::next(p), pend, c,
                                                               equal_to,
                                                               match_enum_state::skip_next_in_item)
                                                    :

                                                    match_enum(s, send, cx::next(p), pend, c,
                                                               equal_to, state))

                                         :

                                         state == match_enum_state::next_out_item
                                             ? *p == c.enum_close
                                                   ?

                                                   s == send ||
                                                       match(cx::next(s), send, cx::next(p), pend,
                                                             c, equal_to)
                                                   :

                                                   s != send && !equal_to(*s, *p) &&
                                                       match_enum(s, send, cx::next(p), pend, c,
                                                                  equal_to, state)

                                             : throw std::logic_error(
                                                   "The program execution should never end up here "
                                                   "trowing this exception");

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

  if (*p == c.anything)
  {
    return match(s, send, cx::next(p), pend, c, equal_to) ||
           (s != send && match(cx::next(s), send, p, pend, c, equal_to));
  }

  if (*p == c.single)
  {
    return s != send && match(cx::next(s), send, cx::next(p), pend, c, equal_to);
  }

  if (*p == c.escape)
  {
    return match(s, send, cx::next(p), pend, c, equal_to, true);
  }

  if (c.enum_enabled && *p == c.enum_open &&
      detail::is_enum(cx::next(p), pend, c, detail::is_enum_state::exclusion_or_first_item))
  {
    return match_enum(s, send, cx::next(p), pend, c, equal_to,
                      detail::match_enum_state::exclusion_or_first_in_item);
  }

  if (s != send && equal_to(*s, *p))
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
                   : *p == c.anything
                         ? match(s, send, cx::next(p), pend, c, equal_to) ||
                               (s != send && match(cx::next(s), send, p, pend, c, equal_to))
                         : *p == c.single
                               ? s != send &&
                                     match(cx::next(s), send, cx::next(p), pend, c, equal_to)
                               : *p == c.escape
                                     ? match(s, send, cx::next(p), pend, c, equal_to, true)
                                     : c.enum_enabled && *p == c.enum_open &&
                                               detail::is_enum(
                                                   cx::next(p), pend, c,
                                                   detail::is_enum_state::exclusion_or_first_item)
                                           ? match_enum(s, send, cx::next(p), pend, c, equal_to,
                                                        detail::match_enum_state::
                                                            exclusion_or_first_in_item)
                                           : s != send && equal_to(*s, *p) &&
                                                 match(cx::next(s), send, cx::next(p), pend, c,
                                                       equal_to);

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

template <typename Sequence, typename Pattern, typename EqualTo = cx::equal_to<void>,
          typename = typename std::enable_if<!std::is_same<EqualTo, cards_type>::value>::type>
constexpr bool match(Sequence&& sequence, Pattern&& pattern, const EqualTo& equal_to)
{
  return match(std::forward<Sequence>(sequence), std::forward<Pattern>(pattern),
               cards<container_item_t<Pattern>>(), equal_to);
}

}  // namespace wildcards

#endif  // WILDCARDS_MATCH_HPP
