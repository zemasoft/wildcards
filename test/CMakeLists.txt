project(SelfTest)

add_executable(selftest src/wildcards/wildcards_test.cpp
                        src/catch.cpp)
target_include_directories(selftest PRIVATE ../include include)

set_target_properties(selftest PROPERTIES CXX_STANDARD 11
                                          CXX_STANDARD_REQUIRED ON
                                          CXX_EXTENSIONS OFF)

if(CMAKE_CXX_COMPILER_ID MATCHES "Clang|AppleClang|GNU")
  target_compile_options(selftest PRIVATE -Wall
                                          -Wextra
                                          -Wpedantic
                                          -Wconversion
                                          -Wsign-conversion
                                          -Wsign-promo -Wdouble-promotion
                                          $<$<CONFIG:Release>:-s>)

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

  file(GLOB_RECURSE clangformat_srcs include/wildcards/*.hpp src/wildcards/*.cpp)

  clangformat_setup("${clangformat_srcs}")
endif()
