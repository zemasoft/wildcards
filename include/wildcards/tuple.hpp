// Copyright Tomas Zeman 2018.
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef WILDCARDS_TUPLE_HPP
#define WILDCARDS_TUPLE_HPP

#include <utility>  // std::forward, std::move

namespace wildcards
{

template <typename First, typename... Rest>
struct tuple : public tuple<Rest...>
{
  constexpr tuple(First first, Rest... rest)
      : tuple<Rest...>{std::move(rest)...}, first{std::move(first)}
  {
  }

  First first;
};

template <typename First>
struct tuple<First>
{
  constexpr tuple(First first) : first{std::move(first)}
  {
  }

  First first;
};

template <typename... Types>
constexpr tuple<Types...> make_tuple(Types&&... types)
{
  return tuple<Types...>{std::forward<Types>(types)...};
}

template <std::size_t Index, typename First, typename... Rest>
struct tuple_element
{
  using type = typename tuple_element<Index - 1, Rest...>::type;

  constexpr static const typename tuple_element<Index - 1, Rest...>::type& get(
      const tuple<First, Rest...>& t)
  {
    return tuple_element<Index - 1, Rest...>::get(t);
  }
};

template <typename First, typename... Rest>
struct tuple_element<0, First, Rest...>
{
  using type = First;

  constexpr static const First& get(const tuple<First, Rest...>& t)
  {
    return t.first;
  }
};

template <std::size_t Index, typename First, typename... Rest>
using tuple_element_t = typename tuple_element<Index, First, Rest...>::type;

template <std::size_t Index, typename First, typename... Rest>
constexpr const tuple_element_t<Index, First, Rest...>& get(const tuple<First, Rest...>& t)
{
  return tuple_element<Index, First, Rest...>::get(t);
}

}  // namespace wildcards

#endif  // WILDCARDS_TUPLE_HPP
