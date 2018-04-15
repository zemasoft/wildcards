// Copyright Tomas Zeman 2018.
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#include "wildcards/wildcards.hpp"  // wildcards::match
#include "cx/string_view.hpp"       // cx::literals

#include "catch.hpp"

TEST_CASE("wildcards::match() is compliant", "[wildcards::match]")
{
  using namespace cx::literals;

  SECTION("match with an empty pattern")
  {
    constexpr auto pattern1 = ""_sv;
    constexpr auto pattern2 = R"(\)"_sv;

    static_assert(wildcards::match(""_sv, pattern1), "");
    static_assert(wildcards::match(""_sv, pattern2), "");

    static_assert(!wildcards::match("Anything"_sv, pattern1), "");
    static_assert(!wildcards::match("Anything"_sv, pattern2), "");
  }

  SECTION("match with \"A\"")
  {
    constexpr auto pattern1 = "A"_sv;
    constexpr auto pattern2 = R"(A\)"_sv;
    constexpr auto pattern3 = R"(\A)"_sv;

    static_assert(wildcards::match("A"_sv, pattern1), "");
    static_assert(wildcards::match("A"_sv, pattern2), "");
    static_assert(wildcards::match("A"_sv, pattern3), "");

    static_assert(!wildcards::match(""_sv, pattern1), "");
    static_assert(!wildcards::match(""_sv, pattern2), "");
    static_assert(!wildcards::match(""_sv, pattern3), "");

    static_assert(!wildcards::match("a"_sv, pattern1), "");
    static_assert(!wildcards::match("a"_sv, pattern2), "");
    static_assert(!wildcards::match("a"_sv, pattern3), "");

    static_assert(!wildcards::match("AA"_sv, pattern1), "");
    static_assert(!wildcards::match("AA"_sv, pattern2), "");
    static_assert(!wildcards::match("AA"_sv, pattern3), "");

    static_assert(!wildcards::match("Something"_sv, pattern1), "");
    static_assert(!wildcards::match("Something"_sv, pattern2), "");
    static_assert(!wildcards::match("Something"_sv, pattern3), "");
  }

  SECTION("match with \"Hallo!\"")
  {
    constexpr auto pattern1 = "Hallo!"_sv;
    constexpr auto pattern2 = R"(Hallo!\)"_sv;
    constexpr auto pattern3 = R"(\H\a\l\l\o\!)"_sv;

    static_assert(wildcards::match("Hallo!"_sv, pattern1), "");
    static_assert(wildcards::match("Hallo!"_sv, pattern2), "");
    static_assert(wildcards::match("Hallo!"_sv, pattern3), "");

    static_assert(!wildcards::match(""_sv, pattern1), "");
    static_assert(!wildcards::match(""_sv, pattern2), "");
    static_assert(!wildcards::match(""_sv, pattern3), "");

    static_assert(!wildcards::match("Hello!"_sv, pattern1), "");
    static_assert(!wildcards::match("Hello!"_sv, pattern2), "");
    static_assert(!wildcards::match("Hello!"_sv, pattern3), "");

    static_assert(!wildcards::match("HHallo!"_sv, pattern1), "");
    static_assert(!wildcards::match("HHallo!"_sv, pattern2), "");
    static_assert(!wildcards::match("HHallo!"_sv, pattern3), "");

    static_assert(!wildcards::match("Hallo!!"_sv, pattern1), "");
    static_assert(!wildcards::match("Hallo!!"_sv, pattern2), "");
    static_assert(!wildcards::match("Hallo!!"_sv, pattern3), "");

    static_assert(!wildcards::match("Hallo!Hallo!"_sv, pattern1), "");
    static_assert(!wildcards::match("Hallo!Hallo!"_sv, pattern2), "");
    static_assert(!wildcards::match("Hallo!Hallo!"_sv, pattern3), "");
  }

  SECTION("match with \"*\"")
  {
    constexpr auto pattern1 = "*"_sv;
    constexpr auto pattern2 = R"(*\)"_sv;
    constexpr auto pattern3 = R"(\*)"_sv;

    static_assert(wildcards::match(""_sv, pattern1), "");
    static_assert(wildcards::match(""_sv, pattern2), "");
    static_assert(!wildcards::match(""_sv, pattern3), "");

    static_assert(wildcards::match("*"_sv, pattern1), "");
    static_assert(wildcards::match("*"_sv, pattern2), "");
    static_assert(wildcards::match("*"_sv, pattern3), "");

    static_assert(wildcards::match("Anything"_sv, pattern1), "");
    static_assert(wildcards::match("Anything"_sv, pattern2), "");
    static_assert(!wildcards::match("Anything"_sv, pattern3), "");
  }

  SECTION("match with \"?\"")
  {
    constexpr auto pattern1 = "?"_sv;
    constexpr auto pattern2 = R"(?\)"_sv;
    constexpr auto pattern3 = R"(\?)"_sv;

    static_assert(wildcards::match("A"_sv, pattern1), "");
    static_assert(wildcards::match("A"_sv, pattern2), "");
    static_assert(!wildcards::match("A"_sv, pattern3), "");

    static_assert(wildcards::match("a"_sv, pattern1), "");
    static_assert(wildcards::match("a"_sv, pattern2), "");
    static_assert(!wildcards::match("a"_sv, pattern3), "");

    static_assert(wildcards::match("?"_sv, pattern1), "");
    static_assert(wildcards::match("?"_sv, pattern2), "");
    static_assert(wildcards::match("?"_sv, pattern3), "");

    static_assert(!wildcards::match(""_sv, pattern1), "");
    static_assert(!wildcards::match(""_sv, pattern2), "");
    static_assert(!wildcards::match(""_sv, pattern3), "");

    static_assert(!wildcards::match("Something"_sv, pattern1), "");
    static_assert(!wildcards::match("Something"_sv, pattern2), "");
    static_assert(!wildcards::match("Something"_sv, pattern3), "");
  }

  SECTION("match with \"H?llo,*W*!\"")
  {
    constexpr auto pattern = "H?llo,*W*!"_sv;

    static_assert(wildcards::match("Hallo, World!"_sv, pattern), "");
    static_assert(wildcards::match("Hello, World!"_sv, pattern), "");
    static_assert(wildcards::match("Hello,World!"_sv, pattern), "");
    static_assert(wildcards::match("Hello,WildCards!"_sv, pattern), "");
    static_assert(wildcards::match("Hello, crazy WildCards!"_sv, pattern), "");
    static_assert(wildcards::match("Hello, crazy WildCards! Still working?!"_sv, pattern), "");

    static_assert(!wildcards::match(""_sv, pattern), "");
    static_assert(!wildcards::match("Hllo, World!"_sv, pattern), "");
    static_assert(!wildcards::match("Hallo, World?"_sv, pattern), "");
    static_assert(!wildcards::match("Hallo, world!"_sv, pattern), "");
    static_assert(!wildcards::match("Yes. Hallo, World!"_sv, pattern), "");
    static_assert(!wildcards::match("Hallo, World!?"_sv, pattern), "");
  }
}
