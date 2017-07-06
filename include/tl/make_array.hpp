#include <array>
#include <type_traits>
#include <utility>

namespace tl {
    template <class... Ts>
    constexpr std::array<typename std::decay<typename std::common_type<Ts...>::type>::type, sizeof...(Ts)>
    make_array(Ts&&... ts) {
        return std::array<typename std::decay<typename std::common_type<Ts...>::type>::type, sizeof...(Ts)>{ std::forward<Ts>(ts)... };
    }
}
