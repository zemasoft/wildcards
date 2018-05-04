// Copyright Tomas Zeman 2018.
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#include "wildcards/match.hpp"

int main()
{
  constexpr char pattern[] = "H?llo,* World[.!?]";

  static_assert(wildcards::match("Hello, World!", pattern), "");
  static_assert(wildcards::match("Hallo, World!", pattern), "");
  static_assert(wildcards::match("Hello, big World!", pattern), "");
  static_assert(wildcards::match("Hello, World.", pattern), "");
  static_assert(wildcards::match("Hello, World?", pattern), "");

  static_assert(!wildcards::match("Hllo World!", pattern), "");
  static_assert(!wildcards::match("Hello World!", pattern), "");
  static_assert(!wildcards::match("Hello,World!", pattern), "");
  static_assert(!wildcards::match("Hello, world!", pattern), "");
  static_assert(!wildcards::match("Hello, World", pattern), "");
  static_assert(!wildcards::match("Hello, World;", pattern), "");
  static_assert(!wildcards::match("Hello, World!!", pattern), "");

  return 0;
}
