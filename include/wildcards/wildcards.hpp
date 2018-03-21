// Copyright Tomas Zeman 2018.
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef WILDCARDS_WILDCARDS_HPP
#define WILDCARDS_WILDCARDS_HPP

#include <iterator>     // std::begin, std::end, std::next
#include <type_traits>  // std::remove_reference
#include <utility>      // std::declval, std::forward, std::pair

namespace wildcards
{

template <typename T, typename U>
constexpr bool equal(const T& lhs, const U& rhs)
{
  return lhs == rhs;
}

template <typename T>
constexpr bool is_asterisk(T val);

template <>
constexpr bool is_asterisk(char val)
{
  return val == '*';
}

template <>
constexpr bool is_asterisk(wchar_t val)
{
  return val == '*';
}

template <typename T>
constexpr bool is_question_mark(T val);

template <>
constexpr bool is_question_mark(char val)
{
  return val == '?';
}

template <>
constexpr bool is_question_mark(wchar_t val)
{
  return val == '?';
}

namespace detail
{

template <typename T>
struct iterator_type
{
  using type = typename std::remove_reference<decltype(std::begin(std::declval<T>()))>::type;
};

template <typename T>
using iterator_type_t = typename iterator_type<T>::type;

template <typename T>
struct value_type
{
  using type = typename std::remove_reference<decltype(*std::begin(std::declval<T>()))>::type;
};

template <typename T>
using value_type_t = typename value_type<T>::type;

template <typename SequenceIterator, typename PatternIterator, typename Cards>
/*constexpr*/ bool match(SequenceIterator s, SequenceIterator send, PatternIterator p,
                         PatternIterator pend, const Cards& cards)
{
  if (!is_asterisk(*p))
  {
    if (s != send)
    {
      if (is_question_mark(*p) || equal(*s, *p))
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

template <typename Sequence, typename Pattern,
          typename Cards = std::pair<detail::value_type_t<Pattern>, detail::value_type_t<Pattern>>>
/*constexpr*/ bool match(Sequence&& sequence, Pattern&& pattern, Cards&& cards = Cards())
{
  return detail::match(std::begin(std::forward<Sequence>(sequence)),
                       std::end(std::forward<Sequence>(sequence)),
                       std::begin(std::forward<Pattern>(pattern)),
                       std::end(std::forward<Pattern>(pattern)), std::forward<Cards>(cards));
}

}  // namespace wildcards

#endif  // WILDCARDS_WILDCARDS_HPP
