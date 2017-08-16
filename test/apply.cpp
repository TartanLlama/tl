#include <string>
#include <cassert>

#include "tl/apply.hpp"

std::string append_int(std::string s, int i) {
    return s + std::to_string(i);
}

int main() {
    auto s = tl::apply(append_int, std::make_tuple("hi ", 42));
    assert (s == "hi 42");
}
