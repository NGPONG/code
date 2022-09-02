#include <iostream>
#include <string_view>
#include <array>
#include <algorithm>

namespace  variadic_toolbox
{
  template<unsigned  count,
    template<unsigned...> class  meta_functor, unsigned...  indices>
  struct  apply_range
  {
    typedef  typename apply_range<count - 1, meta_functor, count - 1, indices...>::result  result;
  };
 
  template<template<unsigned...> class  meta_functor, unsigned...  indices>
  struct  apply_range<0, meta_functor, indices...>
  {
    typedef  typename meta_functor<indices...>::result  result;
  };
}
 
namespace  compile_time
{
  template<char...  str>
  struct  string
  {
    static  constexpr  const char  chars[] = { str..., '\0' };
  };
 
  template<char...  str>
  constexpr  const char string<str...>::chars[];
 
  template<typename  lambda_str_type>
  struct  string_builder
  {
    template<unsigned... indices>
    struct  produce
    {
      typedef  string<lambda_str_type {}.chars[indices]...>  result;
    };
  };
 
  template<char...  str0, char...  str1>
  string<str0..., str1...>  operator+(string<str0...>, string<str1...>)
  {
    return {};
  }
}
 
#define  CSTRING(string_literal)                                                        \
    []{                                                                                 \
        struct  constexpr_string_type { const char * chars = string_literal; };         \
        return  variadic_toolbox::apply_range<sizeof(string_literal)-1,                 \
            compile_time::string_builder<constexpr_string_type>::produce>::result{};    \
    }()

template <typename T> 
constexpr bool ngpong_check(const T *array, std::size_t size)
{
    for (std::size_t i = 0; i < size; i++)
      if (array[i] == 1)
        return true;
    return false;
}

constexpr bool foo(const std::string_view s) {
  constexpr std::size_t size = 3;

  constexpr auto axis = [] () {
      return std::array<std::string_view, 3> {
        "hello,world!",
        "NGPONG",
        "WHAT THE FUNCK"
      };
  }();

  for (std::size_t i = 0; i < size; i++)
    if (axis[i] == s)
      return true;
  return false;
}

void my_test() {
  // auto str_hello = CSTRING(str);
  // if constexpr (foo(str_hello.chars)) {
  //   std::cout << "hello,world!" << std::endl;
  // }
}

template <std::size_t N>
constexpr std::string_view make_string_view(const char* s) { 
  return {s, N - 1};
}

int main(void) {
  constexpr std::string_view sv = make_string_view<12>("");

  // constexpr int32_t asize = 10;

  // static constexpr std::array<double, asize> axis = [] {
  //   auto a = decltype(axis){};
  //   for (int i = 0; i < asize; ++i) {
  //     a[i] = i;
  //   }

  //   return a;
  // }();

  // if constexpr (ngpong_check(axis.data(), 4)) {
  //   std::cout << "hello,world!" << std::endl;
  // }

  // if constexpr (std::find(axis.begin(), axis.end(), 1) != axis.end()) {
  //   std::cout << "hello,world!" << std::endl;
  // }

  return EXIT_SUCCESS;
}
