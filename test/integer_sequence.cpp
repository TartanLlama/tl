#include "tl/integer_sequence.hpp"
#include <type_traits>

int main() {
    static_assert(std::is_same<tl::make_index_sequence<10>,
                               tl::index_sequence<0,1,2,3,4,5,6,7,8,9>>::value,
                  "make_index_sequence test failed");

    static_assert(std::is_same<tl::make_index_range<3,5>, tl::index_sequence<3,4,5,6,7>>::value,
                  "make_index_range test failed");
}
