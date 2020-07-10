///
// TL library - A collection of small C++ utilities
// Written in 2017 by Simon Brand (@TartanLlama)
//
// To the extent possible under law, the author(s) have dedicated all
// copyright and related and neighboring rights to this software to the
// public domain worldwide. This software is distributed without any warranty.
//
// You should have received a copy of the CC0 Public Domain Dedication
// along with this software. If not, see <http://creativecommons.org/publicdomain/zero/1.0/>.
///
// An implementation of decay_copy: http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2011/n3255.html
///
#ifndef TL_DECAY_COPY_HPP
#define TL_DECAY_COPY_HPP
#include <type_traits>
#include <utility>

namespace tl {
    template <class T>
    typename std::decay<T>::type
    decay_copy (T&& t) {
        return std::forward<T>(t);
    }
}
#endif