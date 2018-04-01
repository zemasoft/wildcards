// Copyright Tomas Zeman 2018.
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef WILDCARDS_ITERATOR_HPP
#define WILDCARDS_ITERATOR_HPP

namespace wildcards
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

}  // namespace wildcards

#endif  // WILDCARDS_ITERATOR_HPP
