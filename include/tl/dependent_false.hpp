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
