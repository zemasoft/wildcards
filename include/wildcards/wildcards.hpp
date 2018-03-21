// Copyright Tomas Zeman 2018.
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef WILDCARDS_WILDCARDS_HPP
#define WILDCARDS_WILDCARDS_HPP

#include <iterator>     // std::begin, std::end, std::next
#include <type_traits>  // std::remove_cv, std::remove_reference
#include <utility>      // std::declval, std::forward, std::get, std::pair

namespace wildcards
{

template <typename T>
class cards;

template <>
class cards<char> : public std::pair<char, char>
{
 public:
  constexpr cards() : std::pair<char, char>{'*', '?'}
  {
  }
};

template <>
class cards<wchar_t> : public std::pair<wchar_t, wchar_t>
{
 public:
  constexpr cards() : std::pair<wchar_t, wchar_t>{L'*', L'?'}
  {
  }
};

namespace detail
{

template <typename T>
using value_type = typename std::remove_cv<
    typename std::remove_reference<decltype(*std::begin(std::declval<T>()))>::type>::type;

template <typename SequenceIterator, typename PatternIterator, typename Cards>
/*constexpr*/ bool match(SequenceIterator s, SequenceIterator send, PatternIterator p,
                         PatternIterator pend, const Cards& cards)
{
  if (*p != std::get<0>(cards))
  {
    if (s != send)
    {
      if (*p == std::get<1>(cards) || *s == *p)
      {
        return match(std::next(s), send, std::next(p), pend, cards);
      }

      return false;
    }

    return p == pend;
  }

  return match(s, send, std::next(p), pend, cards) ||
         ((s != send) && match(std::next(s), send, p, pend, cards));
}

}  // namespace detail

template <typename Sequence, typename Pattern, typename Cards = cards<detail::value_type<Pattern>>>
/*constexpr*/ bool match(Sequence&& sequence, Pattern&& pattern, Cards&& cards = Cards())
{
  return detail::match(std::begin(std::forward<Sequence>(sequence)),
                       std::end(std::forward<Sequence>(sequence)),
                       std::begin(std::forward<Pattern>(pattern)),
                       std::end(std::forward<Pattern>(pattern)), std::forward<Cards>(cards));
}

}  // namespace wildcards

#endif  // WILDCARDS_WILDCARDS_HPP
