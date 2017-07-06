cmake_minimum_required (VERSION 3.1)
project (tl)

set (CMAKE_CXX_STANDARD 14)

include_directories (include)

enable_testing()

function (tl_test name)
  add_executable (test_${name} test/${name}.cpp)
  add_test (${name} test_${name})
endfunction()

tl_test(integer_sequence)
tl_test(overload)
tl_test(dependent_false)
tl_test(type_traits)
tl_test(make_array)
