// THIS FILE HAS BEEN GENERATED AUTOMATICALLY. DO NOT EDIT DIRECTLY.
// Generated: 2018-05-09 09:34:45.278048951
// Copyright Tomas Zeman 2018.
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
#ifndef WILDCARDS_HPP
#define WILDCARDS_HPP 
#define WILDCARDS_VERSION_MAJOR 1
#define WILDCARDS_VERSION_MINOR 1
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
: anything{std::move(a)}, single{std::move(s)}, escape{std::move(e)}, enum_enabled{false}
{
}
constexpr cards(T a, T s, T e, T eo, T ec, T ee)
: anything{std::move(a)},
single{std::move(s)},
escape{std::move(e)},
enum_enabled{true},
enum_open{std::move(eo)},
enum_close{std::move(ec)},
enum_exclusion{std::move(ee)}
{
}
T anything;
T single;
T escape;
bool enum_enabled;
T enum_open;
T enum_close;
T enum_exclusion;
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
: enum_enabled{type == cards_type::extended}
{
}
constexpr cards(char a, char s, char e)
: anything{std::move(a)}, single{std::move(s)}, escape{std::move(e)}, enum_enabled{false}
{
}
constexpr cards(char a, char s, char e, char eo, char ec, char ee)
: anything{std::move(a)},
single{std::move(s)},
escape{std::move(e)},
enum_enabled{true},
enum_open{std::move(eo)},
enum_close{std::move(ec)},
enum_exclusion{std::move(ee)}
{
}
char anything{'*'};
char single{'?'};
char escape{'\\'};
bool enum_enabled{true};
char enum_open{'['};
char enum_close{']'};
char enum_exclusion{'!'};
};
template <>
struct cards<char16_t>
{
constexpr cards(cards_type type = cards_type::extended)
: enum_enabled{type == cards_type::extended}
{
}
constexpr cards(char16_t a, char16_t s, char16_t e)
: anything{std::move(a)}, single{std::move(s)}, escape{std::move(e)}, enum_enabled{false}
{
}
constexpr cards(char16_t a, char16_t s, char16_t e, char16_t eo, char16_t ec, char16_t ee)
: anything{std::move(a)},
single{std::move(s)},
escape{std::move(e)},
enum_enabled{true},
enum_open{std::move(eo)},
enum_close{std::move(ec)},
enum_exclusion{std::move(ee)}
{
}
char16_t anything{u'*'};
char16_t single{u'?'};
char16_t escape{u'\\'};
bool enum_enabled{true};
char16_t enum_open{u'['};
char16_t enum_close{u']'};
char16_t enum_exclusion{u'!'};
};
template <>
struct cards<char32_t>
{
constexpr cards(cards_type type = cards_type::extended)
: enum_enabled{type == cards_type::extended}
{
}
constexpr cards(char32_t a, char32_t s, char32_t e)
: anything{std::move(a)}, single{std::move(s)}, escape{std::move(e)}, enum_enabled{false}
{
}
constexpr cards(char32_t a, char32_t s, char32_t e, char32_t eo, char32_t ec, char32_t ee)
: anything{std::move(a)},
single{std::move(s)},
escape{std::move(e)},
enum_enabled{true},
enum_open{std::move(eo)},
enum_close{std::move(ec)},
enum_exclusion{std::move(ee)}
{
}
char32_t anything{U'*'};
char32_t single{U'?'};
char32_t escape{U'\\'};
bool enum_enabled{true};
char32_t enum_open{U'['};
char32_t enum_close{U']'};
char32_t enum_exclusion{U'!'};
};
template <>
struct cards<wchar_t>
{
constexpr cards(cards_type type = cards_type::extended)
: enum_enabled{type == cards_type::extended}
{
}
constexpr cards(wchar_t a, wchar_t s, wchar_t e)
: anything{std::move(a)}, single{std::move(s)}, escape{std::move(e)}, enum_enabled{false}
{
}
constexpr cards(wchar_t a, wchar_t s, wchar_t e, wchar_t eo, wchar_t ec, wchar_t ee)
: anything{std::move(a)},
single{std::move(s)},
escape{std::move(e)},
enum_enabled{true},
enum_open{std::move(eo)},
enum_close{std::move(ec)},
enum_exclusion{std::move(ee)}
{
}
wchar_t anything{L'*'};
wchar_t single{L'?'};
wchar_t escape{L'\\'};
bool enum_enabled{true};
wchar_t enum_open{L'['};
wchar_t enum_close{L']'};
wchar_t enum_exclusion{L'!'};
};
template <typename T>
constexpr cards<T> make_cards(T&& c1, T&& c2)
{
return {std::forward<T>(c1), std::forward<T>(c2)};
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
constexpr bool throw_logic_error(const char* what_arg)
{
return what_arg == nullptr ? false : throw std::logic_error(what_arg);
}
#endif
enum class is_enum_state
{
open,
exclusion_or_first_item,
first_item,
next_item
};
template <typename PatternIterator>
constexpr bool is_enum(
PatternIterator p, PatternIterator pend,
const cards<iterated_item_t<PatternIterator>>& c = cards<iterated_item_t<PatternIterator>>(),
is_enum_state state = is_enum_state::open)
{
#if cfg_HAS_CONSTEXPR14
if (!c.enum_enabled || p == pend)
{
return false;
}
switch (state)
{
case is_enum_state::open:
if (*p == c.enum_open)
{
return is_enum(cx::next(p), pend, c, is_enum_state::exclusion_or_first_item);
}
return false;
case is_enum_state::exclusion_or_first_item:
if (*p == c.enum_exclusion)
{
return is_enum(cx::next(p), pend, c, is_enum_state::first_item);
}
return is_enum(cx::next(p), pend, c, is_enum_state::next_item);
case is_enum_state::first_item:
return is_enum(cx::next(p), pend, c, is_enum_state::next_item);
case is_enum_state::next_item:
if (*p == c.enum_close)
{
return true;
}
return is_enum(cx::next(p), pend, c, is_enum_state::next_item);
default:
#if cfg_HAS_FULL_FEATURED_CONSTEXPR_SWITCH
throw std::logic_error(
"The program execution should never end up here trowing this exception");
#else
return throw_logic_error(
"The program execution should never end up here trowing this exception");
#endif
}
#else
return c.enum_enabled && p != pend &&
(state == is_enum_state::open
? *p == c.enum_open &&
is_enum(cx::next(p), pend, c, is_enum_state::exclusion_or_first_item)
:
state == is_enum_state::exclusion_or_first_item
? *p == c.enum_exclusion
? is_enum(cx::next(p), pend, c, is_enum_state::first_item)
: is_enum(cx::next(p), pend, c, is_enum_state::next_item)
: state == is_enum_state::first_item
? is_enum(cx::next(p), pend, c, is_enum_state::next_item)
: state == is_enum_state::next_item
? *p == c.enum_close ||
is_enum(cx::next(p), pend, c, is_enum_state::next_item)
: throw std::logic_error("The program execution should never end up "
"here trowing this exception"));
#endif
}
#if !cfg_HAS_FULL_FEATURED_CONSTEXPR_SWITCH
constexpr bool throw_invalid_argument(const char* what_arg)
{
return what_arg == nullptr ? false : throw std::invalid_argument(what_arg);
}
#endif
enum class match_enum_state
{
open,
exclusion_or_first_in_item,
first_out_item,
skip_next_in_item,
next_in_item,
next_out_item
};
template <typename SequenceIterator, typename PatternIterator,
typename EqualTo = cx::equal_to<void>>
constexpr bool match_enum(
SequenceIterator s, SequenceIterator send, PatternIterator p, PatternIterator pend,
const cards<iterated_item_t<PatternIterator>>& c = cards<iterated_item_t<PatternIterator>>(),
const EqualTo& equal_to = EqualTo(), match_enum_state state = match_enum_state::open)
{
#if cfg_HAS_CONSTEXPR14
if (!c.enum_enabled)
{
#if cfg_HAS_FULL_FEATURED_CONSTEXPR_SWITCH
throw std::invalid_argument("The use of enums is disabled");
#else
return throw_invalid_argument("The use of enums is disabled");
#endif
}
if (p == pend)
{
#if cfg_HAS_FULL_FEATURED_CONSTEXPR_SWITCH
throw std::invalid_argument("The given pattern is not a valid enum");
#else
return throw_invalid_argument("The given pattern is not a valid enum");
#endif
}
switch (state)
{
case match_enum_state::open:
if (*p == c.enum_open)
{
return match_enum(s, send, cx::next(p), pend, c, equal_to,
match_enum_state::exclusion_or_first_in_item);
}
#if cfg_HAS_FULL_FEATURED_CONSTEXPR_SWITCH
throw std::invalid_argument("The given pattern is not a valid enum");
#else
return throw_invalid_argument("The given pattern is not a valid enum");
#endif
case match_enum_state::exclusion_or_first_in_item:
if (*p == c.enum_exclusion)
{
return match_enum(s, send, cx::next(p), pend, c, equal_to,
match_enum_state::first_out_item);
}
if (s == send)
{
return false;
}
if (equal_to(*s, *p))
{
return match_enum(s, send, cx::next(p), pend, c, equal_to,
match_enum_state::skip_next_in_item);
}
return match_enum(s, send, cx::next(p), pend, c, equal_to, match_enum_state::next_in_item);
case match_enum_state::first_out_item:
if (s == send || equal_to(*s, *p))
{
return false;
}
return match_enum(s, send, cx::next(p), pend, c, equal_to, match_enum_state::next_out_item);
case match_enum_state::skip_next_in_item:
if (*p == c.enum_close)
{
if (s == send)
{
return true;
}
return match(cx::next(s), send, cx::next(p), pend, c, equal_to);
}
return match_enum(s, send, cx::next(p), pend, c, equal_to, state);
case match_enum_state::next_in_item:
if (*p == c.enum_close || s == send)
{
return false;
}
if (equal_to(*s, *p))
{
return match_enum(s, send, cx::next(p), pend, c, equal_to,
match_enum_state::skip_next_in_item);
}
return match_enum(s, send, cx::next(p), pend, c, equal_to, state);
case match_enum_state::next_out_item:
if (*p == c.enum_close)
{
if (s == send)
{
return true;
}
return match(cx::next(s), send, cx::next(p), pend, c, equal_to);
}
if (s == send || equal_to(*s, *p))
{
return false;
}
return match_enum(s, send, cx::next(p), pend, c, equal_to, state);
default:
#if cfg_HAS_FULL_FEATURED_CONSTEXPR_SWITCH
throw std::logic_error(
"The program execution should never end up here trowing this exception");
#else
return throw_logic_error(
"The program execution should never end up here trowing this exception");
#endif
}
#else
return !c.enum_enabled
? throw std::invalid_argument("The use of enums is disabled")
: p == pend
? throw std::invalid_argument("The given pattern is not a valid enum")
: state == match_enum_state::open
? *p == c.enum_open
? match_enum(s, send, cx::next(p), pend, c, equal_to,
match_enum_state::exclusion_or_first_in_item)
:
throw std::invalid_argument("The given pattern is not a valid enum")
:
state == match_enum_state::exclusion_or_first_in_item
? *p == c.enum_exclusion
? match_enum(s, send, cx::next(p), pend, c, equal_to,
match_enum_state::first_out_item)
:
s != send &&
(equal_to(*s, *p)
? match_enum(s, send, cx::next(p), pend, c, equal_to,
match_enum_state::skip_next_in_item)
:
match_enum(s, send, cx::next(p), pend, c, equal_to,
match_enum_state::next_in_item))
:
state == match_enum_state::first_out_item
? s != send && !equal_to(*s, *p) &&
match_enum(s, send, cx::next(p), pend, c, equal_to,
match_enum_state::next_out_item)
:
state == match_enum_state::skip_next_in_item
? *p == c.enum_close
?
s == send || match(cx::next(s), send, cx::next(p), pend,
c, equal_to)
:
match_enum(s, send, cx::next(p), pend, c, equal_to,
state)
:
state == match_enum_state::next_in_item
? *p != c.enum_close && s != send &&
(equal_to(*s, *p)
?
match_enum(s, send, cx::next(p), pend, c,
equal_to,
match_enum_state::skip_next_in_item)
:
match_enum(s, send, cx::next(p), pend, c,
equal_to, state))
:
state == match_enum_state::next_out_item
? *p == c.enum_close
?
s == send ||
match(cx::next(s), send, cx::next(p), pend,
c, equal_to)
:
s != send && !equal_to(*s, *p) &&
match_enum(s, send, cx::next(p), pend, c,
equal_to, state)
: throw std::logic_error(
"The program execution should never end up here "
"trowing this exception");
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
if (c.enum_enabled && *p == c.enum_open &&
detail::is_enum(cx::next(p), pend, c, detail::is_enum_state::exclusion_or_first_item))
{
return match_enum(s, send, cx::next(p), pend, c, equal_to,
detail::match_enum_state::exclusion_or_first_in_item);
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
: c.enum_enabled && *p == c.enum_open &&
detail::is_enum(
cx::next(p), pend, c,
detail::is_enum_state::exclusion_or_first_item)
? match_enum(s, send, cx::next(p), pend, c, equal_to,
detail::match_enum_state::
exclusion_or_first_in_item)
: s != send && equal_to(*s, *p) &&
match(cx::next(s), send, cx::next(p), pend, c,
equal_to);
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
