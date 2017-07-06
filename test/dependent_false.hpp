#include <type_traits>
#include "dependent_false.hpp"

template <class T, typename std::enable_if<std::is_integral<T>::value>::type* = nullptr>
void foo(T t){}

template <class T, typename std::enable_if<!std::is_integral<T>::value>::type* = nullptr>
void foo(T t) {
    static_assert(dependent_false<T>::value, "Not integral");
}

int main() {
    foo(0);
}
