// THIS FILE HAS BEEN GENERATED AUTOMATICALLY. DO NOT EDIT DIRECTLY.
// Generated: 2018-04-20 07:58:19.878033941
// Copyright Tomas Zeman 2018.
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
#ifndef WILDCARDS_HPP
#define WILDCARDS_HPP 
#define WILDCARDS_VERSION_MAJOR 0
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
constexpr cards(T a, T q, T e)
: asterisk{std::move(a)}, question_mark{std::move(q)}, escape{std::move(e)}
{
}
T asterisk;
T question_mark;
T escape;
};
template <>
struct cards<char>
{
constexpr cards()
{
}
constexpr cards(char a, char q, char e)
: asterisk{std::move(a)}, question_mark{std::move(q)}, escape{std::move(e)}
{
}
char asterisk{'*'};
char question_mark{'?'};
char escape{'\\'};
};
template <>
struct cards<char16_t>
{
constexpr cards()
{
}
constexpr cards(char16_t a, char16_t q, char16_t e)
: asterisk{std::move(a)}, question_mark{std::move(q)}, escape{std::move(e)}
{
}
char16_t asterisk{u'*'};
char16_t question_mark{u'?'};
char16_t escape{u'\\'};
};
template <>
struct cards<char32_t>
{
constexpr cards()
{
}
constexpr cards(char32_t a, char32_t q, char32_t e)
: asterisk{std::move(a)}, question_mark{std::move(q)}, escape{std::move(e)}
{
}
char32_t asterisk{U'*'};
char32_t question_mark{U'?'};
char32_t escape{U'\\'};
};
template <>
struct cards<wchar_t>
{
constexpr cards()
{
}
constexpr cards(wchar_t a, wchar_t q, wchar_t e)
: asterisk{std::move(a)}, question_mark{std::move(q)}, escape{std::move(e)}
{
}
wchar_t asterisk{L'*'};
wchar_t question_mark{L'?'};
wchar_t escape{L'\\'};
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
#define cfg_HAS_CONSTEXPR14 __cpp_constexpr >= 201304
#if cfg_HAS_CONSTEXPR14
#define cfg_constexpr14 constexpr
#else
#define cfg_constexpr14 
#endif
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
template <typename SequenceIterator, typename PatternIterator>
constexpr bool match(SequenceIterator s, SequenceIterator send, PatternIterator p,
PatternIterator pend, const cards<iterated_item_t<PatternIterator>>& c,
bool escape = false)
{
#if cfg_HAS_CONSTEXPR14
if (p == pend)
{
return s == send;
}
if (!escape && *p == c.escape)
{
return match(s, send, cx::next(p), pend, c, true);
}
if (escape || *p != c.asterisk)
{
if (s == send)
{
return false;
}
if ((!escape && *p == c.question_mark) || *s == *p)
{
return match(cx::next(s), send, cx::next(p), pend, c, false);
}
return false;
}
return match(s, send, cx::next(p), pend, c, false) ||
((s != send) && match(cx::next(s), send, p, pend, c, false));
#else
return p == pend ? s == send
: !escape && *p == c.escape
? match(s, send, cx::next(p), pend, c, true)
:
escape || *p != c.asterisk
? s != send && ((!escape && *p == c.question_mark) || *s == *p) &&
match(cx::next(s), send, cx::next(p), pend, c, false)
:
match(s, send, cx::next(p), pend, c, false) ||
((s != send) && match(cx::next(s), send, p, pend, c, false));
#endif
}
template <typename Sequence, typename Pattern>
constexpr bool match(Sequence&& sequence, Pattern&& pattern,
const cards<container_item_t<Pattern>>& c = cards<container_item_t<Pattern>>())
{
return match(cx::begin(std::forward<Sequence>(sequence)),
cx::end(std::forward<Sequence>(sequence)), cx::begin(std::forward<Pattern>(pattern)),
cx::end(std::forward<Pattern>(pattern)), c);
}
}
#endif
#endif
