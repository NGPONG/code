#include <iostream>
#include <vector>
#include <array>

enum class HELLO : int32_t {
  w,
  o,
  r,
  l,
  d
};

enum class NGPONG : int32_t {
  a,
  b,
  c
};

// template <char * key>
// struct Map;
// template <char * key>
// struct Map              { static constexpr std::array<HELLO, 0> value; };
// template <>
// struct Map< "" > { static constexpr std::array<HELLO, 2> value = { HELLO::w, HELLO::r }; };
// template <>
// struct Map< NGPONG::b > { static constexpr std::array<HELLO, 1> value = { HELLO::d }; };

// class BASE {
// public:
//   template<typename... T>
//   static constexpr bool always_false_v = false;
// 
//   template<size_t N>
//   static constexpr auto str(const std::string_view sv) {
//     std::array<char, N> arr;
//     for (std::size_t i = 0; i < N; ++i)
//       arr[i] = sv[i];
//     return arr;
//   }
// 
//   template<size_t N>
//   static constexpr auto str(char const (&cstr)[N]) {
//     std::array<char, N - 1> arr;
//     for (std::size_t i = 0; i < N - 1; ++i)
//       arr[i] = cstr[i];
//     return arr;
//   }
// 
//   template<auto key>
//   struct Map;
//   template<auto key>
//   struct Map { static_assert(always_false_v<decltype(key)>, "hello,world"); };
//   template<>
//   struct Map<str("i am string")> { static constexpr std::array<HELLO, 2> value = { HELLO::w, HELLO::r }; };
//   // template<>
//   // struct Map<::str("hahahahah")> { static constexpr std::array<HELLO, 2> value = { HELLO::w, HELLO::r }; };
// };

template<typename... T>
static constexpr bool always_false_v = false;

template<size_t N>
static constexpr auto str(const std::string_view sv) {
  std::array<char, N> arr;
  for (std::size_t i = 0; i < N; ++i)
    arr[i] = sv[i];
  return arr;
}

template<size_t N>
static constexpr auto str(char const (&cstr)[N]) {
  std::array<char, N - 1> arr;
  for (std::size_t i = 0; i < N - 1; ++i)
    arr[i] = cstr[i];
  return arr;
}

template<auto key>
struct Map;
template<auto key>
struct Map { static_assert(always_false_v<decltype(key)>, "hello,world"); };
template<>
struct Map<str("i am string")> { static constexpr std::array<HELLO, 2> value = { HELLO::w, HELLO::r }; };

int main(void) {
  constexpr std::string_view sv = "hahahahah";
  // constexpr auto arr = BASE::Map<BASE::str<sv.size()>(sv)>::value;

  // std::vector<HELLO> v = { arr.begin(), arr.end() };

  // static_assert(arr.size() == 2);

  return EXIT_SUCCESS;
}
