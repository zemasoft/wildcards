project(Test)

add_executable(selftest src/cx/array_test.cpp
                        src/cx/string_view_test.cpp
                        src/cx/tuple_test.cpp
                        src/cx/utility_test.cpp
                        src/wildcards/match_test.cpp
                        src/catch.cpp)
target_include_directories(selftest PRIVATE ../include include)

if(WILDCARDS_CXX_STANDARD EQUAL 17)
  message(STATUS "Enabling C++17 for selftest")
elseif(WILDCARDS_CXX_STANDARD EQUAL 14)
  message(STATUS "Enabling C++14 for selftest")
endif()

set_target_properties(selftest PROPERTIES CXX_STANDARD ${WILDCARDS_CXX_STANDARD}
                                          CXX_STANDARD_REQUIRED ON
                                          CXX_EXTENSIONS OFF)

if(CMAKE_CXX_COMPILER_ID MATCHES "GNU|AppleClang|Clang")
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

  set(clangformat_srcs src/cx/array_test.cpp
                       src/cx/string_view_test.cpp
                       src/cx/tuple_test.cpp
                       src/cx/utility_test.cpp
                       src/wildcards/match_test.cpp)

  clangformat_setup("${clangformat_srcs}")
endif()
