# tl
A bunch of small C++ utilities

[![Linux Build Status](https://travis-ci.org/TartanLlama/tl.png?branch=master)](https://travis-ci.org/TartanLlama/tl)

- [`overload`](https://github.com/TartanLlama/tl/blob/master/include/tl/overload.hpp): a rudimentary implementation of [`std::overload`](http://open-std.org/JTC1/SC22/WG21/docs/papers/2016/p0051r2.pdf)
- [`integer_sequence`](https://github.com/TartanLlama/tl/blob/master/include/tl/integer_sequence.hpp): C++11 version of [`std::integer_sequence`](http://en.cppreference.com/w/cpp/utility/integer_sequence) and friends, plus `tl::make_index_range`
- [`type_traits`](https://github.com/TartanLlama/tl/blob/master/include/tl/type_traits.hpp): implementations of some type traits from C++17 and Lib Fundamentals v2 TS
  - [`std::bool_constant`](http://en.cppreference.com/w/cpp/types/integral_constant)
  - [`std::conjunction`](http://en.cppreference.com/w/cpp/types/conjunction)
  - [`std::disjunction`](http://en.cppreference.com/w/cpp/types/disjunction)
  - [`std::negation`](http://en.cppreference.com/w/cpp/types/negation)
  - [`std::void_t`](http://en.cppreference.com/w/cpp/types/void_t)
  - [`std::is_detected`](http://en.cppreference.com/w/cpp/experimental/is_detected)
  - `index_constant`
  - `variadic_size`
- [`typelist`](https://github.com/TartanLlama/tl/blob/master/include/tl/typelist.hpp): utilities for type lists
  - `typelist`
  - `index_typelist`
  - `cat_typelist`
  - `vallist` (C++17)
  - `index_vallist` (C++17)
  - `cat_vallist` (C++17)
 - [`dependent_false`](https://github.com/TartanLlama/tl/blob/master/include/tl/dependent_false.hpp): enables `static_assert(dependent_false<T>::value)` in templates
 - [`make_array`](https://github.com/TartanLlama/tl/blob/master/include/tl/make_array.hpp): simple implementation of [`std::make_array`](http://en.cppreference.com/w/cpp/experimental/make_array)
 - [`numeric_aliases`](https://github.com/TartanLlama/tl/blob/master/include/tl/numeric_aliases.hpp): Rust-style numeric aliases, e.g. `tl::i8`, `tl::u64`
- [`apply`](https://github.com/TartanLlama/tl/blob/master/include/tl/numeric_aliases.hpp): Implementation of [`std::apply`](http://en.cppreference.com/w/cpp/utility/apply)
