cmake_minimum_required (VERSION 3.1)
project (tl)

set (CMAKE_CXX_STANDARD 14)

include_directories (include)

enable_testing()

add_executable (test_integer_sequence test/integer_sequence.cpp)
add_test (integer_sequence test_integer_sequence)

add_executable (test_overload test/overload.cpp)
add_test (overload test_overload)
