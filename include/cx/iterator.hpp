// Copyright Tomas Zeman 2018.
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef CX_ITERATOR_HPP
#define CX_ITERATOR_HPP

namespace cx
{

template <typename C>
constexpr auto begin(const C& c) -> decltype(c.begin())
{
  return c.begin();
}

template <typename C>
constexpr auto begin(C& c) -> decltype(c.begin())
{
  return c.begin();
}

template <typename C>
constexpr auto end(const C& c) -> decltype(c.end())
{
  return c.end();
}

template <typename C>
constexpr auto end(C& c) -> decltype(c.end())
{
  return c.end();
}

}  // namespace cx

#endif  // CX_ITERATOR_HPP
