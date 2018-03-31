// Copyright Tomas Zeman 2018.
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef WILDCARDS_UTILITY_HPP
#define WILDCARDS_UTILITY_HPP

#include <utility>  // std::forward, std::move

namespace wildcards
{

template <typename First, typename Second>
struct pair
{
  constexpr pair(First first, Second second) : first{std::move(first)}, second{std::move(second)}
  {
  }

  First first;
  Second second;
};

template <typename First, typename Second>
constexpr pair<First, Second> make_pair(First&& first, Second&& second)
{
  return pair<First, Second>{std::forward<First>(first), std::forward<Second>(second)};
}

template <std::size_t Index, typename First, typename Second>
struct pair_element;

template <typename First, typename Second>
struct pair_element<0, First, Second>
{
  using type = First;

  constexpr static const First& get(const pair<First, Second>& p)
  {
    return p.first;
  }
};

template <typename First, typename Second>
struct pair_element<1, First, Second>
{
  using type = Second;

  constexpr static const Second& get(const pair<First, Second>& p)
  {
    return p.second;
  }
};

template <std::size_t Index, typename First, typename Second>
using pair_element_t = typename pair_element<Index, First, Second>::type;

template <std::size_t Index, typename First, typename Second>
constexpr const pair_element_t<Index, First, Second>& get(const pair<First, Second>& p)
{
  return pair_element<Index, First, Second>::get(p);
}

}  // namespace wildcards

#endif  // WILDCARDS_UTILITY_HPP
