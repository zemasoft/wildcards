// THIS FILE HAS BEEN GENERATED AUTOMATICALLY. DO NOT EDIT DIRECTLY.
// Generated: 2018-05-21 13:22:38.275240524
// Copyright Tomas Zeman 2018.
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
#ifndef WILDCARDS_HPP
#define WILDCARDS_HPP 
#define WILDCARDS_VERSION_MAJOR 1
#define WILDCARDS_VERSION_MINOR 2
#define WILDCARDS_VERSION_PATCH 0
#ifndef WILDCARDS_CARDS_HPP
#define WILDCARDS_CARDS_HPP 
#include <utility>
namespace wildcards
{
template <typename T>
struct cards
{
constexpr cards(T a, T s, T e)
: anything{std::move(a)},
single{std::move(s)},
escape{std::move(e)},
set_enabled{false},
alt_enabled{false}
{
}
constexpr cards(T a, T s, T e, T so, T sc, T sn, T ao, T ac, T ar)
: anything{std::move(a)},
single{std::move(s)},
escape{std::move(e)},
set_enabled{true},
set_open{std::move(so)},
set_close{std::move(sc)},
set_not{std::move(sn)},
alt_enabled{true},
alt_open{std::move(ao)},
alt_close{std::move(ac)},
alt_or{std::move(ar)}
{
}
T anything;
T single;
T escape;
bool set_enabled;
T set_open;
T set_close;
T set_not;
bool alt_enabled;
T alt_open;
T alt_close;
T alt_or;
};
enum class cards_type
{
standard,
extended
};
template <>
struct cards<char>
{
constexpr cards(cards_type type = cards_type::extended)
: set_enabled{type == cards_type::extended}, alt_enabled{type == cards_type::extended}
{
}
constexpr cards(char a, char s, char e)
: anything{std::move(a)},
single{std::move(s)},
escape{std::move(e)},
set_enabled{false},
alt_enabled{false}
{
}
constexpr cards(char a, char s, char e, char so, char sc, char sn, char ao, char ac, char ar)
: anything{std::move(a)},
single{std::move(s)},
escape{std::move(e)},
set_enabled{true},
set_open{std::move(so)},
set_close{std::move(sc)},
set_not{std::move(sn)},
alt_enabled{true},
alt_open{std::move(ao)},
alt_close{std::move(ac)},
alt_or{std::move(ar)}
{
}
char anything{'*'};
char single{'?'};
char escape{'\\'};
bool set_enabled{true};
char set_open{'['};
char set_close{']'};
char set_not{'!'};
bool alt_enabled{true};
char alt_open{'('};
char alt_close{')'};
char alt_or{'|'};
};
template <>
struct cards<char16_t>
{
constexpr cards(cards_type type = cards_type::extended)
: set_enabled{type == cards_type::extended}, alt_enabled{type == cards_type::extended}
{
}
constexpr cards(char16_t a, char16_t s, char16_t e)
: anything{std::move(a)},
single{std::move(s)},
escape{std::move(e)},
set_enabled{false},
alt_enabled{false}
{
}
constexpr cards(char16_t a, char16_t s, char16_t e, char16_t so, char16_t sc, char16_t sn,
char16_t ao, char16_t ac, char16_t ar)
: anything{std::move(a)},
single{std::move(s)},
escape{std::move(e)},
set_enabled{true},
set_open{std::move(so)},
set_close{std::move(sc)},
set_not{std::move(sn)},
alt_enabled{true},
alt_open{std::move(ao)},
alt_close{std::move(ac)},
alt_or{std::move(ar)}
{
}
char16_t anything{u'*'};
char16_t single{u'?'};
char16_t escape{u'\\'};
bool set_enabled{true};
char16_t set_open{u'['};
char16_t set_close{u']'};
char16_t set_not{u'!'};
bool alt_enabled{true};
char16_t alt_open{u'('};
char16_t alt_close{u')'};
char16_t alt_or{u'|'};
};
template <>
struct cards<char32_t>
{
constexpr cards(cards_type type = cards_type::extended)
: set_enabled{type == cards_type::extended}, alt_enabled{type == cards_type::extended}
{
}
constexpr cards(char32_t a, char32_t s, char32_t e)
: anything{std::move(a)},
single{std::move(s)},
escape{std::move(e)},
set_enabled{false},
alt_enabled{false}
{
}
constexpr cards(char32_t a, char32_t s, char32_t e, char32_t so, char32_t sc, char32_t sn,
char32_t ao, char32_t ac, char32_t ar)
: anything{std::move(a)},
single{std::move(s)},
escape{std::move(e)},
set_enabled{true},
set_open{std::move(so)},
set_close{std::move(sc)},
set_not{std::move(sn)},
alt_enabled{true},
alt_open{std::move(ao)},
alt_close{std::move(ac)},
alt_or{std::move(ar)}
{
}
char32_t anything{U'*'};
char32_t single{U'?'};
char32_t escape{U'\\'};
bool set_enabled{true};
char32_t set_open{U'['};
char32_t set_close{U']'};
char32_t set_not{U'!'};
bool alt_enabled{true};
char32_t alt_open{U'('};
char32_t alt_close{U')'};
char32_t alt_or{U'|'};
};
template <>
struct cards<wchar_t>
{
constexpr cards(cards_type type = cards_type::extended)
: set_enabled{type == cards_type::extended}, alt_enabled{type == cards_type::extended}
{
}
constexpr cards(wchar_t a, wchar_t s, wchar_t e)
: anything{std::move(a)},
single{std::move(s)},
escape{std::move(e)},
set_enabled{false},
alt_enabled{false}
{
}
constexpr cards(wchar_t a, wchar_t s, wchar_t e, wchar_t so, wchar_t sc, wchar_t sn, wchar_t ao,
wchar_t ac, wchar_t ar)
: anything{std::move(a)},
single{std::move(s)},
escape{std::move(e)},
set_enabled{true},
set_open{std::move(so)},
set_close{std::move(sc)},
set_not{std::move(sn)},
alt_enabled{true},
alt_open{std::move(ao)},
alt_close{std::move(ac)},
alt_or{std::move(ar)}
{
}
wchar_t anything{L'*'};
wchar_t single{L'?'};
wchar_t escape{L'\\'};
bool set_enabled{true};
wchar_t set_open{L'['};
wchar_t set_close{L']'};
wchar_t set_not{L'!'};
bool alt_enabled{true};
wchar_t alt_open{L'('};
wchar_t alt_close{L')'};
wchar_t alt_or{L'|'};
};
template <typename T>
constexpr cards<T> make_cards(T&& a, T&& s, T&& e)
{
return {std::forward<T>(a), std::forward<T>(s), std::forward<T>(e)};
}
template <typename T>
constexpr cards<T> make_cards(T&& a, T&& s, T&& e, T&& so, T&& sc, T&& sn, T&& ao, T&& ac, T&& ar)
{
return {std::forward<T>(a), std::forward<T>(s), std::forward<T>(e),
std::forward<T>(so), std::forward<T>(sc), std::forward<T>(sn),
std::forward<T>(ao), std::forward<T>(ac), std::forward<T>(ar)};
}
}
#endif
#ifndef WILDCARDS_MATCH_HPP
#define WILDCARDS_MATCH_HPP 
#include <stdexcept>
#include <type_traits>
#include <utility>
#ifndef CONFIG_HPP
#define CONFIG_HPP 
#ifndef QUICKCPPLIB_HAS_FEATURE_H
#define QUICKCPPLIB_HAS_FEATURE_H 
#if __cplusplus >= 201103L
#if !defined(__cpp_alias_templates)
#define __cpp_alias_templates 190000
#endif
#if !defined(__cpp_attributes)
#define __cpp_attributes 190000
#endif
#if !defined(__cpp_constexpr)
#if __cplusplus >= 201402L
#define __cpp_constexpr 201304
#else
#define __cpp_constexpr 190000
#endif
#endif
#if !defined(__cpp_decltype)
#define __cpp_decltype 190000
#endif
#if !defined(__cpp_delegating_constructors)
#define __cpp_delegating_constructors 190000
#endif
#if !defined(__cpp_explicit_conversion)
#define __cpp_explicit_conversion 190000
#endif
#if !defined(__cpp_inheriting_constructors)
#define __cpp_inheriting_constructors 190000
#endif
#if !defined(__cpp_initializer_lists)
#define __cpp_initializer_lists 190000
#endif
#if !defined(__cpp_lambdas)
#define __cpp_lambdas 190000
#endif
#if !defined(__cpp_nsdmi)
#define __cpp_nsdmi 190000
#endif
#if !defined(__cpp_range_based_for)
#define __cpp_range_based_for 190000
#endif
#if !defined(__cpp_raw_strings)
#define __cpp_raw_strings 190000
#endif
#if !defined(__cpp_ref_qualifiers)
#define __cpp_ref_qualifiers 190000
#endif
#if !defined(__cpp_rvalue_references)
#define __cpp_rvalue_references 190000
#endif
#if !defined(__cpp_static_assert)
#define __cpp_static_assert 190000
#endif
#if !defined(__cpp_unicode_characters)
#define __cpp_unicode_characters 190000
#endif
#if !defined(__cpp_unicode_literals)
#define __cpp_unicode_literals 190000
#endif
#if !defined(__cpp_user_defined_literals)
#define __cpp_user_defined_literals 190000
#endif
#if !defined(__cpp_variadic_templates)
#define __cpp_variadic_templates 190000
#endif
#endif
#if __cplusplus >= 201402L
#if !defined(__cpp_aggregate_nsdmi)
#define __cpp_aggregate_nsdmi 190000
#endif
#if !defined(__cpp_binary_literals)
#define __cpp_binary_literals 190000
#endif
#if !defined(__cpp_decltype_auto)
#define __cpp_decltype_auto 190000
#endif
#if !defined(__cpp_generic_lambdas)
#define __cpp_generic_lambdas 190000
#endif
#if !defined(__cpp_init_captures)
#define __cpp_init_captures 190000
#endif
#if !defined(__cpp_return_type_deduction)
#define __cpp_return_type_deduction 190000
#endif
#if !defined(__cpp_sized_deallocation)
#define __cpp_sized_deallocation 190000
#endif
#if !defined(__cpp_variable_templates)
#define __cpp_variable_templates 190000
#endif
#endif
#if defined(_MSC_VER) && !defined(__clang__)
#if !defined(__cpp_exceptions) && defined(_CPPUNWIND)
#define __cpp_exceptions 190000
#endif
#if !defined(__cpp_rtti) && defined(_CPPRTTI)
#define __cpp_rtti 190000
#endif
#if !defined(__cpp_alias_templates) && _MSC_VER >= 1800
#define __cpp_alias_templates 190000
#endif
#if !defined(__cpp_attributes)
#define __cpp_attributes 190000
#endif
#if !defined(__cpp_constexpr) && _MSC_FULL_VER >= 190023506
#define __cpp_constexpr 190000
#endif
#if !defined(__cpp_decltype) && _MSC_VER >= 1600
#define __cpp_decltype 190000
#endif
#if !defined(__cpp_delegating_constructors) && _MSC_VER >= 1800
#define __cpp_delegating_constructors 190000
#endif
#if !defined(__cpp_explicit_conversion) && _MSC_VER >= 1800
#define __cpp_explicit_conversion 190000
#endif
#if !defined(__cpp_inheriting_constructors) && _MSC_VER >= 1900
#define __cpp_inheriting_constructors 190000
#endif
#if !defined(__cpp_initializer_lists) && _MSC_VER >= 1900
#define __cpp_initializer_lists 190000
#endif
#if !defined(__cpp_lambdas) && _MSC_VER >= 1600
#define __cpp_lambdas 190000
#endif
#if !defined(__cpp_nsdmi) && _MSC_VER >= 1900
#define __cpp_nsdmi 190000
#endif
#if !defined(__cpp_range_based_for) && _MSC_VER >= 1700
#define __cpp_range_based_for 190000
#endif
#if !defined(__cpp_raw_strings) && _MSC_VER >= 1800
#define __cpp_raw_strings 190000
#endif
#if !defined(__cpp_ref_qualifiers) && _MSC_VER >= 1900
#define __cpp_ref_qualifiers 190000
#endif
#if !defined(__cpp_rvalue_references) && _MSC_VER >= 1600
#define __cpp_rvalue_references 190000
#endif
#if !defined(__cpp_static_assert) && _MSC_VER >= 1600
#define __cpp_static_assert 190000
#endif
#if !defined(__cpp_user_defined_literals) && _MSC_VER >= 1900
#define __cpp_user_defined_literals 190000
#endif
#if !defined(__cpp_variadic_templates) && _MSC_VER >= 1800
#define __cpp_variadic_templates 190000
#endif
#if !defined(__cpp_binary_literals) && _MSC_VER >= 1900
#define __cpp_binary_literals 190000
#endif
#if !defined(__cpp_decltype_auto) && _MSC_VER >= 1900
#define __cpp_decltype_auto 190000
#endif
#if !defined(__cpp_generic_lambdas) && _MSC_VER >= 1900
#define __cpp_generic_lambdas 190000
#endif
#if !defined(__cpp_init_captures) && _MSC_VER >= 1900
#define __cpp_init_captures 190000
#endif
#if !defined(__cpp_return_type_deduction) && _MSC_VER >= 1900
#define __cpp_return_type_deduction 190000
#endif
#if !defined(__cpp_sized_deallocation) && _MSC_VER >= 1900
#define __cpp_sized_deallocation 190000
#endif
#if !defined(__cpp_variable_templates) && _MSC_FULL_VER >= 190023506
#define __cpp_variable_templates 190000
#endif
#endif
#if(defined(__GNUC__) && !defined(__clang__))
#define QUICKCPPLIB_GCC (__GNUC__ * 10000 + __GNUC_MINOR__ * 100 + __GNUC_PATCHLEVEL__)
#if !defined(__cpp_exceptions) && defined(__EXCEPTIONS)
#define __cpp_exceptions 190000
#endif
#if !defined(__cpp_rtti) && defined(__GXX_RTTI)
#define __cpp_rtti 190000
#endif
#if defined(__GXX_EXPERIMENTAL_CXX0X__)
#if !defined(__cpp_alias_templates) && (QUICKCPPLIB_GCC >= 40700)
#define __cpp_alias_templates 190000
#endif
#if !defined(__cpp_attributes) && (QUICKCPPLIB_GCC >= 40800)
#define __cpp_attributes 190000
#endif
#if !defined(__cpp_constexpr) && (QUICKCPPLIB_GCC >= 40600)
#define __cpp_constexpr 190000
#endif
#if !defined(__cpp_decltype) && (QUICKCPPLIB_GCC >= 40300)
#define __cpp_decltype 190000
#endif
#if !defined(__cpp_delegating_constructors) && (QUICKCPPLIB_GCC >= 40700)
#define __cpp_delegating_constructors 190000
#endif
#if !defined(__cpp_explicit_conversion) && (QUICKCPPLIB_GCC >= 40500)
#define __cpp_explicit_conversion 190000
#endif
#if !defined(__cpp_inheriting_constructors) && (QUICKCPPLIB_GCC >= 40800)
#define __cpp_inheriting_constructors 190000
#endif
#if !defined(__cpp_initializer_lists) && (QUICKCPPLIB_GCC >= 40800)
#define __cpp_initializer_lists 190000
#endif
#if !defined(__cpp_lambdas) && (QUICKCPPLIB_GCC >= 40500)
#define __cpp_lambdas 190000
#endif
#if !defined(__cpp_nsdmi) && (QUICKCPPLIB_GCC >= 40700)
#define __cpp_nsdmi 190000
#endif
#if !defined(__cpp_range_based_for) && (QUICKCPPLIB_GCC >= 40600)
#define __cpp_range_based_for 190000
#endif
#if !defined(__cpp_raw_strings) && (QUICKCPPLIB_GCC >= 40500)
#define __cpp_raw_strings 190000
#endif
#if !defined(__cpp_ref_qualifiers) && (QUICKCPPLIB_GCC >= 40801)
#define __cpp_ref_qualifiers 190000
#endif
#if !defined(__cpp_rvalue_references) && defined(__cpp_rvalue_reference)
#define __cpp_rvalue_references __cpp_rvalue_reference
#endif
#if !defined(__cpp_static_assert) && (QUICKCPPLIB_GCC >= 40300)
#define __cpp_static_assert 190000
#endif
#if !defined(__cpp_unicode_characters) && (QUICKCPPLIB_GCC >= 40500)
#define __cpp_unicode_characters 190000
#endif
#if !defined(__cpp_unicode_literals) && (QUICKCPPLIB_GCC >= 40500)
#define __cpp_unicode_literals 190000
#endif
#if !defined(__cpp_user_defined_literals) && (QUICKCPPLIB_GCC >= 40700)
#define __cpp_user_defined_literals 190000
#endif
#if !defined(__cpp_variadic_templates) && (QUICKCPPLIB_GCC >= 40400)
#define __cpp_variadic_templates 190000
#endif
#endif
#endif
#if defined(__clang__)
#define QUICKCPPLIB_CLANG (__clang_major__ * 10000 + __clang_minor__ * 100 + __clang_patchlevel__)
#if !defined(__cpp_exceptions) && (defined(__EXCEPTIONS) || defined(_CPPUNWIND))
#define __cpp_exceptions 190000
#endif
#if !defined(__cpp_rtti) && (defined(__GXX_RTTI) || defined(_CPPRTTI))
#define __cpp_rtti 190000
#endif
#if defined(__GXX_EXPERIMENTAL_CXX0X__)
#if !defined(__cpp_alias_templates) && (QUICKCPPLIB_CLANG >= 30000)
#define __cpp_alias_templates 190000
#endif
#if !defined(__cpp_attributes) && (QUICKCPPLIB_CLANG >= 30300)
#define __cpp_attributes 190000
#endif
#if !defined(__cpp_constexpr) && (QUICKCPPLIB_CLANG >= 30100)
#define __cpp_constexpr 190000
#endif
#if !defined(__cpp_decltype) && (QUICKCPPLIB_CLANG >= 20900)
#define __cpp_decltype 190000
#endif
#if !defined(__cpp_delegating_constructors) && (QUICKCPPLIB_CLANG >= 30000)
#define __cpp_delegating_constructors 190000
#endif
#if !defined(__cpp_explicit_conversion) && (QUICKCPPLIB_CLANG >= 30000)
#define __cpp_explicit_conversion 190000
#endif
#if !defined(__cpp_inheriting_constructors) && (QUICKCPPLIB_CLANG >= 30300)
#define __cpp_inheriting_constructors 190000
#endif
#if !defined(__cpp_initializer_lists) && (QUICKCPPLIB_CLANG >= 30100)
#define __cpp_initializer_lists 190000
#endif
#if !defined(__cpp_lambdas) && (QUICKCPPLIB_CLANG >= 30100)
#define __cpp_lambdas 190000
#endif
#if !defined(__cpp_nsdmi) && (QUICKCPPLIB_CLANG >= 30000)
#define __cpp_nsdmi 190000
#endif
#if !defined(__cpp_range_based_for) && (QUICKCPPLIB_CLANG >= 30000)
#define __cpp_range_based_for 190000
#endif
#if !defined(__cpp_raw_strings) && defined(__cpp_raw_string_literals)
#define __cpp_raw_strings __cpp_raw_string_literals
#endif
#if !defined(__cpp_raw_strings) && (QUICKCPPLIB_CLANG >= 30000)
#define __cpp_raw_strings 190000
#endif
#if !defined(__cpp_ref_qualifiers) && (QUICKCPPLIB_CLANG >= 20900)
#define __cpp_ref_qualifiers 190000
#endif
#if !defined(__cpp_rvalue_references) && defined(__cpp_rvalue_reference)
#define __cpp_rvalue_references __cpp_rvalue_reference
#endif
#if !defined(__cpp_rvalue_references) && (QUICKCPPLIB_CLANG >= 20900)
#define __cpp_rvalue_references 190000
#endif
#if !defined(__cpp_static_assert) && (QUICKCPPLIB_CLANG >= 20900)
#define __cpp_static_assert 190000
#endif
#if !defined(__cpp_unicode_characters) && (QUICKCPPLIB_CLANG >= 30000)
#define __cpp_unicode_characters 190000
#endif
#if !defined(__cpp_unicode_literals) && (QUICKCPPLIB_CLANG >= 30000)
#define __cpp_unicode_literals 190000
#endif
#if !defined(__cpp_user_defined_literals) && defined(__cpp_user_literals)
#define __cpp_user_defined_literals __cpp_user_literals
#endif
#if !defined(__cpp_user_defined_literals) && (QUICKCPPLIB_CLANG >= 30100)
#define __cpp_user_defined_literals 190000
#endif
#if !defined(__cpp_variadic_templates) && (QUICKCPPLIB_CLANG >= 20900)
#define __cpp_variadic_templates 190000
#endif
#endif
#endif
#endif
#define cfg_HAS_CONSTEXPR14 (__cpp_constexpr >= 201304)
#if cfg_HAS_CONSTEXPR14
#define cfg_constexpr14 constexpr
#else
#define cfg_constexpr14 
#endif
#if cfg_HAS_CONSTEXPR14 && !(defined(__GNUC__) && __GNUC__ < 6 && !defined(__clang__))
#define cfg_HAS_FULL_FEATURED_CONSTEXPR_SWITCH 1
#else
#define cfg_HAS_FULL_FEATURED_CONSTEXPR_SWITCH 0
#endif
#endif
#ifndef CX_FUNCTIONAL_HPP
#define CX_FUNCTIONAL_HPP 
#include <utility>
namespace cx
{
template <typename T>
struct less
{
constexpr auto operator()(const T& lhs, const T& rhs) const -> decltype(lhs < rhs)
{
return lhs < rhs;
}
};
template <>
struct less<void>
{
template <typename T, typename U>
constexpr auto operator()(T&& lhs, U&& rhs) const
-> decltype(std::forward<T>(lhs) < std::forward<U>(rhs))
{
return std::forward<T>(lhs) < std::forward<U>(rhs);
}
};
template <typename T>
struct equal_to
{
constexpr auto operator()(const T& lhs, const T& rhs) const -> decltype(lhs == rhs)
{
return lhs == rhs;
}
};
template <>
struct equal_to<void>
{
template <typename T, typename U>
constexpr auto operator()(T&& lhs, U&& rhs) const
-> decltype(std::forward<T>(lhs) == std::forward<U>(rhs))
{
return std::forward<T>(lhs) == std::forward<U>(rhs);
}
};
}
#endif
#ifndef CX_ITERATOR_HPP
#define CX_ITERATOR_HPP 
#include <cstddef>
#include <initializer_list>
namespace cx
{
template <typename It>
constexpr It next(It it)
{
return it + 1;
}
template <typename It>
constexpr It prev(It it)
{
return it - 1;
}
template <typename C>
constexpr auto size(const C& c) -> decltype(c.size())
{
return c.size();
}
template <typename T, std::size_t N>
constexpr std::size_t size(const T (&)[N])
{
return N;
}
template <typename C>
constexpr auto empty(const C& c) -> decltype(c.empty())
{
return c.empty();
}
template <typename T, std::size_t N>
constexpr bool empty(const T (&)[N])
{
return false;
}
template <typename E>
constexpr bool empty(std::initializer_list<E> il)
{
return il.size() == 0;
}
template <typename C>
constexpr auto begin(const C& c) -> decltype(c.begin())
{
return c.begin();
}
template <typename C>
constexpr auto begin(C& c) -> decltype(c.begin())
{
return c.begin();
}
template <typename T, std::size_t N>
constexpr T* begin(T (&array)[N])
{
return &array[0];
}
template <typename E>
constexpr const E* begin(std::initializer_list<E> il)
{
return il.begin();
}
template <typename C>
constexpr auto cbegin(const C& c) -> decltype(cx::begin(c))
{
return cx::begin(c);
}
template <typename C>
constexpr auto end(const C& c) -> decltype(c.end())
{
return c.end();
}
template <typename C>
constexpr auto end(C& c) -> decltype(c.end())
{
return c.end();
}
template <typename T, std::size_t N>
constexpr T* end(T (&array)[N])
{
return &array[N];
}
template <typename E>
constexpr const E* end(std::initializer_list<E> il)
{
return il.end();
}
template <typename C>
constexpr auto cend(const C& c) -> decltype(cx::end(c))
{
return cx::end(c);
}
}
#endif
#ifndef WILDCARDS_UTILITY_HPP
#define WILDCARDS_UTILITY_HPP 
#include <type_traits>
#include <utility>
namespace wildcards
{
template <typename It>
struct iterated_item
{
using type = typename std::remove_cv<
typename std::remove_reference<decltype(*std::declval<It>())>::type>::type;
};
template <typename It>
using iterated_item_t = typename iterated_item<It>::type;
template <typename C>
struct container_item
{
using type = typename std::remove_cv<
typename std::remove_reference<decltype(*cx::begin(std::declval<C>()))>::type>::type;
};
template <typename C>
using container_item_t = typename container_item<C>::type;
}
#endif
namespace wildcards
{
namespace detail
{
#if !cfg_HAS_FULL_FEATURED_CONSTEXPR_SWITCH
constexpr bool throw_invalid_argument(const char* what_arg)
{
return what_arg == nullptr ? false : throw std::invalid_argument(what_arg);
}
template <typename T>
constexpr T throw_invalid_argument(T t, const char* what_arg)
{
return what_arg == nullptr ? t : throw std::invalid_argument(what_arg);
}
constexpr bool throw_logic_error(const char* what_arg)
{
return what_arg == nullptr ? false : throw std::logic_error(what_arg);
}
template <typename T>
constexpr T throw_logic_error(T t, const char* what_arg)
{
return what_arg == nullptr ? t : throw std::logic_error(what_arg);
}
constexpr bool throw_runtime_error(const char* what_arg)
{
return what_arg == nullptr ? false : throw std::runtime_error(what_arg);
}
#endif
enum class is_set_state
{
open,
not_or_first,
first,
next
};
template <typename PatternIterator>
constexpr bool is_set(
PatternIterator p, PatternIterator pend,
const cards<iterated_item_t<PatternIterator>>& c = cards<iterated_item_t<PatternIterator>>(),
is_set_state state = is_set_state::open)
{
#if cfg_HAS_CONSTEXPR14
if (!c.set_enabled || p == pend)
{
return false;
}
switch (state)
{
case is_set_state::open:
if (*p == c.set_open)
{
return is_set(cx::next(p), pend, c, is_set_state::not_or_first);
}
return false;
case is_set_state::not_or_first:
if (*p == c.set_not)
{
return is_set(cx::next(p), pend, c, is_set_state::first);
}
return is_set(cx::next(p), pend, c, is_set_state::next);
case is_set_state::first:
return is_set(cx::next(p), pend, c, is_set_state::next);
case is_set_state::next:
if (*p == c.set_close)
{
return true;
}
return is_set(cx::next(p), pend, c, is_set_state::next);
default:
#if cfg_HAS_FULL_FEATURED_CONSTEXPR_SWITCH
throw std::logic_error(
"The program execution should never end up here throwing this exception");
#else
return throw_logic_error(
"The program execution should never end up here throwing this exception");
#endif
}
#else
return c.set_enabled && p != pend &&
(state == is_set_state::open
? *p == c.set_open && is_set(cx::next(p), pend, c, is_set_state::not_or_first)
:
state == is_set_state::not_or_first
? *p == c.set_not ? is_set(cx::next(p), pend, c, is_set_state::first)
: is_set(cx::next(p), pend, c, is_set_state::next)
: state == is_set_state::first
? is_set(cx::next(p), pend, c, is_set_state::next)
: state == is_set_state::next
? *p == c.set_close ||
is_set(cx::next(p), pend, c, is_set_state::next)
: throw std::logic_error("The program execution should never end up "
"here throwing this exception"));
#endif
}
enum class set_end_state
{
open,
not_or_first,
first,
next
};
template <typename PatternIterator>
constexpr PatternIterator set_end(
PatternIterator p, PatternIterator pend,
const cards<iterated_item_t<PatternIterator>>& c = cards<iterated_item_t<PatternIterator>>(),
set_end_state state = set_end_state::open)
{
#if cfg_HAS_CONSTEXPR14
if (!c.set_enabled)
{
#if cfg_HAS_FULL_FEATURED_CONSTEXPR_SWITCH
throw std::invalid_argument("The use of sets is disabled");
#else
return throw_invalid_argument(p, "The use of sets is disabled");
#endif
}
if (p == pend)
{
#if cfg_HAS_FULL_FEATURED_CONSTEXPR_SWITCH
throw std::invalid_argument("The given pattern is not a valid set");
#else
return throw_invalid_argument(p, "The given pattern is not a valid set");
#endif
}
switch (state)
{
case set_end_state::open:
if (*p == c.set_open)
{
return set_end(cx::next(p), pend, c, set_end_state::not_or_first);
}
#if cfg_HAS_FULL_FEATURED_CONSTEXPR_SWITCH
throw std::invalid_argument("The given pattern is not a valid set");
#else
return throw_invalid_argument(p, "The given pattern is not a valid set");
#endif
case set_end_state::not_or_first:
if (*p == c.set_not)
{
return set_end(cx::next(p), pend, c, set_end_state::first);
}
return set_end(cx::next(p), pend, c, set_end_state::next);
case set_end_state::first:
return set_end(cx::next(p), pend, c, set_end_state::next);
case set_end_state::next:
if (*p == c.set_close)
{
return cx::next(p);
}
return set_end(cx::next(p), pend, c, set_end_state::next);
default:
#if cfg_HAS_FULL_FEATURED_CONSTEXPR_SWITCH
throw std::logic_error(
"The program execution should never end up here throwing this exception");
#else
return throw_logic_error(
p, "The program execution should never end up here throwing this exception");
#endif
}
#else
return !c.set_enabled
? throw std::invalid_argument("The use of sets is disabled")
: p == pend
? throw std::invalid_argument("The given pattern is not a valid set")
:
state == set_end_state::open
? *p == c.set_open
? set_end(cx::next(p), pend, c, set_end_state::not_or_first)
: throw std::invalid_argument("The given pattern is not a valid set")
:
state == set_end_state::not_or_first
? *p == c.set_not ? set_end(cx::next(p), pend, c, set_end_state::first)
: set_end(cx::next(p), pend, c, set_end_state::next)
: state == set_end_state::first
? set_end(cx::next(p), pend, c, set_end_state::next)
: state == set_end_state::next
? *p == c.set_close
? cx::next(p)
: set_end(cx::next(p), pend, c, set_end_state::next)
: throw std::logic_error(
"The program execution should never end up "
"here throwing this exception");
#endif
}
enum class match_set_state
{
open,
not_or_first_in,
first_out,
next_in,
next_out
};
template <typename SequenceIterator, typename PatternIterator,
typename EqualTo = cx::equal_to<void>>
constexpr bool match_set(
SequenceIterator s, SequenceIterator send, PatternIterator p, PatternIterator pend,
const cards<iterated_item_t<PatternIterator>>& c = cards<iterated_item_t<PatternIterator>>(),
const EqualTo& equal_to = EqualTo(), match_set_state state = match_set_state::open)
{
#if cfg_HAS_CONSTEXPR14
if (!c.set_enabled)
{
#if cfg_HAS_FULL_FEATURED_CONSTEXPR_SWITCH
throw std::invalid_argument("The use of sets is disabled");
#else
return throw_invalid_argument("The use of sets is disabled");
#endif
}
if (p == pend)
{
#if cfg_HAS_FULL_FEATURED_CONSTEXPR_SWITCH
throw std::invalid_argument("The given pattern is not a valid set");
#else
return throw_invalid_argument("The given pattern is not a valid set");
#endif
}
switch (state)
{
case match_set_state::open:
if (*p == c.set_open)
{
return match_set(s, send, cx::next(p), pend, c, equal_to, match_set_state::not_or_first_in);
}
#if cfg_HAS_FULL_FEATURED_CONSTEXPR_SWITCH
throw std::invalid_argument("The given pattern is not a valid set");
#else
return throw_invalid_argument("The given pattern is not a valid set");
#endif
case match_set_state::not_or_first_in:
if (*p == c.set_not)
{
return match_set(s, send, cx::next(p), pend, c, equal_to, match_set_state::first_out);
}
if (s == send)
{
return false;
}
if (equal_to(*s, *p))
{
return true;
}
return match_set(s, send, cx::next(p), pend, c, equal_to, match_set_state::next_in);
case match_set_state::first_out:
if (s == send || equal_to(*s, *p))
{
return false;
}
return match_set(s, send, cx::next(p), pend, c, equal_to, match_set_state::next_out);
case match_set_state::next_in:
if (*p == c.set_close || s == send)
{
return false;
}
if (equal_to(*s, *p))
{
return true;
}
return match_set(s, send, cx::next(p), pend, c, equal_to, state);
case match_set_state::next_out:
if (*p == c.set_close)
{
return true;
}
if (s == send || equal_to(*s, *p))
{
return false;
}
return match_set(s, send, cx::next(p), pend, c, equal_to, state);
default:
#if cfg_HAS_FULL_FEATURED_CONSTEXPR_SWITCH
throw std::logic_error(
"The program execution should never end up here throwing this exception");
#else
return throw_logic_error(
"The program execution should never end up here throwing this exception");
#endif
}
#else
return !c.set_enabled
? throw std::invalid_argument("The use of sets is disabled")
: p == pend
? throw std::invalid_argument("The given pattern is not a valid set")
: state == match_set_state::open
? *p == c.set_open
? match_set(s, send, cx::next(p), pend, c, equal_to,
match_set_state::not_or_first_in)
:
throw std::invalid_argument("The given pattern is not a valid set")
:
state == match_set_state::not_or_first_in
? *p == c.set_not
? match_set(s, send, cx::next(p), pend, c, equal_to,
match_set_state::first_out)
:
s != send && (equal_to(*s, *p) ||
match_set(s, send, cx::next(p), pend, c, equal_to,
match_set_state::next_in))
:
state == match_set_state::first_out
? s != send && !equal_to(*s, *p) &&
match_set(s, send, cx::next(p), pend, c, equal_to,
match_set_state::next_out)
:
state == match_set_state::next_in
? *p != c.set_close && s != send &&
(equal_to(*s, *p) || match_set(s, send, cx::next(p),
pend, c, equal_to, state))
:
state == match_set_state::next_out
? *p == c.set_close ||
(s != send && !equal_to(*s, *p) &&
match_set(s, send, cx::next(p), pend, c, equal_to,
state))
: throw std::logic_error(
"The program execution should never end up "
"here "
"throwing this exception");
#endif
}
enum class is_alt_state
{
open,
next,
escape
};
template <typename PatternIterator>
constexpr bool is_alt(
PatternIterator p, PatternIterator pend,
const cards<iterated_item_t<PatternIterator>>& c = cards<iterated_item_t<PatternIterator>>(),
is_alt_state state = is_alt_state::open, int depth = 0)
{
#if cfg_HAS_CONSTEXPR14
if (!c.alt_enabled || p == pend)
{
return false;
}
switch (state)
{
case is_alt_state::open:
if (*p == c.alt_open)
{
return is_alt(cx::next(p), pend, c, is_alt_state::next, depth + 1);
}
return false;
case is_alt_state::next:
if (*p == c.escape)
{
return is_alt(cx::next(p), pend, c, is_alt_state::escape, depth);
}
if (c.set_enabled && *p == c.set_open &&
is_set(cx::next(p), pend, c, is_set_state::not_or_first))
{
return is_alt(set_end(cx::next(p), pend, c, set_end_state::not_or_first), pend, c, state,
depth);
}
if (*p == c.alt_open)
{
return is_alt(cx::next(p), pend, c, state, depth + 1);
}
if (*p == c.alt_close)
{
if (depth - 1 == 0)
{
return true;
}
return is_alt(cx::next(p), pend, c, state, depth - 1);
}
return is_alt(cx::next(p), pend, c, state, depth);
case is_alt_state::escape:
return is_alt(cx::next(p), pend, c, is_alt_state::next, depth);
default:
#if cfg_HAS_FULL_FEATURED_CONSTEXPR_SWITCH
throw std::logic_error(
"The program execution should never end up here throwing this exception");
#else
return throw_logic_error(
p, "The program execution should never end up here throwing this exception");
#endif
}
#else
return c.alt_enabled && p != pend &&
(state == is_alt_state::open
? *p == c.alt_open && is_alt(cx::next(p), pend, c, is_alt_state::next, depth + 1)
: state == is_alt_state::next
? *p == c.escape
? is_alt(cx::next(p), pend, c, is_alt_state::escape, depth)
: c.set_enabled && *p == c.set_open &&
is_set(cx::next(p), pend, c, is_set_state::not_or_first)
? is_alt(set_end(cx::next(p), pend, c, set_end_state::not_or_first),
pend, c, state, depth)
: *p == c.alt_open
? is_alt(cx::next(p), pend, c, state, depth + 1)
: *p == c.alt_close
? depth - 1 == 0 ||
is_alt(cx::next(p), pend, c, state, depth - 1)
: is_alt(cx::next(p), pend, c, state, depth)
:
state == is_alt_state::escape
? is_alt(cx::next(p), pend, c, is_alt_state::next, depth)
: throw std::logic_error(
"The program execution should never end up here throwing this "
"exception"));
#endif
}
}
template <typename SequenceIterator, typename PatternIterator,
typename EqualTo = cx::equal_to<void>>
constexpr bool match(
SequenceIterator s, SequenceIterator send, PatternIterator p, PatternIterator pend,
const cards<iterated_item_t<PatternIterator>>& c = cards<iterated_item_t<PatternIterator>>(),
const EqualTo& equal_to = EqualTo(), bool escape = false)
{
#if cfg_HAS_CONSTEXPR14
if (p == pend)
{
return s == send;
}
if (escape)
{
if (s != send && equal_to(*s, *p))
{
return match(cx::next(s), send, cx::next(p), pend, c, equal_to);
}
return false;
}
if (*p == c.anything)
{
return match(s, send, cx::next(p), pend, c, equal_to) ||
(s != send && match(cx::next(s), send, p, pend, c, equal_to));
}
if (*p == c.single)
{
return s != send && match(cx::next(s), send, cx::next(p), pend, c, equal_to);
}
if (*p == c.escape)
{
return match(s, send, cx::next(p), pend, c, equal_to, true);
}
if (c.set_enabled && *p == c.set_open &&
detail::is_set(cx::next(p), pend, c, detail::is_set_state::not_or_first))
{
return match_set(s, send, cx::next(p), pend, c, equal_to,
detail::match_set_state::not_or_first_in) &&
match(cx::next(s), send,
detail::set_end(cx::next(p), pend, c, detail::set_end_state::not_or_first), pend,
c, equal_to);
}
if (c.alt_enabled && *p == c.alt_open &&
detail::is_alt(cx::next(p), pend, c, detail::is_alt_state::next, 1))
{
#if cfg_HAS_FULL_FEATURED_CONSTEXPR_SWITCH
throw std::runtime_error("Sorry, alternatives not implemented");
#else
return detail::throw_runtime_error("Sorry, alternatives not implemented");
#endif
}
if (s != send && equal_to(*s, *p))
{
return match(cx::next(s), send, cx::next(p), pend, c, equal_to);
}
return false;
#else
return p == pend
? s == send
: escape
? s != send && equal_to(*s, *p) &&
match(cx::next(s), send, cx::next(p), pend, c, equal_to)
: *p == c.anything
? match(s, send, cx::next(p), pend, c, equal_to) ||
(s != send && match(cx::next(s), send, p, pend, c, equal_to))
: *p == c.single
? s != send &&
match(cx::next(s), send, cx::next(p), pend, c, equal_to)
: *p == c.escape
? match(s, send, cx::next(p), pend, c, equal_to, true)
: c.set_enabled && *p == c.set_open &&
detail::is_set(cx::next(p), pend, c,
detail::is_set_state::not_or_first)
? match_set(s, send, cx::next(p), pend, c, equal_to,
detail::match_set_state::not_or_first_in) &&
match(cx::next(s), send,
detail::set_end(
cx::next(p), pend, c,
detail::set_end_state::not_or_first),
pend, c, equal_to)
: c.alt_enabled && *p == c.alt_open &&
detail::is_alt(cx::next(p), pend, c,
detail::is_alt_state::next, 1)
? throw std::runtime_error(
"Sorry, alternatives not implemented")
: s != send && equal_to(*s, *p) &&
match(cx::next(s), send, cx::next(p), pend,
c, equal_to);
#endif
}
template <typename Sequence, typename Pattern, typename EqualTo = cx::equal_to<void>>
constexpr bool match(Sequence&& sequence, Pattern&& pattern,
const cards<container_item_t<Pattern>>& c = cards<container_item_t<Pattern>>(),
const EqualTo& equal_to = EqualTo())
{
return match(cx::cbegin(sequence), cx::cend(std::forward<Sequence>(sequence)),
cx::cbegin(pattern), cx::cend(std::forward<Pattern>(pattern)), c, equal_to);
}
template <typename Sequence, typename Pattern, typename EqualTo = cx::equal_to<void>,
typename = typename std::enable_if<!std::is_same<EqualTo, cards_type>::value>::type>
constexpr bool match(Sequence&& sequence, Pattern&& pattern, const EqualTo& equal_to)
{
return match(std::forward<Sequence>(sequence), std::forward<Pattern>(pattern),
cards<container_item_t<Pattern>>(), equal_to);
}
}
#endif
#endif
