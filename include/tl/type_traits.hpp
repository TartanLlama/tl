///
// TL library - A collection of small C++ utilities
// Written in 2017 by Simon Brand (@TartanLlama)
//
// To the extent possible under law, the author(s) have dedicated all
// copyright and related and neighboring rights to this software to the
// public domain worldwide. This software is distributed without any warranty.
//
// You should have received a copy of the CC0 Public Domain Dedication
// along with this software. If not, see <http://creativecommons.org/publicdomain/zero/1.0/>.
///
// Implementations of some type traits from C++17 and Lib Fundamentals v2 TS
// C++14-style type aliases for C++11
///

#ifndef TL_TYPE_TRAITS_HPP
#define TL_TYPE_TRAITS_HPP

#include <utility>
#include <type_traits>

namespace tl {
    template <bool B>
    using bool_constant = std::integral_constant<bool, B>;

    template <std::size_t N>
    using index_constant = std::integral_constant<std::size_t, N>;

    template <class...> struct conjunction : std::true_type { };
    template <class B> struct conjunction<B> : B { };
    template <class B, class... Bs>
    struct conjunction<B, Bs...>
        : std::conditional<bool(B::value), conjunction<Bs...>, B>::type {};

    template <class...> struct disjunction : std::false_type { };
    template <class B> struct disjunction<B> : B { };
    template <class B, class... Bs>
    struct disjunction<B, Bs...>
        : std::conditional<bool(B::value), B, disjunction<Bs...>>::type {};

    template <class B>
    struct negation : bool_constant<!bool(B::value)> { };

    namespace detail {
        template<class... Ts> struct voider { using type = void; };
    }

    template <class... Ts>
    using void_t = typename detail::voider<Ts...>::type;

    namespace detail {
        template <template <class...> class Trait, class Enabler, class... Args>
        struct is_detected : std::false_type{};

        template <template <class...> class Trait, class... Args>
        struct is_detected<Trait, void_t<Trait<Args...>>, Args...> : std::true_type{};
    }

    template <template <class...> class Trait, class... Args>
    using is_detected = typename detail::is_detected<Trait, void, Args...>::type;

    template <class Pack>
    struct variadic_size;

    template <template <class...> class Wrapper, class... Ts>
    struct variadic_size<Wrapper<Ts...>> : index_constant<sizeof...(Ts)> {};

    template <class T> using remove_cv_t = typename std::remove_cv<T>::type;
    template <class T> using remove_const_t = typename std::remove_const<T>::type;
    template <class T> using remove_volatile_t = typename std::remove_volatile<T>::type;
    template <class T> using add_cv_t = typename std::add_cv<T>::type;
    template <class T> using add_const_t = typename std::add_const<T>::type;
    template <class T> using add_volatile_t = typename std::add_volatile<T>::type;
    template <class T> using remove_reference_t = typename std::remove_reference<T>::type;
    template <class T> using add_lvalue_reference_t = typename std::add_lvalue_reference<T>::type;
    template <class T> using add_rvalue_reference_t = typename std::add_rvalue_reference<T>::type;
    template <class T> using remove_pointer_t = typename std::remove_pointer<T>::type;
    template <class T> using add_pointer_t = typename std::add_pointer<T>::type;
    template <class T> using make_signed_t = typename std::make_signed<T>::type;
    template <class T> using make_unsigned_t = typename std::make_unsigned<T>::type;
    template <class T> using remove_extent_t = typename std::remove_extent<T>::type;
    template <class T> using remove_all_extents_t = typename std::remove_all_extents<T>::type;
    template <std::size_t N, std::size_t A=N> using aligned_storage_t = typename std::aligned_storage<N,A>::type;
    template <std::size_t N, class... Ts> using aligned_union_t = typename std::aligned_union<N,Ts...>::type;
    template <class T> using decay_t = typename std::decay<T>::type;
    template <bool E, class T=void> using enable_if_t = typename std::enable_if<E,T>::type;
    template <bool B, class T, class F> using conditional_t = typename std::conditional<B,T,F>::type;
    template <class... Ts> using common_type_t = typename std::common_type<Ts...>::type;
    template <class T> using underlying_type_t = typename std::underlying_type<T>::type;
    template <class T> using result_of_t = typename std::result_of<T>::type;

    template <typename T, typename=void>
    struct safe_underlying_type {};

    template <typename T>
    struct safe_underlying_type<T, enable_if_t<std::is_enum<T>::value>>
        : std::underlying_type<T> {};

    template <typename T>
    using safe_underlying_type_t = typename safe_underlying_type<T>::type;
    
}
#endif
