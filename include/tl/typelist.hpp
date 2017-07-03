#ifndef TL_TYPELIST_HPP
#define TL_TYPELIST_HPP

namespace tl {
    template <class... Ts> struct typelist{};

    // Given a typelist and an index, stores the Nth type in the list as a member alias
    // Assumes that the list is long enough
    template <class List, size_t N>
    struct index_typelist;

    // Recursive case
    template <template <class...> class List, class T, class... Ts, size_t N>
    struct index_typelist<List<T,Ts...>, N> {
        using type = typename index_typelist<List<Ts...>, N-1>::type;
    };

    // Found the type
    template <template <class...> class List, class T, class... Ts>
    struct index_typelist<List<T,Ts...>, 0> {
        using type = T;
    };

    // Concatenates two typelists
    template <class List1, class List2>
    struct cat_typelist;

    template <template <class...> class List, class... Ts, auto... Us>
    struct cat_typelist<List<Ts...>, List<Us...>> {
        using type = List<Ts...,Us...>;
    };

#if __cplusplus >= 201703L
    template <auto... Ts> struct vallist{};

    // Given a list of non-type template params and an index, stores the Nth type in the list as static data member
    // Assumes that the list is long enough
    template <class List, size_t N>
    struct index_vallist;

    // Recursive case
    template <template <auto...> class List, auto T, auto... Ts, size_t N>
    struct index_vallist<List<T,Ts...>, N> {
        static constexpr auto value = index_vallist<List<Ts...>, N-1>::value;
    };

    // Found the value
    template <template <auto...> class List, auto T, auto... Ts>
    struct index_vallist<List<T,Ts...>, 0> {
        static constexpr auto value = T;
    };

    // Concatenates two vallists
    template <class List1, class List2>
    struct cat_vallist;

    template <template <auto...> class List, auto... Ts, auto... Us>
    struct cat_vallist<List<Ts...>, List<Us...>> {
        using type = List<Ts...,Us...>;
    };
#endif
}

#endif
