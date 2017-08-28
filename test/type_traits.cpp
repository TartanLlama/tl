#define _cplusplus 201103L

#include "tl/type_traits.hpp"

using namespace tl;


static_assert(std::is_same<remove_cv_t<const volatile int>, int>::value, "wat");
static_assert(std::is_same<remove_const_t<const int>, int>::value, "wat");
static_assert(std::is_same<remove_volatile_t<volatile int>, int>::value, "wat");
static_assert(std::is_same<add_cv_t<int>, const volatile int>::value, "wat");
static_assert(std::is_same<add_const_t<int>, const int>::value, "wat");
static_assert(std::is_same<add_volatile_t<int>, volatile int>::value, "wat");
static_assert(std::is_same<remove_reference_t<int&>, int>::value, "wat");
static_assert(std::is_same<add_lvalue_reference_t<int>, int&>::value, "wat");
static_assert(std::is_same<add_rvalue_reference_t<int>, int&&>::value, "wat");
static_assert(std::is_same<remove_pointer_t<int*>, int>::value, "wat");
static_assert(std::is_same<add_pointer_t<int>, int*>::value, "wat");
static_assert(std::is_same<make_signed_t<unsigned>, int>::value, "wat");
static_assert(std::is_same<make_unsigned_t<int>, unsigned>::value, "wat");
static_assert(std::is_same<remove_extent_t<int[3]>, int>::value, "wat");
static_assert(std::is_same<remove_all_extents_t<int[3][2]>, int>::value, "wat");
static_assert(std::is_same<decay_t<const int[4]>, const int*>::value, "wat");
static_assert(std::is_same<enable_if_t<true>, void>::value, "wat");
static_assert(std::is_same<conditional_t<true,int,float>, int>::value, "wat");
static_assert(std::is_same<common_type_t<int,int>, int>::value, "wat");
enum class test_enum : char {};
static_assert(std::is_same<underlying_type_t<test_enum>, char>::value, "wat");
using func = int(*)(int);
static_assert(std::is_same<result_of_t<func(int)>, int>::value, "wat");

int main() {

}
