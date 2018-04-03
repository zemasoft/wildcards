// Copyright Tomas Zeman 2018.
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#include <catch.hpp>

#include <cx/string_view.hpp>
#include <wildcards/wildcards.hpp>

TEST_CASE("wildcards", "wildcards")
{
  using namespace cx::literals;

  static_assert(wildcards::match("test"_sv, "test"_sv), "");
  static_assert(wildcards::match("test"_sv, "t*st"_sv), "");
  static_assert(wildcards::match("test"_sv, "t?st"_sv), "");
  static_assert(wildcards::match("test"_sv, "t*t"_sv), "");

  constexpr auto cards = wildcards::make_cards(u'*', u'.');
  static_assert(wildcards::match(u"Ahoj, jak se mas?"_sv, u"Ahoj, *m..?"_sv, cards), "");
  static_assert(wildcards::match(u"Ahoj, jak se mas?"_sv, u"Ahoj, *m..?"_sv, {u'*', u'.'}), "");
}
