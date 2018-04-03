// Copyright Tomas Zeman 2018.
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef CX_STRING_HPP
#define CX_STRING_HPP

#include <cstddef>

#include <cx/algorithm.hpp>

namespace cx
{

template <typename T>
class basic_string
{
 public:
  using value_type = T;

  constexpr basic_string() = default;

  template <std::size_t N>
  constexpr basic_string(const T (&str)[N]) : m_data{&str[0]}, m_size{N - 1}
  {
  }

  constexpr basic_string(const T* str, std::size_t s) : m_data{str}, m_size{s}
  {
  }

  constexpr const T* c_str() const
  {
    return m_data;
  }

  constexpr std::size_t size() const
  {
    return m_size;
  }

  constexpr const T* begin() const
  {
    return m_data;
  }

  constexpr const T* end() const
  {
    return m_data + m_size;
  }

 private:
  const T* m_data{nullptr};
  std::size_t m_size{0};
};

template <typename T, typename U>
constexpr bool operator==(const basic_string<T>& lhs, const basic_string<U>& rhs)
{
  return equal(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
}

template <typename T, typename U>
constexpr bool operator!=(const basic_string<T>& lhs, const basic_string<U>& rhs)
{
  return !(lhs == rhs);
}

template <typename T, std::size_t N>
constexpr basic_string<T> make_string(const T (&str)[N])
{
  return basic_string<T>{str, N - 1};
}

template <typename T>
constexpr basic_string<T> make_string(const T* str, std::size_t s)
{
  return basic_string<T>{str, s};
}

using string = basic_string<char>;
using u16string = basic_string<char16_t>;
using u32string = basic_string<char32_t>;
using wstring = basic_string<wchar_t>;

namespace literals
{

constexpr string operator"" _cs(const char* str, std::size_t s)
{
  return string{str, s};
}

constexpr u16string operator"" _cs(const char16_t* str, std::size_t s)
{
  return u16string{str, s};
}

constexpr u32string operator"" _cs(const char32_t* str, std::size_t s)
{
  return u32string{str, s};
}

constexpr wstring operator"" _cs(const wchar_t* str, std::size_t s)
{
  return wstring{str, s};
}

}  // namespace literals

}  // namespace cx

#endif  // CX_STRING_HPP
