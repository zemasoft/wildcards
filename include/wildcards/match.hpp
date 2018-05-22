// Copyright Tomas Zeman 2018.
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef WILDCARDS_MATCH_HPP
#define WILDCARDS_MATCH_HPP

#include <stdexcept>    // std::invalid_argument, std::logic_error, std::runtime_error
#include <type_traits>  // std::enable_if, std::is_same
#include <utility>      // std::forward

#include "config.hpp"             // cfg_HAS_CONSTEXPR14, cfg_HAS_FULL_FEATURED_CONSTEXPR_SWITCH
#include "cx/functional.hpp"      // cx::equal_to
#include "cx/iterator.hpp"        // cx::cbegin, cx::cend, cx::next
#include "wildcards/cards.hpp"    // wildcards::cards
#include "wildcards/utility.hpp"  // wildcards::container_item_t, wildcards::iterated_item_t

namespace wildcards
{

namespace detail
{

#if !cfg_HAS_FULL_FEATURED_CONSTEXPR_SWITCH

constexpr bool throw_invalid_argument(const char* what_arg)
{
  return what_arg == nullptr ? false : throw std::invalid_argument(what_arg);
}

template <typename T>
constexpr T throw_invalid_argument(T t, const char* what_arg)
{
  return what_arg == nullptr ? t : throw std::invalid_argument(what_arg);
}

constexpr bool throw_logic_error(const char* what_arg)
{
  return what_arg == nullptr ? false : throw std::logic_error(what_arg);
}

template <typename T>
constexpr T throw_logic_error(T t, const char* what_arg)
{
  return what_arg == nullptr ? t : throw std::logic_error(what_arg);
}

constexpr bool throw_runtime_error(const char* what_arg)
{
  return what_arg == nullptr ? false : throw std::runtime_error(what_arg);
}

#endif

enum class is_set_state
{
  open,
  not_or_first,
  first,
  next
};

template <typename PatternIterator>
constexpr bool is_set(
    PatternIterator p, PatternIterator pend,
    const cards<iterated_item_t<PatternIterator>>& c = cards<iterated_item_t<PatternIterator>>(),
    is_set_state state = is_set_state::open)
{
#if cfg_HAS_CONSTEXPR14

  if (!c.set_enabled || p == pend)
  {
    return false;
  }

  switch (state)
  {
    case is_set_state::open:
      if (*p == c.set_open)
      {
        return is_set(cx::next(p), pend, c, is_set_state::not_or_first);
      }

      return false;

    case is_set_state::not_or_first:
      if (*p == c.set_not)
      {
        return is_set(cx::next(p), pend, c, is_set_state::first);
      }

      return is_set(cx::next(p), pend, c, is_set_state::next);

    case is_set_state::first:
      return is_set(cx::next(p), pend, c, is_set_state::next);

    case is_set_state::next:
      if (*p == c.set_close)
      {
        return true;
      }

      return is_set(cx::next(p), pend, c, is_set_state::next);

    default:
#if cfg_HAS_FULL_FEATURED_CONSTEXPR_SWITCH
      throw std::logic_error(
          "The program execution should never end up here throwing this exception");
#else
      return throw_logic_error(
          "The program execution should never end up here throwing this exception");
#endif
  }

#else  // !cfg_HAS_CONSTEXPR14

  return c.set_enabled && p != pend &&
         (state == is_set_state::open
              ? *p == c.set_open && is_set(cx::next(p), pend, c, is_set_state::not_or_first)
              :

              state == is_set_state::not_or_first
                  ? *p == c.set_not ? is_set(cx::next(p), pend, c, is_set_state::first)
                                    : is_set(cx::next(p), pend, c, is_set_state::next)
                  : state == is_set_state::first
                        ? is_set(cx::next(p), pend, c, is_set_state::next)
                        : state == is_set_state::next
                              ? *p == c.set_close ||
                                    is_set(cx::next(p), pend, c, is_set_state::next)
                              : throw std::logic_error("The program execution should never end up "
                                                       "here throwing this exception"));

#endif  // cfg_HAS_CONSTEXPR14
}

enum class set_end_state
{
  open,
  not_or_first,
  first,
  next
};

template <typename PatternIterator>
constexpr PatternIterator set_end(
    PatternIterator p, PatternIterator pend,
    const cards<iterated_item_t<PatternIterator>>& c = cards<iterated_item_t<PatternIterator>>(),
    set_end_state state = set_end_state::open)
{
#if cfg_HAS_CONSTEXPR14

  if (!c.set_enabled)
  {
#if cfg_HAS_FULL_FEATURED_CONSTEXPR_SWITCH
    throw std::invalid_argument("The use of sets is disabled");
#else
    return throw_invalid_argument(p, "The use of sets is disabled");
#endif
  }

  if (p == pend)
  {
#if cfg_HAS_FULL_FEATURED_CONSTEXPR_SWITCH
    throw std::invalid_argument("The given pattern is not a valid set");
#else
    return throw_invalid_argument(p, "The given pattern is not a valid set");
#endif
  }

  switch (state)
  {
    case set_end_state::open:
      if (*p == c.set_open)
      {
        return set_end(cx::next(p), pend, c, set_end_state::not_or_first);
      }

#if cfg_HAS_FULL_FEATURED_CONSTEXPR_SWITCH
      throw std::invalid_argument("The given pattern is not a valid set");
#else
      return throw_invalid_argument(p, "The given pattern is not a valid set");
#endif

    case set_end_state::not_or_first:
      if (*p == c.set_not)
      {
        return set_end(cx::next(p), pend, c, set_end_state::first);
      }

      return set_end(cx::next(p), pend, c, set_end_state::next);

    case set_end_state::first:
      return set_end(cx::next(p), pend, c, set_end_state::next);

    case set_end_state::next:
      if (*p == c.set_close)
      {
        return cx::next(p);
      }

      return set_end(cx::next(p), pend, c, set_end_state::next);

    default:
#if cfg_HAS_FULL_FEATURED_CONSTEXPR_SWITCH
      throw std::logic_error(
          "The program execution should never end up here throwing this exception");
#else
      return throw_logic_error(
          p, "The program execution should never end up here throwing this exception");
#endif
  }

#else  // !cfg_HAS_CONSTEXPR14

  return !c.set_enabled
             ? throw std::invalid_argument("The use of sets is disabled")
             : p == pend
                   ? throw std::invalid_argument("The given pattern is not a valid set")
                   :

                   state == set_end_state::open
                       ? *p == c.set_open
                             ? set_end(cx::next(p), pend, c, set_end_state::not_or_first)
                             : throw std::invalid_argument("The given pattern is not a valid set")
                       :

                       state == set_end_state::not_or_first
                           ? *p == c.set_not ? set_end(cx::next(p), pend, c, set_end_state::first)
                                             : set_end(cx::next(p), pend, c, set_end_state::next)
                           : state == set_end_state::first
                                 ? set_end(cx::next(p), pend, c, set_end_state::next)
                                 : state == set_end_state::next
                                       ? *p == c.set_close
                                             ? cx::next(p)
                                             : set_end(cx::next(p), pend, c, set_end_state::next)
                                       : throw std::logic_error(
                                             "The program execution should never end up "
                                             "here throwing this exception");

#endif  // cfg_HAS_CONSTEXPR14
}

enum class match_set_state
{
  open,
  not_or_first_in,
  first_out,
  next_in,
  next_out
};

template <typename SequenceIterator, typename PatternIterator,
          typename EqualTo = cx::equal_to<void>>
constexpr bool match_set(
    SequenceIterator s, SequenceIterator send, PatternIterator p, PatternIterator pend,
    const cards<iterated_item_t<PatternIterator>>& c = cards<iterated_item_t<PatternIterator>>(),
    const EqualTo& equal_to = EqualTo(), match_set_state state = match_set_state::open)
{
#if cfg_HAS_CONSTEXPR14

  if (!c.set_enabled)
  {
#if cfg_HAS_FULL_FEATURED_CONSTEXPR_SWITCH
    throw std::invalid_argument("The use of sets is disabled");
#else
    return throw_invalid_argument("The use of sets is disabled");
#endif
  }

  if (p == pend)
  {
#if cfg_HAS_FULL_FEATURED_CONSTEXPR_SWITCH
    throw std::invalid_argument("The given pattern is not a valid set");
#else
    return throw_invalid_argument("The given pattern is not a valid set");
#endif
  }

  switch (state)
  {
    case match_set_state::open:
      if (*p == c.set_open)
      {
        return match_set(s, send, cx::next(p), pend, c, equal_to, match_set_state::not_or_first_in);
      }

#if cfg_HAS_FULL_FEATURED_CONSTEXPR_SWITCH
      throw std::invalid_argument("The given pattern is not a valid set");
#else
      return throw_invalid_argument("The given pattern is not a valid set");
#endif

    case match_set_state::not_or_first_in:
      if (*p == c.set_not)
      {
        return match_set(s, send, cx::next(p), pend, c, equal_to, match_set_state::first_out);
      }

      if (s == send)
      {
        return false;
      }

      if (equal_to(*s, *p))
      {
        return true;
      }

      return match_set(s, send, cx::next(p), pend, c, equal_to, match_set_state::next_in);

    case match_set_state::first_out:
      if (s == send || equal_to(*s, *p))
      {
        return false;
      }

      return match_set(s, send, cx::next(p), pend, c, equal_to, match_set_state::next_out);

    case match_set_state::next_in:
      if (*p == c.set_close || s == send)
      {
        return false;
      }

      if (equal_to(*s, *p))
      {
        return true;
      }

      return match_set(s, send, cx::next(p), pend, c, equal_to, state);

    case match_set_state::next_out:
      if (*p == c.set_close)
      {
        return true;
      }

      if (s == send || equal_to(*s, *p))
      {
        return false;
      }

      return match_set(s, send, cx::next(p), pend, c, equal_to, state);

    default:
#if cfg_HAS_FULL_FEATURED_CONSTEXPR_SWITCH
      throw std::logic_error(
          "The program execution should never end up here throwing this exception");
#else
      return throw_logic_error(
          "The program execution should never end up here throwing this exception");
#endif
  }

#else  // !cfg_HAS_CONSTEXPR14

  return !c.set_enabled
             ? throw std::invalid_argument("The use of sets is disabled")
             : p == pend
                   ? throw std::invalid_argument("The given pattern is not a valid set")
                   : state == match_set_state::open
                         ? *p == c.set_open
                               ? match_set(s, send, cx::next(p), pend, c, equal_to,
                                           match_set_state::not_or_first_in)
                               :

                               throw std::invalid_argument("The given pattern is not a valid set")
                         :

                         state == match_set_state::not_or_first_in
                             ? *p == c.set_not
                                   ? match_set(s, send, cx::next(p), pend, c, equal_to,
                                               match_set_state::first_out)
                                   :

                                   s != send && (equal_to(*s, *p) ||
                                                 match_set(s, send, cx::next(p), pend, c, equal_to,
                                                           match_set_state::next_in))

                             :

                             state == match_set_state::first_out
                                 ? s != send && !equal_to(*s, *p) &&
                                       match_set(s, send, cx::next(p), pend, c, equal_to,
                                                 match_set_state::next_out)

                                 :

                                 state == match_set_state::next_in
                                     ? *p != c.set_close && s != send &&
                                           (equal_to(*s, *p) || match_set(s, send, cx::next(p),
                                                                          pend, c, equal_to, state))

                                     :

                                     state == match_set_state::next_out
                                         ? *p == c.set_close ||
                                               (s != send && !equal_to(*s, *p) &&
                                                match_set(s, send, cx::next(p), pend, c, equal_to,
                                                          state))

                                         : throw std::logic_error(
                                               "The program execution should never end up "
                                               "here "
                                               "throwing this exception");

#endif  // cfg_HAS_CONSTEXPR14
}

enum class is_alt_state
{
  open,
  next,
  escape
};

template <typename PatternIterator>
constexpr bool is_alt(
    PatternIterator p, PatternIterator pend,
    const cards<iterated_item_t<PatternIterator>>& c = cards<iterated_item_t<PatternIterator>>(),
    is_alt_state state = is_alt_state::open, int depth = 0)
{
#if cfg_HAS_CONSTEXPR14

  if (!c.alt_enabled || p == pend)
  {
    return false;
  }

  switch (state)
  {
    case is_alt_state::open:
      if (*p == c.alt_open)
      {
        return is_alt(cx::next(p), pend, c, is_alt_state::next, depth + 1);
      }

      return false;

    case is_alt_state::next:
      if (*p == c.escape)
      {
        return is_alt(cx::next(p), pend, c, is_alt_state::escape, depth);
      }

      if (c.set_enabled && *p == c.set_open &&
          is_set(cx::next(p), pend, c, is_set_state::not_or_first))
      {
        return is_alt(set_end(cx::next(p), pend, c, set_end_state::not_or_first), pend, c, state,
                      depth);
      }

      if (*p == c.alt_open)
      {
        return is_alt(cx::next(p), pend, c, state, depth + 1);
      }

      if (*p == c.alt_close)
      {
        if (depth - 1 == 0)
        {
          return true;
        }

        return is_alt(cx::next(p), pend, c, state, depth - 1);
      }

      return is_alt(cx::next(p), pend, c, state, depth);

    case is_alt_state::escape:
      return is_alt(cx::next(p), pend, c, is_alt_state::next, depth);

    default:
#if cfg_HAS_FULL_FEATURED_CONSTEXPR_SWITCH
      throw std::logic_error(
          "The program execution should never end up here throwing this exception");
#else
      return throw_logic_error(
          p, "The program execution should never end up here throwing this exception");
#endif
  }

#else  // !cfg_HAS_CONSTEXPR14

  return c.alt_enabled && p != pend &&
         (state == is_alt_state::open
              ? *p == c.alt_open && is_alt(cx::next(p), pend, c, is_alt_state::next, depth + 1)
              : state == is_alt_state::next
                    ? *p == c.escape
                          ? is_alt(cx::next(p), pend, c, is_alt_state::escape, depth)
                          : c.set_enabled && *p == c.set_open &&
                                    is_set(cx::next(p), pend, c, is_set_state::not_or_first)
                                ? is_alt(set_end(cx::next(p), pend, c, set_end_state::not_or_first),
                                         pend, c, state, depth)
                                : *p == c.alt_open
                                      ? is_alt(cx::next(p), pend, c, state, depth + 1)
                                      : *p == c.alt_close
                                            ? depth - 1 == 0 ||
                                                  is_alt(cx::next(p), pend, c, state, depth - 1)
                                            : is_alt(cx::next(p), pend, c, state, depth)
                    :

                    state == is_alt_state::escape
                        ? is_alt(cx::next(p), pend, c, is_alt_state::next, depth)
                        : throw std::logic_error(
                              "The program execution should never end up here throwing this "
                              "exception"));

#endif  // cfg_HAS_CONSTEXPR14
}

enum class alt_end_state
{
  open,
  next,
  escape
};

template <typename PatternIterator>
constexpr PatternIterator alt_end(
    PatternIterator p, PatternIterator pend,
    const cards<iterated_item_t<PatternIterator>>& c = cards<iterated_item_t<PatternIterator>>(),
    alt_end_state state = alt_end_state::open, int depth = 0)
{
#if cfg_HAS_CONSTEXPR14

  if (!c.alt_enabled)
  {
#if cfg_HAS_FULL_FEATURED_CONSTEXPR_SWITCH
    throw std::invalid_argument("The use of alternatives is disabled");
#else
    return throw_invalid_argument(p, "The use of alternatives is disabled");
#endif
  }

  if (p == pend)
  {
#if cfg_HAS_FULL_FEATURED_CONSTEXPR_SWITCH
    throw std::invalid_argument("The given pattern is not a valid alternative");
#else
    return throw_invalid_argument(p, "The given pattern is not a valid alternative");
#endif
  }

  switch (state)
  {
    case alt_end_state::open:
      if (*p == c.alt_open)
      {
        return alt_end(cx::next(p), pend, c, alt_end_state::next, depth + 1);
      }

#if cfg_HAS_FULL_FEATURED_CONSTEXPR_SWITCH
      throw std::invalid_argument("The given pattern is not a valid alternative");
#else
      return throw_invalid_argument(p, "The given pattern is not a valid alternative");
#endif

    case alt_end_state::next:
      if (*p == c.escape)
      {
        return alt_end(cx::next(p), pend, c, alt_end_state::escape, depth);
      }

      if (c.set_enabled && *p == c.set_open &&
          is_set(cx::next(p), pend, c, is_set_state::not_or_first))
      {
        return alt_end(set_end(cx::next(p), pend, c, set_end_state::not_or_first), pend, c, state,
                       depth);
      }

      if (*p == c.alt_open)
      {
        return alt_end(cx::next(p), pend, c, state, depth + 1);
      }

      if (*p == c.alt_close)
      {
        if (depth - 1 == 0)
        {
          return cx::next(p);
        }

        return alt_end(cx::next(p), pend, c, state, depth - 1);
      }

      return alt_end(cx::next(p), pend, c, state, depth);

    case alt_end_state::escape:
      return alt_end(cx::next(p), pend, c, alt_end_state::next, depth);

    default:
#if cfg_HAS_FULL_FEATURED_CONSTEXPR_SWITCH
      throw std::logic_error(
          "The program execution should never end up here throwing this exception");
#else
      return throw_logic_error(
          p, "The program execution should never end up here throwing this exception");
#endif
  }

#else  // !cfg_HAS_CONSTEXPR14

  return !c.alt_enabled
             ? throw std::invalid_argument("The use of alternatives is disabled")
             : p == pend
                   ? throw std::invalid_argument("The given pattern is not a valid alternative")
                   : state == alt_end_state::open
                         ? *p == c.alt_open
                               ? alt_end(cx::next(p), pend, c, alt_end_state::next, depth + 1)
                               : throw std::invalid_argument(
                                     "The given pattern is not a valid alternative")
                         : state == alt_end_state::next
                               ? *p == c.escape
                                     ? alt_end(cx::next(p), pend, c, alt_end_state::escape, depth)
                                     : c.set_enabled && *p == c.set_open &&
                                               is_set(cx::next(p), pend, c,
                                                      is_set_state::not_or_first)
                                           ? alt_end(set_end(cx::next(p), pend, c,
                                                             set_end_state::not_or_first),
                                                     pend, c, state, depth)
                                           : *p == c.alt_open
                                                 ? alt_end(cx::next(p), pend, c, state, depth + 1)
                                                 : *p == c.alt_close
                                                       ? depth - 1 == 0
                                                             ? cx::next(p)
                                                             : alt_end(cx::next(p), pend, c, state,
                                                                       depth - 1)
                                                       : alt_end(cx::next(p), pend, c, state, depth)
                               :

                               state == alt_end_state::escape
                                   ? alt_end(cx::next(p), pend, c, alt_end_state::next, depth)
                                   : throw std::logic_error(
                                         "The program execution should never end up here throwing "
                                         "this "
                                         "exception");

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

  if (c.set_enabled && *p == c.set_open &&
      detail::is_set(cx::next(p), pend, c, detail::is_set_state::not_or_first))
  {
    return match_set(s, send, cx::next(p), pend, c, equal_to,
                     detail::match_set_state::not_or_first_in) &&
           match(cx::next(s), send,
                 detail::set_end(cx::next(p), pend, c, detail::set_end_state::not_or_first), pend,
                 c, equal_to);
  }

  if (c.alt_enabled && *p == c.alt_open &&
      detail::is_alt(cx::next(p), pend, c, detail::is_alt_state::next, 1))
  {
#if cfg_HAS_FULL_FEATURED_CONSTEXPR_SWITCH
    throw std::runtime_error("Sorry, alternatives not implemented");
#else
    return detail::throw_runtime_error("Sorry, alternatives not implemented");
#endif
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
                                     : c.set_enabled && *p == c.set_open &&
                                               detail::is_set(cx::next(p), pend, c,
                                                              detail::is_set_state::not_or_first)
                                           ? match_set(s, send, cx::next(p), pend, c, equal_to,
                                                       detail::match_set_state::not_or_first_in) &&
                                                 match(cx::next(s), send,
                                                       detail::set_end(
                                                           cx::next(p), pend, c,
                                                           detail::set_end_state::not_or_first),
                                                       pend, c, equal_to)
                                           : c.alt_enabled && *p == c.alt_open &&
                                                     detail::is_alt(cx::next(p), pend, c,
                                                                    detail::is_alt_state::next, 1)
                                                 ? throw std::runtime_error(
                                                       "Sorry, alternatives not implemented")
                                                 : s != send && equal_to(*s, *p) &&
                                                       match(cx::next(s), send, cx::next(p), pend,
                                                             c, equal_to);

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
