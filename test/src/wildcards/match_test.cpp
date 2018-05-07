// Copyright Tomas Zeman 2018.
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#include "wildcards/match.hpp"  // wildcards::match
#include "cx/array.hpp"         // cx::array
#include "cx/iterator.hpp"      // cx::begin, cx::end
#include "cx/string_view.hpp"   // cx::literals

#include "catch.hpp"

TEST_CASE("wildcards::detail::is_enum() is compliant", "[wildcards::detail::is_enum]")
{
  using wildcards::detail::is_enum;

  SECTION("")
  {
    constexpr char pattern1[] = "[a]";
    constexpr char pattern2[] = "[abc]";

    constexpr char pattern3[] = "[]]";
    constexpr char pattern4[] = "[]a]";
    constexpr char pattern5[] = "[]abc]";
    constexpr char pattern6[] = "[][]";
    constexpr char pattern7[] = "[][a]";
    constexpr char pattern8[] = "[][abc]";

    constexpr char pattern9[] = "[[]";
    constexpr char pattern10[] = "[[a]";
    constexpr char pattern11[] = "[[abc]";

    static_assert(is_enum(cx::begin(pattern1), cx::end(pattern1)), "");
    static_assert(is_enum(cx::begin(pattern2), cx::end(pattern2)), "");

    static_assert(is_enum(cx::begin(pattern3), cx::end(pattern3)), "");
    static_assert(is_enum(cx::begin(pattern4), cx::end(pattern4)), "");
    static_assert(is_enum(cx::begin(pattern5), cx::end(pattern5)), "");
    static_assert(is_enum(cx::begin(pattern6), cx::end(pattern6)), "");
    static_assert(is_enum(cx::begin(pattern7), cx::end(pattern7)), "");
    static_assert(is_enum(cx::begin(pattern8), cx::end(pattern8)), "");

    static_assert(is_enum(cx::begin(pattern9), cx::end(pattern9)), "");
    static_assert(is_enum(cx::begin(pattern10), cx::end(pattern10)), "");
    static_assert(is_enum(cx::begin(pattern11), cx::end(pattern11)), "");
  }

  SECTION("")
  {
    constexpr char pattern1[] = "[!a]";
    constexpr char pattern2[] = "[!abc]";

    constexpr char pattern3[] = "[!]]";
    constexpr char pattern4[] = "[!]a]";
    constexpr char pattern5[] = "[!]abc]";
    constexpr char pattern6[] = "[!][]";
    constexpr char pattern7[] = "[!][a]";
    constexpr char pattern8[] = "[!][abc]";

    constexpr char pattern9[] = "[![]";
    constexpr char pattern10[] = "[![a]";
    constexpr char pattern11[] = "[![abc]";

    static_assert(is_enum(cx::begin(pattern1), cx::end(pattern1)), "");
    static_assert(is_enum(cx::begin(pattern2), cx::end(pattern2)), "");

    static_assert(is_enum(cx::begin(pattern3), cx::end(pattern3)), "");
    static_assert(is_enum(cx::begin(pattern4), cx::end(pattern4)), "");
    static_assert(is_enum(cx::begin(pattern5), cx::end(pattern5)), "");
    static_assert(is_enum(cx::begin(pattern6), cx::end(pattern6)), "");
    static_assert(is_enum(cx::begin(pattern7), cx::end(pattern7)), "");
    static_assert(is_enum(cx::begin(pattern8), cx::end(pattern8)), "");

    static_assert(is_enum(cx::begin(pattern9), cx::end(pattern9)), "");
    static_assert(is_enum(cx::begin(pattern10), cx::end(pattern10)), "");
    static_assert(is_enum(cx::begin(pattern11), cx::end(pattern11)), "");
  }

  SECTION("")
  {
    constexpr char pattern1[] = "";
    constexpr char pattern2[] = "a";
    constexpr char pattern3[] = "!";

    constexpr char pattern4[] = "[";
    constexpr char pattern5[] = "[a";
    constexpr char pattern6[] = "[]";
    constexpr char pattern7[] = "[]a";

    constexpr char pattern8[] = "[!";
    constexpr char pattern9[] = "[!a";
    constexpr char pattern10[] = "[!]";
    constexpr char pattern11[] = "[!]a";

    static_assert(!is_enum(cx::begin(pattern1), cx::end(pattern1)), "");
    static_assert(!is_enum(cx::begin(pattern2), cx::end(pattern2)), "");
    static_assert(!is_enum(cx::begin(pattern3), cx::end(pattern3)), "");

    static_assert(!is_enum(cx::begin(pattern4), cx::end(pattern4)), "");
    static_assert(!is_enum(cx::begin(pattern5), cx::end(pattern5)), "");
    static_assert(!is_enum(cx::begin(pattern6), cx::end(pattern6)), "");
    static_assert(!is_enum(cx::begin(pattern7), cx::end(pattern7)), "");

    static_assert(!is_enum(cx::begin(pattern8), cx::end(pattern8)), "");
    static_assert(!is_enum(cx::begin(pattern9), cx::end(pattern9)), "");
    static_assert(!is_enum(cx::begin(pattern10), cx::end(pattern10)), "");
    static_assert(!is_enum(cx::begin(pattern11), cx::end(pattern11)), "");
  }
}

TEST_CASE("wildcards::detail::match_enum() is compliant", "[wildcards::detail::match_enum]")
{
  using wildcards::detail::match_enum;

  SECTION("")
  {
    constexpr char pattern[] = "[a]";

    constexpr char seq1[] = "";
    constexpr char seq2[] = "a";
    constexpr char seq3[] = "b";

    static_assert(!match_enum(cx::begin(seq1), cx::end(seq1), cx::begin(pattern), cx::end(pattern)),
                  "");
    static_assert(match_enum(cx::begin(seq2), cx::end(seq2), cx::begin(pattern), cx::end(pattern)),
                  "");
    static_assert(!match_enum(cx::begin(seq3), cx::end(seq3), cx::begin(pattern), cx::end(pattern)),
                  "");
  }

  SECTION("")
  {
    constexpr char pattern[] = "[abc]";

    constexpr char seq1[] = "";
    constexpr char seq2[] = "a";
    constexpr char seq3[] = "b";
    constexpr char seq4[] = "c";
    constexpr char seq5[] = "d";

    static_assert(!match_enum(cx::begin(seq1), cx::end(seq1), cx::begin(pattern), cx::end(pattern)),
                  "");
    static_assert(match_enum(cx::begin(seq2), cx::end(seq2), cx::begin(pattern), cx::end(pattern)),
                  "");
    static_assert(match_enum(cx::begin(seq3), cx::end(seq3), cx::begin(pattern), cx::end(pattern)),
                  "");
    static_assert(match_enum(cx::begin(seq4), cx::end(seq4), cx::begin(pattern), cx::end(pattern)),
                  "");
    static_assert(!match_enum(cx::begin(seq5), cx::end(seq5), cx::begin(pattern), cx::end(pattern)),
                  "");
  }

  SECTION("")
  {
    constexpr char pattern[] = "[]]";

    constexpr char seq1[] = "";
    constexpr char seq2[] = "]";
    constexpr char seq3[] = "a";

    static_assert(!match_enum(cx::begin(seq1), cx::end(seq1), cx::begin(pattern), cx::end(pattern)),
                  "");
    static_assert(match_enum(cx::begin(seq2), cx::end(seq2), cx::begin(pattern), cx::end(pattern)),
                  "");
    static_assert(!match_enum(cx::begin(seq3), cx::end(seq3), cx::begin(pattern), cx::end(pattern)),
                  "");
  }

  SECTION("")
  {
    constexpr char pattern[] = "[]abc]";

    constexpr char seq1[] = "";
    constexpr char seq2[] = "]";
    constexpr char seq3[] = "a";
    constexpr char seq4[] = "b";
    constexpr char seq5[] = "c";
    constexpr char seq6[] = "d";

    static_assert(!match_enum(cx::begin(seq1), cx::end(seq1), cx::begin(pattern), cx::end(pattern)),
                  "");
    static_assert(match_enum(cx::begin(seq2), cx::end(seq2), cx::begin(pattern), cx::end(pattern)),
                  "");
    static_assert(match_enum(cx::begin(seq3), cx::end(seq3), cx::begin(pattern), cx::end(pattern)),
                  "");
    static_assert(match_enum(cx::begin(seq4), cx::end(seq4), cx::begin(pattern), cx::end(pattern)),
                  "");
    static_assert(match_enum(cx::begin(seq5), cx::end(seq5), cx::begin(pattern), cx::end(pattern)),
                  "");
    static_assert(!match_enum(cx::begin(seq6), cx::end(seq6), cx::begin(pattern), cx::end(pattern)),
                  "");
  }

  SECTION("")
  {
    constexpr char pattern[] = "[!a]";

    constexpr char seq1[] = "";
    constexpr char seq2[] = "a";
    constexpr char seq3[] = "b";

    static_assert(!match_enum(cx::begin(seq1), cx::end(seq1), cx::begin(pattern), cx::end(pattern)),
                  "");
    static_assert(!match_enum(cx::begin(seq2), cx::end(seq2), cx::begin(pattern), cx::end(pattern)),
                  "");
    static_assert(match_enum(cx::begin(seq3), cx::end(seq3), cx::begin(pattern), cx::end(pattern)),
                  "");
  }

  SECTION("")
  {
    constexpr char pattern[] = "[!abc]";

    constexpr char seq1[] = "";
    constexpr char seq2[] = "a";
    constexpr char seq3[] = "b";
    constexpr char seq4[] = "c";
    constexpr char seq5[] = "d";

    static_assert(!match_enum(cx::begin(seq1), cx::end(seq1), cx::begin(pattern), cx::end(pattern)),
                  "");
    static_assert(!match_enum(cx::begin(seq2), cx::end(seq2), cx::begin(pattern), cx::end(pattern)),
                  "");
    static_assert(!match_enum(cx::begin(seq3), cx::end(seq3), cx::begin(pattern), cx::end(pattern)),
                  "");
    static_assert(!match_enum(cx::begin(seq4), cx::end(seq4), cx::begin(pattern), cx::end(pattern)),
                  "");
    static_assert(match_enum(cx::begin(seq5), cx::end(seq5), cx::begin(pattern), cx::end(pattern)),
                  "");
  }

  SECTION("")
  {
    constexpr char pattern[] = "[!]]";

    constexpr char seq1[] = "";
    constexpr char seq2[] = "]";
    constexpr char seq3[] = "a";

    static_assert(!match_enum(cx::begin(seq1), cx::end(seq1), cx::begin(pattern), cx::end(pattern)),
                  "");
    static_assert(!match_enum(cx::begin(seq2), cx::end(seq2), cx::begin(pattern), cx::end(pattern)),
                  "");
    static_assert(match_enum(cx::begin(seq3), cx::end(seq3), cx::begin(pattern), cx::end(pattern)),
                  "");
  }

  SECTION("")
  {
    constexpr char pattern[] = "[!]abc]";

    constexpr char seq1[] = "";
    constexpr char seq2[] = "]";
    constexpr char seq3[] = "a";
    constexpr char seq4[] = "b";
    constexpr char seq5[] = "c";
    constexpr char seq6[] = "d";

    static_assert(!match_enum(cx::begin(seq1), cx::end(seq1), cx::begin(pattern), cx::end(pattern)),
                  "");
    static_assert(!match_enum(cx::begin(seq2), cx::end(seq2), cx::begin(pattern), cx::end(pattern)),
                  "");
    static_assert(!match_enum(cx::begin(seq3), cx::end(seq3), cx::begin(pattern), cx::end(pattern)),
                  "");
    static_assert(!match_enum(cx::begin(seq4), cx::end(seq4), cx::begin(pattern), cx::end(pattern)),
                  "");
    static_assert(!match_enum(cx::begin(seq5), cx::end(seq5), cx::begin(pattern), cx::end(pattern)),
                  "");
    static_assert(match_enum(cx::begin(seq6), cx::end(seq6), cx::begin(pattern), cx::end(pattern)),
                  "");
  }
}

TEST_CASE("wildcards::match() is compliant", "[wildcards::match]")
{
  using wildcards::match;

  SECTION("match with an empty pattern")
  {
    constexpr char pattern1[] = "";
    constexpr char pattern2[] = R"(\)";

    static_assert(match("", pattern1), "");
    static_assert(match("", pattern2), "");

    static_assert(!match("Anything", pattern1), "");
    static_assert(!match("Anything", pattern2), "");
  }

  SECTION(R"(match with "A")")
  {
    constexpr char pattern1[] = "A";
    constexpr char pattern2[] = R"(A\)";
    constexpr char pattern3[] = R"(\A)";
    constexpr char pattern4[] = "[A]";

    static_assert(match("A", pattern1), "");
    static_assert(match("A", pattern2), "");
    static_assert(match("A", pattern3), "");
    static_assert(match("A", pattern4), "");

    static_assert(!match("", pattern1), "");
    static_assert(!match("", pattern2), "");
    static_assert(!match("", pattern3), "");
    static_assert(!match("", pattern4), "");

    static_assert(!match("a", pattern1), "");
    static_assert(!match("a", pattern2), "");
    static_assert(!match("a", pattern3), "");
    static_assert(!match("a", pattern4), "");

    static_assert(!match("AA", pattern1), "");
    static_assert(!match("AA", pattern2), "");
    static_assert(!match("AA", pattern3), "");
    static_assert(!match("AA", pattern4), "");

    static_assert(!match("Something", pattern1), "");
    static_assert(!match("Something", pattern2), "");
    static_assert(!match("Something", pattern3), "");
    static_assert(!match("Something", pattern4), "");
  }

  SECTION(R"(match with "Hello!")")
  {
    constexpr char pattern1[] = "Hello!";
    constexpr char pattern2[] = R"(Hello!\)";
    constexpr char pattern3[] = R"(\H\e\l\l\o\!)";
    constexpr char pattern4[] = "[H][e][l][l][o]!";

    static_assert(match("Hello!", pattern1), "");
    static_assert(match("Hello!", pattern2), "");
    static_assert(match("Hello!", pattern3), "");
    static_assert(match("Hello!", pattern4), "");

    static_assert(!match("", pattern1), "");
    static_assert(!match("", pattern2), "");
    static_assert(!match("", pattern3), "");
    static_assert(!match("", pattern4), "");

    static_assert(!match("Hallo!", pattern1), "");
    static_assert(!match("Hallo!", pattern2), "");
    static_assert(!match("Hallo!", pattern3), "");
    static_assert(!match("Hallo!", pattern4), "");

    static_assert(!match("HHello!", pattern1), "");
    static_assert(!match("HHello!", pattern2), "");
    static_assert(!match("HHello!", pattern3), "");
    static_assert(!match("HHello!", pattern4), "");

    static_assert(!match("Hello!!", pattern1), "");
    static_assert(!match("Hello!!", pattern2), "");
    static_assert(!match("Hello!!", pattern3), "");
    static_assert(!match("Hello!!", pattern4), "");

    static_assert(!match("Hello!Hello!", pattern1), "");
    static_assert(!match("Hello!Hello!", pattern2), "");
    static_assert(!match("Hello!Hello!", pattern3), "");
    static_assert(!match("Hello!Hello!", pattern4), "");
  }

  SECTION(R"(match with "*")")
  {
    constexpr char pattern1[] = "*";
    constexpr char pattern2[] = R"(*\)";
    constexpr char pattern3[] = R"(\*)";
    constexpr char pattern4[] = "[*]";

    static_assert(match("", pattern1), "");
    static_assert(match("", pattern2), "");
    static_assert(!match("", pattern3), "");
    static_assert(!match("", pattern4), "");

    static_assert(match("*", pattern1), "");
    static_assert(match("*", pattern2), "");
    static_assert(match("*", pattern3), "");
    static_assert(match("*", pattern4), "");

    static_assert(match("Anything", pattern1), "");
    static_assert(match("Anything", pattern2), "");
    static_assert(!match("Anything", pattern3), "");
    static_assert(!match("Anything", pattern4), "");
  }

  SECTION(R"(match with "?")")
  {
    constexpr char pattern1[] = "?";
    constexpr char pattern2[] = R"(?\)";
    constexpr char pattern3[] = R"(\?)";
    constexpr char pattern4[] = "[?]";

    static_assert(match("A", pattern1), "");
    static_assert(match("A", pattern2), "");
    static_assert(!match("A", pattern3), "");
    static_assert(!match("A", pattern4), "");

    static_assert(match("a", pattern1), "");
    static_assert(match("a", pattern2), "");
    static_assert(!match("a", pattern3), "");
    static_assert(!match("a", pattern4), "");

    static_assert(match("?", pattern1), "");
    static_assert(match("?", pattern2), "");
    static_assert(match("?", pattern3), "");
    static_assert(match("?", pattern4), "");

    static_assert(!match("", pattern1), "");
    static_assert(!match("", pattern2), "");
    static_assert(!match("", pattern3), "");
    static_assert(!match("", pattern4), "");

    static_assert(!match("Something", pattern1), "");
    static_assert(!match("Something", pattern2), "");
    static_assert(!match("Something", pattern3), "");
    static_assert(!match("Something", pattern4), "");
  }

  SECTION(R"(match with "H?llo,*W*!")")
  {
    constexpr char pattern[] = "H?llo,*W*!";

    static_assert(match("Hello, World!", pattern), "");
    static_assert(match("Hallo, World!", pattern), "");
    static_assert(match("Hallo,World!", pattern), "");
    static_assert(match("Hallo,WildCards!", pattern), "");
    static_assert(match("Hallo, crazy WildCards!", pattern), "");
    static_assert(match("Hallo, crazy WildCards! Still working?!", pattern), "");

    static_assert(!match("", pattern), "");
    static_assert(!match("Hllo, World!", pattern), "");
    static_assert(!match("Hello, World?", pattern), "");
    static_assert(!match("Hello, world!", pattern), "");
    static_assert(!match("Yes. Hello, World!", pattern), "");
    static_assert(!match("Hello, World!?", pattern), "");
  }

  SECTION(R"zzz(match with R"(\\\* *\? \*\\)")zzz")
  {
    constexpr char pattern1[] = R"(\\\* *\? \*\\)";
    constexpr char pattern2[] = R"([\][*] *[?] [*][\])";

    static_assert(match(R"(\* Hello? *\)", pattern1), "");
    static_assert(match(R"(\* Hello? *\)", pattern2), "");

    static_assert(match(R"(\* Hi? *\)", pattern1), "");
    static_assert(match(R"(\* Hi? *\)", pattern2), "");

    static_assert(match(R"(\* ? *\)", pattern1), "");
    static_assert(match(R"(\* ? *\)", pattern2), "");

    static_assert(!match(R"(\* Hello! *\)", pattern1), "");
    static_assert(!match(R"(\* Hello! *\)", pattern2), "");

    static_assert(!match(R"(* Hello? *\)", pattern1), "");
    static_assert(!match(R"(* Hello? *\)", pattern2), "");

    static_assert(!match(R"(\ Hello? *\)", pattern1), "");
    static_assert(!match(R"(\ Hello? *\)", pattern2), "");

    static_assert(!match(R"( Hello? *\)", pattern1), "");
    static_assert(!match(R"( Hello? *\)", pattern2), "");
  }

  SECTION(R"(match with u"H?llo,*W*!")")
  {
    constexpr char16_t pattern[] = u"H?llo,*W*!";

    static_assert(match(u"Hello, World!", pattern), "");
  }

  SECTION(R"(match with U"H?llo,*W*!")")
  {
    constexpr char32_t pattern[] = U"H?llo,*W*!";

    static_assert(match(U"Hello, World!", pattern), "");
  }

  SECTION(R"(match with L"H?llo,*W*!")")
  {
    constexpr wchar_t pattern[] = L"H?llo,*W*!";

    static_assert(match(L"Hello, World!", pattern), "");
  }

  SECTION(R"(match with "H_llo,%W%!")")
  {
    constexpr char pattern[] = "H_llo,%W%!";

    static_assert(match("Hello, World!", pattern, {'%', '_', '\\'}), "");
  }

  SECTION(R"(match with "H?llo,*W*!"_sv)")
  {
    using namespace cx::literals;

    constexpr auto pattern = "H?llo,*W*!"_sv;

    static_assert(match("Hello, World!"_sv, pattern), "");
  }

  SECTION(R"(match with u"H?llo,*W*!"_sv)")
  {
    using namespace cx::literals;

    constexpr auto pattern = u"H?llo,*W*!"_sv;

    static_assert(match(u"Hello, World!"_sv, pattern), "");
  }

  SECTION(R"(match with U"H?llo,*W*!"_sv)")
  {
    using namespace cx::literals;

    constexpr auto pattern = U"H?llo,*W*!"_sv;

    static_assert(match(U"Hello, World!"_sv, pattern), "");
  }

  SECTION(R"(match with L"H?llo,*W*!"_sv)")
  {
    using namespace cx::literals;

    constexpr auto pattern = L"H?llo,*W*!"_sv;

    static_assert(match(L"Hello, World!"_sv, pattern), "");
  }

  SECTION(R"(match with "H_llo,%W%!"_sv)")
  {
    using namespace cx::literals;

    constexpr auto pattern = "H_llo,%W%!"_sv;

    static_assert(match("Hello, World!"_sv, pattern, {'%', '_', '\\'}), "");
  }

  SECTION(R"(match with "11*7?"_sv)")
  {
    struct equal_to
    {
      constexpr bool operator()(int n, char c) const
      {
        return n + 48 == c;
      }
    };

    using namespace cx::literals;

    constexpr auto pattern = "11*7?"_sv;

#if defined(_MSC_VER) && _MSC_VER <= 1900  // VS2015
    REQUIRE(match(cx::array<int, 6>{{1, 1, 3, 5, 7, 9}}, pattern, equal_to()));
#else
    static_assert(match(cx::array<int, 6>{{1, 1, 3, 5, 7, 9}}, pattern, equal_to()), "");
#endif
  }

  SECTION(R"(match with "11%7_"_sv)")
  {
    struct equal_to
    {
      constexpr bool operator()(int n, char c) const
      {
        return n + 48 == c;
      }
    };

    using namespace cx::literals;

    constexpr auto pattern = "11%7_"_sv;

#if defined(_MSC_VER) && _MSC_VER <= 1900  // VS2015
    REQUIRE(match(cx::array<int, 6>{{1, 1, 3, 5, 7, 9}}, pattern, {'%', '_', '\\'}, equal_to()));
#else
    static_assert(
        match(cx::array<int, 6>{{1, 1, 3, 5, 7, 9}}, pattern, {'%', '_', '\\'}, equal_to()), "");
#endif
  }

  SECTION("")
  {
    static_assert(match("aaa", "a[abc]a"), "");
    static_assert(!match("aaa", "a[bcd]a"), "");
    static_assert(!match("aaa", "a[a]]a"), "");
    static_assert(match("aa]a", "a[a]]a"), "");
    static_assert(match("aaa", "a[]abc]a"), "");
    static_assert(match("aaa", "a[[a]a"), "");
    static_assert(match("a[a", "a[[a]a"), "");
    static_assert(match("a]a", "a[]]a"), "");
    static_assert(!match("aa", "a[]a"), "");
    static_assert(match("a[]a", "a[]a"), "");

    static_assert(!match("aaa", "a[!a]a"), "");
    static_assert(match("aaa", "a[!b]a"), "");
    static_assert(!match("aaa", "a[b!b]a"), "");
    static_assert(match("a!a", "a[b!b]a"), "");
    static_assert(!match("a!a", "a[!]a"), "");
    static_assert(match("a[!]a", "a[!]a"), "");
  }
}
