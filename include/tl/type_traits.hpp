// Implementations of some type traits from C++17 and Lib Fundamentals v2 TS

#ifndef TL_TYPE_TRAITS_HPP
#define TL_TYPE_TRAITS_HPP

#include <utility>
#include <type_traits>

namespace tl {
    template <bool B>
    using bool_constant = std::integral_constant<bool, B>;

    template <bool B>
    using index_constant = std::integral_constant<std::size_t, B>;

    template <class...> struct conjunction : std::true_type { };
    template <class B> struct conjunction<B> : B { };
    template <class B, class... Bs>
    struct conjunction<B, Bs...>
        : typename std::conditional<bool(B::value), conjunction<Bs...>, B>::type {};

    template <class...> struct disjunction : std::false_type { };
    template <class B> struct disjunction<B> : B { };
    template <class B, class... Bs>
    struct disjunction<B, Bs...>
        : typename std::conditional_t<bool(B::value), B, disjunction<Bs...>>::type {};

    template <class B>
    struct negation : bool_constant<!bool(B::value)> { };

    namespace detail {
        template<class... Ts> voider { using type = void; };
    }

    template <class... Ts>
    using void_t = typename voider<Ts...>::type;

    namespace detail {
        template <template <class...> class Trait, class Enabler, class... Args>
        struct is_detected : std::false_type{};

        template <template <class...> class Trait, class... Args>
        struct is_detected<Trait, void_t<Trait<Args...>>>, Args...> : std::true_type{};
    }

    template <template <class...> class Trait, class... Args>
    using is_detected = typename detail::is_detected<Trait, void, Args...>::type;

    template <class Pack>
    struct variadic_size;

    template <template <class...> class Wrapper, class... Ts>
    struct variadic_size<Wrapper<Ts...>> : index_constant<std::size_t, sizeof...(Ts)>;
}

#endif
