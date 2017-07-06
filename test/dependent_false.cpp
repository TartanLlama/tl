#include <type_traits>
#include "tl/dependent_false.hpp"

template <class T, std::enable_if_t<std::is_integral<T>::value>* = nullptr>
void foo(T t){}

template <class T, std::enable_if_t<!std::is_integral<T>::value>* = nullptr>
void foo(T t) {
    static_assert(tl::dependent_false<T>::value, "Not integral");
}

int main() {
    foo(0);
}
