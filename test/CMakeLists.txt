project(Test)

add_executable(selftest src/cx/array_test.cpp
                        src/cx/string_view_test.cpp
                        src/cx/tuple_test.cpp
                        src/cx/utility_test.cpp
                        src/wildcards/wildcards_test.cpp
                        src/catch.cpp)
target_include_directories(selftest PRIVATE ../include include)

if(WILDCARDS_USE_CXX_17)
  message(STATUS "Enabling C++17 for tests")
  set_target_properties(selftest PROPERTIES CXX_STANDARD 17)
elseif(WILDCARDS_USE_CXX_14)
  message(STATUS "Enabling C++14 for tests")
  set_target_properties(selftest PROPERTIES CXX_STANDARD 14)
else()
  set_target_properties(selftest PROPERTIES CXX_STANDARD 11)
endif()

set_target_properties(selftest PROPERTIES CXX_STANDARD_REQUIRED ON
                                          CXX_EXTENSIONS OFF)

if(CMAKE_CXX_COMPILER_ID MATCHES "Clang|AppleClang|GNU")
  target_compile_options(selftest PRIVATE -Wall
                                          -Wextra
                                          -Wpedantic
                                          -Wconversion
                                          -Wsign-conversion
                                          -Wsign-promo -Wdouble-promotion)

  if(WILDCARDS_ENABLE_WERROR)
    target_compile_options(selftest PRIVATE -Werror)
  endif()

  if(CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  endif()
elseif(CMAKE_CXX_COMPILER_ID MATCHES "MSVC")
  target_compile_options(selftest PRIVATE /W4)

  if(WILDCARDS_ENABLE_WERROR)
    target_compile_options(selftest PRIVATE /WX)
  endif()
endif()

add_test(NAME SelfTest COMMAND selftest)

if(CLANGFORMAT)
  include(ClangFormat)

  file(GLOB_RECURSE clangformat_srcs include/cx/*.hpp
                                     include/wildcards/*.hpp
                                     src/cx/*.cpp
                                     src/wildcards/*.cpp)

  clangformat_setup("${clangformat_srcs}")
endif()
