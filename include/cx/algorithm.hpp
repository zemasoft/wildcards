// Copyright Tomas Zeman 2018.
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef CX_ALGORITHM_HPP
#define CX_ALGORITHM_HPP

namespace cx
{

template <typename Iterator1, typename Iterator2>
constexpr bool equal(Iterator1 first1, Iterator1 last1, Iterator2 first2, Iterator2 last2)
{
  return first1 != last1 && first2 != last2 && *first1 == *first2
             ? equal(first1 + 1, last1, first2 + 1, last2)
             : first1 == last1 && first2 == last2;
}

}  // namespace cx

#endif  // CX_ALGORITHM_HPP
