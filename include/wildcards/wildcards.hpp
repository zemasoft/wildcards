// Copyright Tomas Zeman 2018.
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef WILDCARDS_WILDCARDS_HPP
#define WILDCARDS_WILDCARDS_HPP

#include <iterator>     // std::begin, std::end, std::next
#include <type_traits>  // std::remove_reference
#include <utility>      // std::declval, std::forward

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

template <typename SequenceContainer, typename PatternContainer>
class matcher
{
 public:
  using sequence_container_type = SequenceContainer;
  using pattern_container_type = PatternContainer;

  using sequence_iterator_type = iterator_type_t<sequence_container_type>;
  using pattern_iterator_type = iterator_type_t<pattern_container_type>;

  /*constexpr*/ bool match(sequence_iterator_type s, sequence_iterator_type send,
                           pattern_iterator_type p, pattern_iterator_type pend)
  {
    if (!is_asterisk(*p))
    {
      if (s != send)
      {
        if (is_question_mark(*p) || equal(*s, *p))
        {
          return match(std::next(s), send, std::next(p), pend);
        }

        return false;
      }

      return p == pend;
    }

    return match(s, send, std::next(p), pend) ||
           ((s != send) && match(std::next(s), send, p, pend));
  }
};

}  // namespace detail

template <typename SequenceContainer, typename PatternContainer>
/*constexpr*/ bool match(SequenceContainer&& sequence, PatternContainer&& pattern)
{
  detail::matcher<SequenceContainer, PatternContainer> matcher;
  return matcher.match(std::begin(std::forward<SequenceContainer>(sequence)),
                       std::end(std::forward<SequenceContainer>(sequence)),
                       std::begin(std::forward<PatternContainer>(pattern)),
                       std::end(std::forward<PatternContainer>(pattern)));
}

}  // namespace wildcards

#endif  // WILDCARDS_WILDCARDS_HPP
