// Copyright Tomas Zeman 2018.
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#include <cx/string_view.hpp>       // cx::literals
#include <wildcards/wildcards.hpp>  // wildcards::match

#include <catch.hpp>

TEST_CASE("wildcards::match() is compliant", "[wildcards::match]")
{
  using namespace cx::literals;

  SECTION("wildcards::match(cx::string_view, cx::string_view)")
  {
    SECTION("match with an empty pattern")
    {
      constexpr auto pattern = ""_sv;

      static_assert(wildcards::match(""_sv, pattern), "");

      static_assert(!wildcards::match("Anything"_sv, pattern), "");
    }

    SECTION("match with \"A\"")
    {
      constexpr auto pattern = "A"_sv;

      static_assert(wildcards::match("A"_sv, pattern), "");

      static_assert(!wildcards::match(""_sv, pattern), "");
      static_assert(!wildcards::match("a"_sv, pattern), "");
      static_assert(!wildcards::match("AA"_sv, pattern), "");
      static_assert(!wildcards::match("Something"_sv, pattern), "");
    }

    SECTION("match with \"Hallo!\"")
    {
      constexpr auto pattern = "Hallo!"_sv;

      static_assert(wildcards::match("Hallo!"_sv, pattern), "");

      static_assert(!wildcards::match(""_sv, pattern), "");
      static_assert(!wildcards::match("Hello!"_sv, pattern), "");
      static_assert(!wildcards::match("HHallo!"_sv, pattern), "");
      static_assert(!wildcards::match("Hallo!!"_sv, pattern), "");
      static_assert(!wildcards::match("Hallo!Hallo!"_sv, pattern), "");
    }

    SECTION("match with \"*\"")
    {
      constexpr auto pattern = "*"_sv;

      static_assert(wildcards::match(""_sv, pattern), "");
      static_assert(wildcards::match("Anything"_sv, pattern), "");
    }

    SECTION("match with \"?\"")
    {
      constexpr auto pattern = "?"_sv;

      static_assert(wildcards::match("A"_sv, pattern), "");
      static_assert(wildcards::match("a"_sv, pattern), "");

      static_assert(!wildcards::match(""_sv, pattern), "");
      static_assert(!wildcards::match("Something"_sv, pattern), "");
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
}
