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
  SECTION("match with an empty pattern")
  {
    constexpr char pattern1[] = "";
    constexpr char pattern2[] = R"(\)";

    static_assert(wildcards::match("", pattern1), "");
    static_assert(wildcards::match("", pattern2), "");

    static_assert(!wildcards::match("Anything", pattern1), "");
    static_assert(!wildcards::match("Anything", pattern2), "");
  }

  SECTION(R"(match with "A")")
  {
    constexpr char pattern1[] = "A";
    constexpr char pattern2[] = R"(A\)";
    constexpr char pattern3[] = R"(\A)";

    static_assert(wildcards::match("A", pattern1), "");
    static_assert(wildcards::match("A", pattern2), "");
    static_assert(wildcards::match("A", pattern3), "");

    static_assert(!wildcards::match("", pattern1), "");
    static_assert(!wildcards::match("", pattern2), "");
    static_assert(!wildcards::match("", pattern3), "");

    static_assert(!wildcards::match("a", pattern1), "");
    static_assert(!wildcards::match("a", pattern2), "");
    static_assert(!wildcards::match("a", pattern3), "");

    static_assert(!wildcards::match("AA", pattern1), "");
    static_assert(!wildcards::match("AA", pattern2), "");
    static_assert(!wildcards::match("AA", pattern3), "");

    static_assert(!wildcards::match("Something", pattern1), "");
    static_assert(!wildcards::match("Something", pattern2), "");
    static_assert(!wildcards::match("Something", pattern3), "");
  }

  SECTION(R"(match with "Hallo!")")
  {
    constexpr char pattern1[] = "Hallo!";
    constexpr char pattern2[] = R"(Hallo!\)";
    constexpr char pattern3[] = R"(\H\a\l\l\o\!)";

    static_assert(wildcards::match("Hallo!", pattern1), "");
    static_assert(wildcards::match("Hallo!", pattern2), "");
    static_assert(wildcards::match("Hallo!", pattern3), "");

    static_assert(!wildcards::match("", pattern1), "");
    static_assert(!wildcards::match("", pattern2), "");
    static_assert(!wildcards::match("", pattern3), "");

    static_assert(!wildcards::match("Hello!", pattern1), "");
    static_assert(!wildcards::match("Hello!", pattern2), "");
    static_assert(!wildcards::match("Hello!", pattern3), "");

    static_assert(!wildcards::match("HHallo!", pattern1), "");
    static_assert(!wildcards::match("HHallo!", pattern2), "");
    static_assert(!wildcards::match("HHallo!", pattern3), "");

    static_assert(!wildcards::match("Hallo!!", pattern1), "");
    static_assert(!wildcards::match("Hallo!!", pattern2), "");
    static_assert(!wildcards::match("Hallo!!", pattern3), "");

    static_assert(!wildcards::match("Hallo!Hallo!", pattern1), "");
    static_assert(!wildcards::match("Hallo!Hallo!", pattern2), "");
    static_assert(!wildcards::match("Hallo!Hallo!", pattern3), "");
  }

  SECTION(R"(match with "*")")
  {
    constexpr char pattern1[] = "*";
    constexpr char pattern2[] = R"(*\)";
    constexpr char pattern3[] = R"(\*)";

    static_assert(wildcards::match("", pattern1), "");
    static_assert(wildcards::match("", pattern2), "");
    static_assert(!wildcards::match("", pattern3), "");

    static_assert(wildcards::match("*", pattern1), "");
    static_assert(wildcards::match("*", pattern2), "");
    static_assert(wildcards::match("*", pattern3), "");

    static_assert(wildcards::match("Anything", pattern1), "");
    static_assert(wildcards::match("Anything", pattern2), "");
    static_assert(!wildcards::match("Anything", pattern3), "");
  }

  SECTION(R"(match with "?")")
  {
    constexpr char pattern1[] = "?";
    constexpr char pattern2[] = R"(?\)";
    constexpr char pattern3[] = R"(\?)";

    static_assert(wildcards::match("A", pattern1), "");
    static_assert(wildcards::match("A", pattern2), "");
    static_assert(!wildcards::match("A", pattern3), "");

    static_assert(wildcards::match("a", pattern1), "");
    static_assert(wildcards::match("a", pattern2), "");
    static_assert(!wildcards::match("a", pattern3), "");

    static_assert(wildcards::match("?", pattern1), "");
    static_assert(wildcards::match("?", pattern2), "");
    static_assert(wildcards::match("?", pattern3), "");

    static_assert(!wildcards::match("", pattern1), "");
    static_assert(!wildcards::match("", pattern2), "");
    static_assert(!wildcards::match("", pattern3), "");

    static_assert(!wildcards::match("Something", pattern1), "");
    static_assert(!wildcards::match("Something", pattern2), "");
    static_assert(!wildcards::match("Something", pattern3), "");
  }

  SECTION(R"(match with "H?llo,*W*!")")
  {
    constexpr char pattern[] = "H?llo,*W*!";

    static_assert(wildcards::match("Hallo, World!", pattern), "");
    static_assert(wildcards::match("Hello, World!", pattern), "");
    static_assert(wildcards::match("Hello,World!", pattern), "");
    static_assert(wildcards::match("Hello,WildCards!", pattern), "");
    static_assert(wildcards::match("Hello, crazy WildCards!", pattern), "");
    static_assert(wildcards::match("Hello, crazy WildCards! Still working?!", pattern), "");

    static_assert(!wildcards::match("", pattern), "");
    static_assert(!wildcards::match("Hllo, World!", pattern), "");
    static_assert(!wildcards::match("Hallo, World?", pattern), "");
    static_assert(!wildcards::match("Hallo, world!", pattern), "");
    static_assert(!wildcards::match("Yes. Hallo, World!", pattern), "");
    static_assert(!wildcards::match("Hallo, World!?", pattern), "");
  }

  SECTION(R"zzz(match with R"(\\\* *\? \*\\)")zzz")
  {
    constexpr char pattern[] = R"(\\\* *\? \*\\)";

    static_assert(wildcards::match(R"(\* Hallo? *\)", pattern), "");
    static_assert(wildcards::match(R"(\* Hi? *\)", pattern), "");
    static_assert(wildcards::match(R"(\* ? *\)", pattern), "");

    static_assert(!wildcards::match(R"(\* Hallo! *\)", pattern), "");
    static_assert(!wildcards::match(R"(* Hallo? *\)", pattern), "");
    static_assert(!wildcards::match(R"(\ Hallo? *\)", pattern), "");
    static_assert(!wildcards::match(R"( Hallo? *\)", pattern), "");
  }

  SECTION(R"(match with u"H?llo,*W*!")")
  {
    constexpr char16_t pattern[] = u"H?llo,*W*!";

    static_assert(wildcards::match(u"Hallo, World!", pattern), "");
  }

  SECTION(R"(match with U"H?llo,*W*!")")
  {
    constexpr char32_t pattern[] = U"H?llo,*W*!";

    static_assert(wildcards::match(U"Hallo, World!", pattern), "");
  }

  SECTION(R"(match with L"H?llo,*W*!")")
  {
    constexpr wchar_t pattern[] = L"H?llo,*W*!";

    static_assert(wildcards::match(L"Hallo, World!", pattern), "");
  }

  SECTION(R"(match with "H_llo,%W%!")")
  {
    constexpr char pattern[] = "H_llo,%W%!";

    static_assert(wildcards::match("Hallo, World!", pattern, {'%', '_', '\\', '[', ']', '!'}), "");
  }

  SECTION(R"(match with "H?llo,*W*!"_sv)")
  {
    using namespace cx::literals;

    constexpr auto pattern = "H?llo,*W*!"_sv;

    static_assert(wildcards::match("Hallo, World!"_sv, pattern), "");
  }

  SECTION(R"(match with u"H?llo,*W*!"_sv)")
  {
    using namespace cx::literals;

    constexpr auto pattern = u"H?llo,*W*!"_sv;

    static_assert(wildcards::match(u"Hallo, World!"_sv, pattern), "");
  }

  SECTION(R"(match with U"H?llo,*W*!"_sv)")
  {
    using namespace cx::literals;

    constexpr auto pattern = U"H?llo,*W*!"_sv;

    static_assert(wildcards::match(U"Hallo, World!"_sv, pattern), "");
  }

  SECTION(R"(match with L"H?llo,*W*!"_sv)")
  {
    using namespace cx::literals;

    constexpr auto pattern = L"H?llo,*W*!"_sv;

    static_assert(wildcards::match(L"Hallo, World!"_sv, pattern), "");
  }

  SECTION(R"(match with "H_llo,%W%!"_sv)")
  {
    using namespace cx::literals;

    constexpr auto pattern = "H_llo,%W%!"_sv;

    static_assert(wildcards::match("Hallo, World!"_sv, pattern, {'%', '_', '\\', '[', ']', '!'}),
                  "");
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
    REQUIRE(wildcards::match(cx::array<int, 6>{{1, 1, 3, 5, 7, 9}}, pattern, equal_to()));
#else
    static_assert(wildcards::match(cx::array<int, 6>{{1, 1, 3, 5, 7, 9}}, pattern, equal_to()), "");
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
    REQUIRE(wildcards::match(cx::array<int, 6>{{1, 1, 3, 5, 7, 9}}, pattern,
                             {'%', '_', '\\', '[', ']', '!'}, equal_to()));
#else
    static_assert(wildcards::match(cx::array<int, 6>{{1, 1, 3, 5, 7, 9}}, pattern,
                                   {'%', '_', '\\', '[', ']', '!'}, equal_to()),
                  "");
#endif
  }
}
