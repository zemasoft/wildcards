// Copyright Tomas Zeman 2018.
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#include "wildcards/match.hpp"  // wildcards::match

int main()
{
  constexpr char pattern[] = "Hallo,* World?";

  static_assert(wildcards::match("Hallo, World!", pattern), "");
  static_assert(wildcards::match("Hallo, World?", pattern), "");
  static_assert(wildcards::match("Hallo, dear World!", pattern), "");

  static_assert(!wildcards::match("Hallo World!", pattern), "");
  static_assert(!wildcards::match("Hallo,World!", pattern), "");
  static_assert(!wildcards::match("Hallo, world!", pattern), "");
  static_assert(!wildcards::match("Hallo, World", pattern), "");

  return 0;
}
