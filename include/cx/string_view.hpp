// Copyright Tomas Zeman 2018.
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef CX_STRING_VIEW_HPP
#define CX_STRING_VIEW_HPP

#include <cstddef>  // std::size_t

#include <cx/algorithm.hpp>  // cx::equal

namespace cx
{

template <typename T>
class basic_string_view
{
 public:
  using value_type = T;

  constexpr basic_string_view() = default;

  template <std::size_t N>
  constexpr basic_string_view(const T (&str)[N]) : data_{&str[0]}, size_{N - 1}
  {
  }

  constexpr basic_string_view(const T* str, std::size_t s) : data_{str}, size_{s}
  {
  }

  constexpr const T* data() const
  {
    return data_;
  }

  constexpr std::size_t size() const
  {
    return size_;
  }

  constexpr const T* begin() const
  {
    return data_;
  }

  constexpr const T* end() const
  {
    return data_ + size_;
  }

 private:
  const T* data_{nullptr};
  std::size_t size_{0};
};

template <typename T, typename U>
constexpr bool operator==(const basic_string_view<T>& lhs, const basic_string_view<U>& rhs)
{
  return equal(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
}

template <typename T, typename U>
constexpr bool operator!=(const basic_string_view<T>& lhs, const basic_string_view<U>& rhs)
{
  return !(lhs == rhs);
}

template <typename T, std::size_t N>
constexpr basic_string_view<T> make_string_view(const T (&str)[N])
{
  return basic_string_view<T>{str, N - 1};
}

template <typename T>
constexpr basic_string_view<T> make_string_view(const T* str, std::size_t s)
{
  return basic_string_view<T>{str, s};
}

using string_view = basic_string_view<char>;
using u16string_view = basic_string_view<char16_t>;
using u32string_view = basic_string_view<char32_t>;
using wstring_view = basic_string_view<wchar_t>;

namespace literals
{

constexpr string_view operator"" _sv(const char* str, std::size_t s)
{
  return string_view{str, s};
}

constexpr u16string_view operator"" _sv(const char16_t* str, std::size_t s)
{
  return u16string_view{str, s};
}

constexpr u32string_view operator"" _sv(const char32_t* str, std::size_t s)
{
  return u32string_view{str, s};
}

constexpr wstring_view operator"" _sv(const wchar_t* str, std::size_t s)
{
  return wstring_view{str, s};
}

}  // namespace literals

}  // namespace cx

#endif  // CX_STRING_VIEW_HPP
