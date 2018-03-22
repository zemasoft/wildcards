// Copyright Tomas Zeman 2018.
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef WILDCARDS_WILDCARDS_HPP
#define WILDCARDS_WILDCARDS_HPP

#include <iterator>     // std::begin, std::end, std::next
#include <type_traits>  // std::remove_cv, std::remove_reference
#include <utility>      // std::declval, std::forward, std::get, std::pair

namespace wildcards
{

template <typename T>
struct cards;

template <>
struct cards<char> : public std::pair<char, char>
{
  constexpr cards() : std::pair<char, char>{'*', '?'}
  {
  }
};

template <>
struct cards<char16_t> : public std::pair<char16_t, char16_t>
{
  constexpr cards() : std::pair<char16_t, char16_t>{u'*', u'?'}
  {
  }
};

template <>
struct cards<char32_t> : public std::pair<char32_t, char32_t>
{
  constexpr cards() : std::pair<char32_t, char32_t>{U'*', U'?'}
  {
  }
};

template <>
struct cards<wchar_t> : public std::pair<wchar_t, wchar_t>
{
  constexpr cards() : std::pair<wchar_t, wchar_t>{L'*', L'?'}
  {
  }
};

template <typename T, typename U>
struct equal
{
  constexpr bool operator()(const T& lhs, const U& rhs) const
  {
    return lhs == rhs;
  }
};

namespace detail
{

// constexpr since C++17
template <typename C>
constexpr auto begin(C& c) noexcept(noexcept(std::begin(c))) -> decltype(std::begin(c))
{
  return std::begin(c);
}

// constexpr since C++17
template <typename C>
constexpr auto begin(const C& c) noexcept(noexcept(std::begin(c))) -> decltype(std::begin(c))
{
  return std::begin(c);
}

// constexpr since C++14
template <typename T, std::size_t N>
constexpr T* begin(T (&array)[N]) noexcept
{
  return array;
}

constexpr char* begin(char& c) noexcept
{
  return &c;
}

constexpr const char* begin(const char& c) noexcept
{
  return &c;
}

constexpr char16_t* begin(char16_t& c) noexcept
{
  return &c;
}

constexpr const char16_t* begin(const char16_t& c) noexcept
{
  return &c;
}

constexpr char32_t* begin(char32_t& c) noexcept
{
  return &c;
}

constexpr const char32_t* begin(const char32_t& c) noexcept
{
  return &c;
}

constexpr wchar_t* begin(wchar_t& c) noexcept
{
  return &c;
}

constexpr const wchar_t* begin(const wchar_t& c) noexcept
{
  return &c;
}

// constexpr since C++17
template <typename C>
constexpr auto end(C& c) noexcept(noexcept(std::end(c))) -> decltype(std::end(c))
{
  return std::end(c);
}

// constexpr since C++17
template <typename C>
constexpr auto end(const C& c) noexcept(noexcept(std::end(c))) -> decltype(std::end(c))
{
  return std::end(c);
}

// constexpr since C++14
template <typename T, std::size_t N>
constexpr T* end(T (&array)[N]) noexcept
{
  return array + N;
}

constexpr char* end(char& c) noexcept
{
  return &c + 1;
}

constexpr const char* end(const char& c) noexcept
{
  return &c + 1;
}

constexpr char16_t* end(char16_t& c) noexcept
{
  return &c + 1;
}

constexpr const char16_t* end(const char16_t& c) noexcept
{
  return &c + 1;
}

constexpr char32_t* end(char32_t& c) noexcept
{
  return &c + 1;
}

constexpr const char32_t* end(const char32_t& c) noexcept
{
  return &c + 1;
}

constexpr wchar_t* end(wchar_t& c) noexcept
{
  return &c + 1;
}

constexpr const wchar_t* end(const wchar_t& c) noexcept
{
  return &c + 1;
}

template <typename C>
using value_type = typename std::remove_cv<
    typename std::remove_reference<decltype(*detail::begin(std::declval<C>()))>::type>::type;

template <typename SequenceIterator, typename PatternIterator, typename Cards, typename Equal>
/*constexpr*/ bool match(SequenceIterator s, SequenceIterator send, PatternIterator p,
                         PatternIterator pend, const Cards& cards, const Equal& equal)
{
  if (*p != std::get<0>(cards))
  {
    if (s != send)
    {
      if (*p == std::get<1>(cards) || equal(*s, *p))
      {
        return match(std::next(s), send, std::next(p), pend, cards, equal);
      }

      return false;
    }

    return p == pend;
  }

  return match(s, send, std::next(p), pend, cards, equal) ||
         ((s != send) && match(std::next(s), send, p, pend, cards, equal));
}

}  // namespace detail

template <typename Sequence, typename Pattern, typename Cards = cards<detail::value_type<Pattern>>,
          typename Equal = equal<detail::value_type<Sequence>, detail::value_type<Pattern>>>
/*constexpr*/ bool match(Sequence&& sequence, Pattern&& pattern, Cards&& cards = Cards(),
                         Equal&& equal = Equal())
{
  return detail::match(detail::begin(std::forward<Sequence>(sequence)),
                       detail::end(std::forward<Sequence>(sequence)),
                       detail::begin(std::forward<Pattern>(pattern)),
                       detail::end(std::forward<Pattern>(pattern)), std::forward<Cards>(cards),
                       std::forward<Equal>(equal));
}

}  // namespace wildcards

#endif  // WILDCARDS_WILDCARDS_HPP
