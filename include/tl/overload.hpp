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
// A rudimentary implementation of std::overload
// http://open-std.org/JTC1/SC22/WG21/docs/papers/2016/p0051r2.pdf
//
// This allows in-place visitation of variant types
//
// Example:
//     variant<int,float,std::string> my_variant;
//     auto do_something = overload(
//         [](int i) { /* do something with int */ },
//         [](float f) { /* do something with float */ },
//         [](std::string s) { /* do something with string */ }
//     );
//     visit(do_something, my_variant);
///

#ifndef TL_OVERLOAD_HPP
#define TL_OVERLOAD_HPP

#include <utility>

namespace tl {
    namespace detail {
        template <class... Ts>
        struct overloader;

        template <>
        struct overloader<> {};

        template <class T, class... Ts>
        struct overloader<T, Ts...> : T, overloader<Ts...> {
            using T::operator();

            template <class U, class... Us>
            overloader(U&& u, Us&&... us)
                : T{std::forward<U>(u)}, overloader<Ts...>{std::forward<Us>(us)...} {}
        };
    }

    template <class... Ts>
    auto overload(Ts&&... ts) {
        return detail::overloader<typename std::decay<Ts>::type...>{std::forward<Ts>(ts)...};
    }
}

#endif
