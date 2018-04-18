// Copyright Tomas Zeman 2018.
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#include <cstring>
#include <iostream>

#include "cx/string_view.hpp"
#include "wildcards/match.hpp"

int main(int argc, char** argv)
{
  if (argc <= 1)
  {
    std::cout << "usage: " << argv[0] << " string pattern" << std::endl;
    return EXIT_SUCCESS;
  }

  if (argc != 3)
  {
    std::cerr << "invalid arguments" << std::endl;
    return EXIT_FAILURE;
  }

  auto string = cx::make_string_view(argv[1], std::strlen(argv[1]));
  auto pattern = cx::make_string_view(argv[2], std::strlen(argv[2]));

  if (!wildcards::match(string, pattern))
  {
    return EXIT_FAILURE;
  }

  return EXIT_SUCCESS;
}
