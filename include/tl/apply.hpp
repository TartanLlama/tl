// An implementation of std::apply

#ifndef TL_APPLY_HPP
#define TL_APPLY_HPP

#include <tuple>

#if __cplusplus >= 201402L
#include <utility>
#define INDEX_NAMESPACE std
#else
#include "integer_sequence.hpp"
#define INDEX_NAMESPACE tl
#endif

#define DEDUCE_RETURN(EXPR) -> decltype(EXPR) { return EXPR; }

namespace tl {
    template <class F, class Tuple, std::size_t... Idx>
    auto apply(F&& f, Tuple&& tuple, INDEX_NAMESPACE::index_sequence<Idx...>) DEDUCE_RETURN(
        std::forward<F>(f)(std::get<Idx>(std::forward<Tuple>(tuple))...)
    )

    template <class F, class Tuple>
    auto apply(F&& f, Tuple&& tuple) DEDUCE_RETURN(
        apply(std::forward<F>(f), std::forward<Tuple>(tuple),
              INDEX_NAMESPACE::make_index_sequence<
                  std::tuple_size<typename std::decay<Tuple>::type>::value
              >{})
    )
}

#endif
