#include "tl/overload.hpp"
#include <cassert>

int main() {
    auto dispatcher = tl::overload(
        [](int i) { return 42; },
        [](char const* f) { return 24; }
    );

    assert(dispatcher(0) == 42);
    assert(dispatcher("hi") == 24);
}
