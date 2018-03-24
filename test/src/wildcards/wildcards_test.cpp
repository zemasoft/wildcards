// Copyright Tomas Zeman 2018.
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#include <string>       // std::string, std::wstring
#include <type_traits>  // std::is_same
#include <utility>      // std::get
#include <vector>       // std::vector

#include <catch.hpp>

#include <wildcards/wildcards.hpp>

TEST_CASE("WildCards", "wildcards")
{
  SECTION("wildcards::detail::value_type")
  {
    using wildcards::detail::value_type;

    static_assert(std::is_same<value_type<char[3]>, char>::value, "");
    static_assert(std::is_same<value_type<char16_t[3]>, char16_t>::value, "");
    static_assert(std::is_same<value_type<char32_t[3]>, char32_t>::value, "");
    static_assert(std::is_same<value_type<wchar_t[3]>, wchar_t>::value, "");

    static_assert(std::is_same<value_type<std::string>, char>::value, "");
    static_assert(std::is_same<value_type<std::u16string>, char16_t>::value, "");
    static_assert(std::is_same<value_type<std::u32string>, char32_t>::value, "");
    static_assert(std::is_same<value_type<std::wstring>, wchar_t>::value, "");

    static_assert(std::is_same<value_type<char>, char>::value, "");
    static_assert(std::is_same<value_type<char16_t>, char16_t>::value, "");
    static_assert(std::is_same<value_type<char32_t>, char32_t>::value, "");
    static_assert(std::is_same<value_type<wchar_t>, wchar_t>::value, "");

    static_assert(std::is_same<value_type<std::vector<int>>, int>::value, "");
  }

  SECTION("wildcards::cards")
  {
    SECTION("wildcards::cards<char>")
    {
      constexpr wildcards::cards<char> cards;

      static_assert(std::get<0>(cards) == '*', "");
      static_assert(std::get<1>(cards) == '?', "");
    }

    SECTION("wildcards::cards<char16_t>")
    {
      constexpr wildcards::cards<char16_t> cards;

      static_assert(std::get<0>(cards) == u'*', "");
      static_assert(std::get<1>(cards) == u'?', "");
    }

    SECTION("wildcards::cards<char32_t>")
    {
      constexpr wildcards::cards<char32_t> cards;

      static_assert(std::get<0>(cards) == U'*', "");
      static_assert(std::get<1>(cards) == U'?', "");
    }

    SECTION("wildcards::cards<wchar_t>")
    {
      constexpr wildcards::cards<wchar_t> cards;

      static_assert(std::get<0>(cards) == L'*', "");
      static_assert(std::get<1>(cards) == L'?', "");
    }
  }

  SECTION("wildcards::match(char[], char[])")
  {
    SECTION("match with an empty pattern")
    {
      char pattern[] = "";

      REQUIRE(wildcards::match("", pattern));

      REQUIRE(!wildcards::match("Anything", pattern));
    }

    SECTION("match with \"A\"")
    {
      char pattern[] = "A";

      REQUIRE(wildcards::match("A", pattern));

      REQUIRE(!wildcards::match("", pattern));
      REQUIRE(!wildcards::match("a", pattern));
      REQUIRE(!wildcards::match("AA", pattern));
      REQUIRE(!wildcards::match("Something", pattern));
    }

    SECTION("match with \"Hallo!\"")
    {
      char pattern[] = "Hallo!";

      REQUIRE(wildcards::match("Hallo!", pattern));

      REQUIRE(!wildcards::match("", pattern));
      REQUIRE(!wildcards::match("Hello!", pattern));
      REQUIRE(!wildcards::match("HHallo!", pattern));
      REQUIRE(!wildcards::match("Hallo!!", pattern));
      REQUIRE(!wildcards::match("Hallo!Hallo!", pattern));
    }

    SECTION("match with \"*\"")
    {
      char pattern[] = "*";

      REQUIRE(wildcards::match("", pattern));
      REQUIRE(wildcards::match("Anything", pattern));
    }

    SECTION("match with \"?\"")
    {
      char pattern[] = "?";

      REQUIRE(wildcards::match("A", pattern));
      REQUIRE(wildcards::match("a", pattern));

      REQUIRE(!wildcards::match("", pattern));
      REQUIRE(!wildcards::match("Something", pattern));
    }

    SECTION("match with \"H?llo,*W*!\"")
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

  SECTION("wildcards::match(char16_t[], char16_t[])")
  {
    REQUIRE(wildcards::match(u"Hallo, World!", u"H?llo,*W*!"));
    REQUIRE(!wildcards::match(u"Hllo, World!", u"H?llo,*W*!"));
  }

  SECTION("wildcards::match(char32_t[], char32_t[])")
  {
    REQUIRE(wildcards::match(U"Hallo, World!", U"H?llo,*W*!"));
    REQUIRE(!wildcards::match(U"Hllo, World!", U"H?llo,*W*!"));
  }

  SECTION("wildcards::match(wchar_t[], wchar_t[])")
  {
    REQUIRE(wildcards::match(L"Hallo, World!", L"H?llo,*W*!"));
    REQUIRE(!wildcards::match(L"Hllo, World!", L"H?llo,*W*!"));
  }

  SECTION("wildcards::match(std::string, std::string)")
  {
    REQUIRE(wildcards::match(std::string("Hallo, World!"), std::string("H?llo,*W*!")));
    REQUIRE(!wildcards::match(std::string("Hllo, World!"), std::string("H?llo,*W*!")));
  }

  SECTION("wildcards::match(std::u16string, std::u16string)")
  {
    REQUIRE(wildcards::match(std::u16string(u"Hallo, World!"), std::u16string(u"H?llo,*W*!")));
    REQUIRE(!wildcards::match(std::u16string(u"Hllo, World!"), std::u16string(u"H?llo,*W*!")));
  }

  SECTION("wildcards::match(std::u32string, std::u32string)")
  {
    REQUIRE(wildcards::match(std::u32string(U"Hallo, World!"), std::u32string(U"H?llo,*W*!")));
    REQUIRE(!wildcards::match(std::u32string(U"Hllo, World!"), std::u32string(U"H?llo,*W*!")));
  }

  SECTION("wildcards::match(std::wstring, std::wstring)")
  {
    REQUIRE(wildcards::match(std::wstring(L"Hallo, World!"), std::wstring(L"H?llo,*W*!")));
    REQUIRE(!wildcards::match(std::wstring(L"Hllo, World!"), std::wstring(L"H?llo,*W*!")));
  }
}
