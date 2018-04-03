// Copyright Tomas Zeman 2018.
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#include <catch.hpp>

#include <cx/string_view.hpp>
#include <cx/tuple.hpp>
#include <cx/utility.hpp>

TEST_CASE("cx", "cx")
{
  using namespace cx::literals;

  constexpr auto s1 = cx::basic_string_view<char>("test");
  constexpr auto s2 = cx::make_string_view("test");
  constexpr auto s3 = cx::string_view("test");
  constexpr auto s4 = "test"_cs;
  constexpr auto s5 = cx::make_string_view("testt", 4);

  static_assert(s1 == s2, "");
  static_assert(s1 == s3, "");
  static_assert(s1 == s4, "");
  static_assert(s1 == s5, "");

  constexpr auto t1 = cx::tuple<int>{10};
  constexpr auto t2 = cx::tuple<int, char>{10, 'a'};
  constexpr auto t3 = cx::make_tuple(10, 'a', 5.5);

  static_assert(cx::get<0>(t1) == 10, "");
  static_assert(cx::get<0>(t2) == 10, "");
  static_assert(cx::get<1>(t2) == 'a', "");
  static_assert(cx::get<0>(t3) == 10, "");
  static_assert(cx::get<1>(t3) == 'a', "");
  static_assert(cx::get<2>(t3) == 5.5, "");

  constexpr auto p1 = cx::pair<int, char>{10, 'a'};
  constexpr auto p2 = cx::make_pair(10, 'a');

  static_assert(cx::get<0>(p1) == 10, "");
  static_assert(cx::get<1>(p1) == 'a', "");
  static_assert(cx::get<int>(p1) == 10, "");
  static_assert(cx::get<char>(p1) == 'a', "");
  static_assert(cx::get<0>(p2) == 10, "");
  static_assert(cx::get<1>(p2) == 'a', "");
}
