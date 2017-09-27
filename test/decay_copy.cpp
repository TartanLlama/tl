#include <cassert>

#include "tl/decay_copy.hpp"

bool run = false;

struct foo {
    foo() = default;
    foo(const foo&) = default;
    foo(const foo&&) {
        run = true;
    }
};

int main() {
    foo a;
    tl::decay_copy(std::move(a));
    assert(run == true);
}
