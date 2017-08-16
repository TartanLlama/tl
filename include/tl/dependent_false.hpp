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
// Dependent false allows using unconditional static_assert failures.
// Example:
//    static_assert(dependent_false<T>::value, "Failed");
///


#ifndef TL_DEPENDENT_FALSE_HPP
#define TL_DEPENDENT_FALSE_HPP

#include <utility>

namespace tl {
    namespace detail {
        class class_with_a_really_long_name_that_you_should_not_use{};
    }

    template <class T>
    struct dependent_false : std::false_type{};

    template<>
    struct dependent_false<detail::class_with_a_really_long_name_that_you_should_not_use> : std::true_type{};
}



#endif
