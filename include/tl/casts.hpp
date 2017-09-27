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
// Collection of useful casts
///

#include <type_traits>
#include <cstring>

namespace tl {
    namespace detail {
        template <typename T, typename=void>
        struct safe_underlying_type {};

        template <typename T>
        struct safe_underlying_type<T, typename std::enable_if<std::is_enum<T>::value>::type>
            : std::underlying_type<T> {};

        template <typename T>
        using safe_underlying_type_t = typename safe_underlying_type<T>::type;
    }
    
    template <class To, class From>
    To bit_cast (const From& from) {
        static_assert(std::is_trivially_copyable<From>::value, "From must be trivially copyable");
        static_assert(std::is_trivially_copyable<To>::value, "To must be trivially copyable");
        static_assert(sizeof(To) == sizeof(From), "Provided types should have the same size");
    
        To to;
        std::memcpy(&to, &from, sizeof(to));
        return to;
    }

    template <class E>
    detail::safe_underlying_type_t<E>
    underlying_cast (E e) {
        static_assert(std::is_enum<E>::value, "E must be an enum type");
        return static_cast<detail::safe_underlying_type_t<E>>(e);
    }
}
