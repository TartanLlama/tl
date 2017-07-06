#include "tl/make_array.hpp"
#include <cassert>

int main() {
    auto arr = tl::make_array(1, 12, 42l);
    static_assert(std::is_same<decltype(arr), std::array<long,3>>::value, "Failed");
    assert(arr[0] == 1);
    assert(arr[1] == 12);
    assert(arr[2] == 42l);
}
