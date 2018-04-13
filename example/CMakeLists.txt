project(Example)

macro(add_example target file_name)
  add_executable(${target} ${file_name})
  target_include_directories(${target} PRIVATE ../include)

  if(WILDCARDS_USE_CXX_17)
    message(STATUS "Enabling C++17 for examples")
    set_target_properties(${target} PROPERTIES CXX_STANDARD 17)
  elseif(WILDCARDS_USE_CXX_14)
    message(STATUS "Enabling C++14 for examples")
    set_target_properties(${target} PROPERTIES CXX_STANDARD 14)
  else()
    set_target_properties(${target} PROPERTIES CXX_STANDARD 11)
  endif()

  set_target_properties(${target} PROPERTIES CXX_STANDARD_REQUIRED ON
                                             CXX_EXTENSIONS OFF)

  if(CMAKE_CXX_COMPILER_ID MATCHES "Clang|AppleClang|GNU")
    target_compile_options(${target} PRIVATE -Wall
                                             -Wextra
                                             -Wpedantic
                                             -Wconversion
                                             -Wsign-conversion
                                             -Wsign-promo -Wdouble-promotion
                                             $<$<CONFIG:Release>:-s>)

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

if(CLANGFORMAT)
  include(ClangFormat)

  file(GLOB_RECURSE clangformat_srcs *.cpp)

  clangformat_setup("${clangformat_srcs}")
endif()
