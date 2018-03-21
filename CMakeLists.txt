cmake_minimum_required(VERSION 3.5)

project(WildCards VERSION 0.0.1 LANGUAGES CXX)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${PROJECT_SOURCE_DIR}/cmake)

option(WILDCARDS_BUILD_TESTS "Build unit tests" OFF)
option(WILDCARDS_ENABLE_WERROR "Enable all warnings as errors" OFF)

if(WILDCARDS_BUILD_TESTS)
  include(CTest)

  add_subdirectory(test)
endif()

if(CLANGFORMAT)
  include(ClangFormat)

  file(GLOB_RECURSE clangformat_srcs include/wildcards/*.hpp)

  clangformat_setup("${clangformat_srcs}")
endif()
