#include <functional>
#include <utility>
#include <numeric>
#include <iostream> 
#include "callable_traits.hpp"

template <class T, std::size_t Offset, std::size_t... Idx>
std::integer_sequence<T, (Idx + Offset)...> offset_integer_sequence(
    std::integer_sequence<T, Idx...>);

template <std::size_t From, std::size_t N>
using make_index_range = decltype(
    offset_integer_sequence<std::size_t, From>(std::make_index_sequence<N>{}));

template <class F, std::size_t... Idx, class Tup>
decltype(auto) apply_sequence(F&& f, std::index_sequence<Idx...>, Tup&& tup) {
    return std::invoke(std::forward<F>(f), std::get<Idx>(std::forward<Tup>(tup))...);
}


template <auto...> struct vallist{};
     
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

template <std::size_t... Is>
struct partial_sum {
    template <class List, std::size_t... Idx>
    static auto sum(std::index_sequence<Idx...>)
        -> std::integral_constant<int, (0 + ... + (index_vallist<List, Idx>::value))>;
    
    template <class List, std::size_t... Idx>
    static auto helper (std::index_sequence<Idx...>)
        -> vallist<decltype(sum<List>(std::make_index_sequence<Idx>{}))::value...>;
    using type = decltype(helper<vallist<Is...>>(std::make_index_sequence<sizeof...(Is)>{}));
};

template <class... Fs, class Tup, std::size_t... Idx, auto... Size, auto... Start>
void make_func_helper(Tup&& tup,  std::index_sequence<Idx...>, vallist<Size...>,
                      vallist<Start...>, Fs&&... fs) {
    auto funcs = std::forward_as_tuple(std::forward<Fs>(fs)...);
    (apply_sequence(std::get<Idx>(funcs), make_index_range<Start, Size>{}, tup), ...);
}

template <class... Fs>
auto make_func(Fs&&... fs) {
    using sizes = vallist<callable_traits<Fs>::n_params...>;
    using starts = typename partial_sum<callable_traits<Fs>::n_params...>::type;
    return [=](auto&&... args) {
        auto tup = std::forward_as_tuple(std::forward<decltype(args)>(args)...);
        make_func_helper(tup, std::index_sequence_for<Fs...>{}, sizes{}, starts{}, fs...);
    };
}
void l1 (int a) {
  std::cout << "Calling l1 with " << a <<'\n';
};

struct foo {
    int a;
    void l2(int b) { std::cout << "Calling l2 with " << a << b << '\n'; }
};

int main () {
    auto l3 = [=](int a) {
        std::cout << "Calling l3 with " << a << '\n';
    };
    auto comp = make_func(l1, &foo::l2, l3)
    foo a {42};
    comp(0,a,1,2);
}
