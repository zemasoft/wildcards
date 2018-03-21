// Copyright Tomas Zeman 2018.
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#include <string>  // std::string, std::wstring

#include <catch.hpp>

#include <wildcards/wildcards.hpp>

TEST_CASE("WildCards", "wildcards")
{
  SECTION("char[]")
  {
    SECTION("Match with an empty pattern")
    {
      char pattern[] = "";

      REQUIRE(wildcards::match("", pattern));

      REQUIRE(!wildcards::match("Anything", pattern));
    }

    SECTION("Match with 'A'")
    {
      char pattern[] = "A";

      REQUIRE(wildcards::match("A", pattern));

      REQUIRE(!wildcards::match("", pattern));
      REQUIRE(!wildcards::match("a", pattern));
      REQUIRE(!wildcards::match("AA", pattern));
      REQUIRE(!wildcards::match("Something", pattern));
    }

    SECTION("Match with 'Hallo!'")
    {
      char pattern[] = "Hallo!";

      REQUIRE(wildcards::match("Hallo!", pattern));

      REQUIRE(!wildcards::match("", pattern));
      REQUIRE(!wildcards::match("Hello!", pattern));
      REQUIRE(!wildcards::match("HHallo!", pattern));
      REQUIRE(!wildcards::match("Hallo!!", pattern));
      REQUIRE(!wildcards::match("Hallo!Hallo!", pattern));
    }

    SECTION("Match with '*'")
    {
      char pattern[] = "*";

      REQUIRE(wildcards::match("", pattern));
      REQUIRE(wildcards::match("Anything", pattern));
    }

    SECTION("Match with '?'")
    {
      char pattern[] = "?";

      REQUIRE(wildcards::match("A", pattern));
      REQUIRE(wildcards::match("a", pattern));

      REQUIRE(!wildcards::match("", pattern));
      REQUIRE(!wildcards::match("Something", pattern));
    }

    SECTION("Match with 'H?llo,*W*!'")
    {
      char pattern[] = "H?llo,*W*!";

      REQUIRE(wildcards::match("Hallo, World!", pattern));
      REQUIRE(wildcards::match("Hello, World!", pattern));
      REQUIRE(wildcards::match("Hello,World!", pattern));
      REQUIRE(wildcards::match("Hello,WildCards!", pattern));
      REQUIRE(wildcards::match("Hello, crazy WildCards!", pattern));
      REQUIRE(wildcards::match("Hello, crazy WildCards! Still working?!", pattern));

      REQUIRE(!wildcards::match("", pattern));
      REQUIRE(!wildcards::match("Hllo, World!", pattern));
      REQUIRE(!wildcards::match("Hallo, World?", pattern));
      REQUIRE(!wildcards::match("Hallo, world!", pattern));
      REQUIRE(!wildcards::match("Yes. Hallo, World!", pattern));
      REQUIRE(!wildcards::match("Hallo, World!?", pattern));
    }
  }

  SECTION("wchar_t[]")
  {
    REQUIRE(wildcards::match(L"Hallo, World!", L"H?llo,*W*!"));
    REQUIRE(!wildcards::match(L"Hllo, World!", L"H?llo,*W*!"));
  }

  SECTION("std::string")
  {
    REQUIRE(wildcards::match(std::string("Hallo, World!"), std::string("H?llo,*W*!")));
    REQUIRE(!wildcards::match(std::string("Hllo, World!"), std::string("H?llo,*W*!")));
  }

  SECTION("std::wstring")
  {
    REQUIRE(wildcards::match(std::wstring(L"Hallo, World!"), std::wstring(L"H?llo,*W*!")));
    REQUIRE(!wildcards::match(std::wstring(L"Hllo, World!"), std::wstring(L"H?llo,*W*!")));
  }
}
