// Copyright Tomas Zeman 2018.
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef CX_UTILITY_HPP
#define CX_UTILITY_HPP

#include <utility>  // std::forward, std::move

namespace cx
{

template <typename First, typename Second>
struct pair
{
  using first_type = First;
  using second_type = Second;

  constexpr pair() = default;

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

  constexpr static First& get(pair<First, Second>& p)
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

  constexpr static Second& get(pair<First, Second>& p)
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

template <std::size_t Index, typename First, typename Second>
constexpr pair_element_t<Index, First, Second>& get(pair<First, Second>& p)
{
  return pair_element<Index, First, Second>::get(p);
}

template <typename T, typename U>
constexpr const T& get(const pair<T, U>& p)
{
  return p.first;
}

template <typename T, typename U>
constexpr T& get(pair<T, U>& p)
{
  return p.first;
}

template <typename T, typename U>
constexpr const T& get(const pair<U, T>& p)
{
  return p.second;
}

template <typename T, typename U>
constexpr T& get(pair<U, T>& p)
{
  return p.second;
}

}  // namespace cx

#endif  // CX_UTILITY_HPP
