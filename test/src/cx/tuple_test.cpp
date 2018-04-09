// Copyright Tomas Zeman 2018.
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#include <type_traits>

#include <cx/tuple.hpp>

#include <catch.hpp>

TEST_CASE("tuple", "[tuple]")
{
  SECTION("tuple<>")
  {
    constexpr auto t1 = cx::tuple<>{};
    constexpr auto t2 = cx::make_tuple();

    static_assert(std::is_same<decltype(t1), decltype(t2)>::value, "");

    static_assert(t1 == t2, "");
  }

  SECTION("tuple<int>")
  {
    constexpr auto t1 = cx::tuple<int>{};
    constexpr auto t2 = cx::tuple<int>{10};
    constexpr auto t3 = cx::make_tuple(10);

    static_assert(std::is_same<decltype(t1), decltype(t2)>::value, "");
    static_assert(std::is_same<decltype(t1), decltype(t3)>::value, "");

    static_assert(t2 == t3, "");

    static_assert(cx::get<0>(t2) == 10, "");

    static_assert(cx::make_tuple(10) != cx::make_tuple(20), "");
  }

  SECTION("tuple<int, char>")
  {
    constexpr auto t1 = cx::tuple<int, char>{};
    constexpr auto t2 = cx::tuple<int, char>{10, 'a'};
    constexpr auto t3 = cx::make_tuple(10, 'a');

    static_assert(std::is_same<decltype(t1), decltype(t2)>::value, "");
    static_assert(std::is_same<decltype(t1), decltype(t3)>::value, "");

    static_assert(t2 == t3, "");

    static_assert(cx::get<0>(t2) == 10, "");
    static_assert(cx::get<1>(t2) == 'a', "");

    static_assert(cx::make_tuple(10, 'a') != cx::make_tuple(20, 'a'), "");
    static_assert(cx::make_tuple(10, 'a') != cx::make_tuple(10, 'b'), "");
    static_assert(cx::make_tuple(10, 'a') != cx::make_tuple(20, 'b'), "");
  }

  SECTION("tuple<int, char, double>")
  {
    constexpr auto t1 = cx::tuple<int, char, double>{};
    constexpr auto t2 = cx::tuple<int, char, double>{10, 'a', 5.5};
    constexpr auto t3 = cx::make_tuple(10, 'a', 5.5);

    static_assert(std::is_same<decltype(t1), decltype(t2)>::value, "");
    static_assert(std::is_same<decltype(t1), decltype(t3)>::value, "");

    static_assert(t2 == t3, "");

    static_assert(cx::get<0>(t2) == 10, "");
    static_assert(cx::get<1>(t2) == 'a', "");
    static_assert(cx::get<2>(t2) == 5.5, "");

    static_assert(cx::make_tuple(10, 'a', 5.5) != cx::make_tuple(20, 'a', 5.5), "");
    static_assert(cx::make_tuple(10, 'a', 5.5) != cx::make_tuple(10, 'b', 5.5), "");
    static_assert(cx::make_tuple(10, 'a', 5.5) != cx::make_tuple(10, 'a', 5.6), "");
    static_assert(cx::make_tuple(10, 'a', 5.5) != cx::make_tuple(20, 'b', 5.5), "");
    static_assert(cx::make_tuple(10, 'a', 5.5) != cx::make_tuple(20, 'a', 5.6), "");
    static_assert(cx::make_tuple(10, 'a', 5.5) != cx::make_tuple(10, 'b', 5.6), "");
    static_assert(cx::make_tuple(10, 'a', 5.5) != cx::make_tuple(20, 'b', 5.6), "");
  }
}
