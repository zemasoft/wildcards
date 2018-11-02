project(Example)

macro(add_example target file_name)
  add_executable(${target} ${file_name})
  target_include_directories(${target} PRIVATE ../include)

  if(WILDCARDS_CXX_STANDARD EQUAL 17)
    message(STATUS "Enabling C++17 for ${target}")
  elseif(WILDCARDS_CXX_STANDARD EQUAL 14)
    message(STATUS "Enabling C++14 for ${target}")
  endif()

  set_target_properties(${target} PROPERTIES CXX_STANDARD ${WILDCARDS_CXX_STANDARD}
                                             CXX_STANDARD_REQUIRED ON
                                             CXX_EXTENSIONS OFF)

  if(CMAKE_CXX_COMPILER_ID MATCHES "GNU|AppleClang|Clang")
    target_compile_options(${target} PRIVATE -Wall
                                             -Wextra
                                             -Wpedantic
                                             -Wconversion
                                             -Wsign-conversion
                                             -Wsign-promo -Wdouble-promotion)

    if(WILDCARDS_ENABLE_WERROR)
      target_compile_options(${target} PRIVATE -Werror)
    endif()

    if(CMAKE_CXX_COMPILER_ID MATCHES "Clang")
    endif()
  elseif(CMAKE_CXX_COMPILER_ID MATCHES "MSVC")
    target_compile_options(${target} PRIVATE /W4)

    if(WILDCARDS_ENABLE_WERROR)
      target_compile_options(${target} PRIVATE /WX)
    endif()
  endif()
endmacro()

add_example(example01 example01.cpp)
add_example(example02 example02.cpp)
add_example(example03 example03.cpp)
add_example(example04 example04.cpp)
if(WILDCARDS_CXX_STANDARD EQUAL 17 AND NOT CMAKE_CXX_COMPILER_ID MATCHES "AppleClang")
  add_example(example05 example05.cpp)
  if(CMAKE_CXX_COMPILER_ID MATCHES "GNU")
    target_link_libraries(example05 stdc++fs)
  elseif(CMAKE_CXX_COMPILER_ID MATCHES "Clang")
    target_link_libraries(example05 c++experimental)
  elseif(CMAKE_CXX_COMPILER_ID MATCHES "MSVC")
    # TODO?
  endif()
endif()
add_example(example06 example06.cpp)

if(CLANGFORMAT)
  include(ClangFormat)

  set(clangformat_srcs example01.cpp
                       example02.cpp
                       example03.cpp
                       example04.cpp
                       example05.cpp
                       example06.cpp)

  clangformat_setup("${clangformat_srcs}")
endif()
