cmake_minimum_required(VERSION 3.11)

project(tl-misc VERSION 1.0.0 LANGUAGES CXX)

option(TL_ENABLE_TESTS "Enable tests." ON)

include(FetchContent)
FetchContent_Declare(
  tl_cmake
  GIT_REPOSITORY https://github.com/TartanLlama/tl-cmake.git
)
FetchContent_GetProperties(tl_cmake)
if(NOT tl_cmake_POPULATED)
  FetchContent_Populate(tl_cmake)
  set(CMAKE_MODULE_PATH ${tl_cmake_SOURCE_DIR} ${CMAKE_MODULE_PATH})
endif()
include(add-tl)

tl_add_library(misc SOURCES 
                include/tl/apply.hpp
                include/tl/casts.hpp
                include/tl/decay_copy.hpp
                include/tl/dependent_false.hpp
                include/tl/integer_sequence.hpp
                include/tl/make_array.hpp
                include/tl/numeric_aliases.hpp
                include/tl/overload.hpp
                include/tl/tl.hpp
                include/tl/type_traits.hpp
                include/tl/typelist.hpp)

if(TL_ENABLE_TESTS)
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
  tl_test(apply)
  tl_test(decay_copy)
  tl_test(casts)
endif()
