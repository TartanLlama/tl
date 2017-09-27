#include <cassert>

#include "tl/casts.hpp"

struct foo {
    int i;
};

enum class e {
    a
};

int main() {
    int i = 42;
    auto f = tl::bit_cast<foo>(i);
    assert (i == f.i);

    auto en = e::a;
    auto c = tl::underlying_cast(en);
    static_assert(std::is_same<decltype(c), int>::value, "wat");
    assert (c == static_cast<int>(en));
}
