cmake_minimum_required(VERSION 3.5)

project(WildCards VERSION 0.0.1 LANGUAGES CXX)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${PROJECT_SOURCE_DIR}/cmake)

option(WILDCARDS_BUILD_TESTS "Build unit tests" ON)
option(WILDCARDS_BUILD_EXAMPLES "Build examples" OFF)
option(WILDCARDS_ENABLE_WERROR "Enable all warnings as errors" ON)

option(WILDCARDS_USE_CXX_17 "Build using C++17" OFF)
option(WILDCARDS_USE_CXX_14 "Build using C++14" OFF)

if(WILDCARDS_BUILD_TESTS)
  include(CTest)

  add_subdirectory(test)
endif()

if(WILDCARDS_BUILD_EXAMPLES)
  add_subdirectory(example)
endif()

if(CLANGFORMAT)
  include(ClangFormat)

  set(clangformat_srcs include/config.hpp
                       include/cx/algorithm.hpp
                       include/cx/array.hpp
                       include/cx/iterator.hpp
                       include/cx/string_view.hpp
                       include/cx/tuple.hpp
                       include/cx/utility.hpp
                       include/wildcards/cards.hpp
                       include/wildcards/utility.hpp
                       include/wildcards/wildcards.hpp)

  clangformat_setup("${clangformat_srcs}")
endif()
