// Copyright Tomas Zeman 2018.
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#include <catch.hpp>

#include <cx/string.hpp>
#include <wildcards/match.hpp>

TEST_CASE("wildcards", "wildcards")
{
  using namespace cx::literals;

  static_assert(wildcards::match("test"_cs, "test"_cs), "");
  static_assert(wildcards::match("test"_cs, "t*st"_cs), "");
  static_assert(wildcards::match("test"_cs, "t?st"_cs), "");
  static_assert(wildcards::match("test"_cs, "t*t"_cs), "");

  static_assert(wildcards::match(u"Ahoj, jak se mas?"_cs, u"Ahoj, *m..?"_cs, {u'*', u'.'}), "");
}
