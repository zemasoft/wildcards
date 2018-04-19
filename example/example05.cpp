// Copyright Tomas Zeman 2018.
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#include <cstring>
#include <iostream>

// clang-format off
#ifdef __has_include
# if __has_include(<filesystem>)
#   include <filesystem>
    namespace fs = std::filesystem;
# elif __has_include(<experimental/filesystem>)
#   include <experimental/filesystem>
    namespace fs = std::experimental::filesystem;
# elif __has_include(<boost/filesystem.hpp>)
#   include <boost/filesystem.hpp>
    namespace fs = boost::filesystem;
# else
#   error "Missing <filesystem>"
# endif
#endif
// clang-format on

#include "cx/string_view.hpp"
#include "wildcards/match.hpp"

int main(int argc, char** argv)
{
  if (argc <= 1)
  {
    std::cout << "usage: " << argv[0] << " path pattern" << std::endl;
    return EXIT_SUCCESS;
  }

  if (argc != 3)
  {
    std::cerr << "invalid arguments" << std::endl;
    return EXIT_FAILURE;
  }

  auto path = cx::make_string_view(argv[1], std::strlen(argv[1]));
  auto pattern = cx::make_string_view(argv[2], std::strlen(argv[2]));

  for (auto& p : fs::directory_iterator(path.data()))
  {
    if (wildcards::match(p.path().string(), pattern))
    {
      std::cout << p.path().string() << std::endl;
    }
  }

  return EXIT_SUCCESS;
}
