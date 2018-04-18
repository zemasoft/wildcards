// Copyright Tomas Zeman 2018.
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#include <iostream>
#include <stdexcept>

#include "cx/string_view.hpp"
#include "wildcards/match.hpp"

template <typename T>
struct valid_id_pattern;

template <>
struct valid_id_pattern<char>
{
  constexpr static cx::string_view value = "test_*";
};

template <>
struct valid_id_pattern<char16_t>
{
  constexpr static cx::u16string_view value = u"test_*";
};

template <>
struct valid_id_pattern<char32_t>
{
  constexpr static cx::u32string_view value = U"test_*";
};

template <>
struct valid_id_pattern<wchar_t>
{
  constexpr static cx::wstring_view value = L"test_*";
};

template <typename T>
constexpr cx::basic_string_view<T> basic_valid_id(cx::basic_string_view<T> s)
{
  return wildcards::match(s, valid_id_pattern<T>::value) ? s
                                                         : throw std::logic_error("ID is invalid");
}

constexpr cx::string_view valid_id(cx::string_view s)
{
  return basic_valid_id<char>(s);
}

constexpr cx::u16string_view valid_id(cx::u16string_view s)
{
  return basic_valid_id<char16_t>(s);
}

constexpr cx::u32string_view valid_id(cx::u32string_view s)
{
  return basic_valid_id<char32_t>(s);
}

constexpr cx::wstring_view valid_id(cx::wstring_view s)
{
  return basic_valid_id<wchar_t>(s);
}

constexpr cx::string_view operator"" _valid_id(const char* str, std::size_t s)
{
  return valid_id(cx::make_string_view(str, s));
}

constexpr cx::u16string_view operator"" _valid_id(const char16_t* str, std::size_t s)
{
  return valid_id(cx::make_string_view(str, s));
}

constexpr cx::u32string_view operator"" _valid_id(const char32_t* str, std::size_t s)
{
  return valid_id(cx::make_string_view(str, s));
}

constexpr cx::wstring_view operator"" _valid_id(const wchar_t* str, std::size_t s)
{
  return valid_id(cx::make_string_view(str, s));
}

int main()
{
  constexpr auto id1 = valid_id("test_ok");
  constexpr auto id2 = "test_ok"_valid_id;

  std::cout << "valid ID: " << id1 << std::endl;
  std::cout << "valid ID: " << id2 << std::endl;

  return EXIT_SUCCESS;
}
