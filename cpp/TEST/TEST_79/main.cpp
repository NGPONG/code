#include <iostream>
#include <vector>
#include <array>

template <typename T>
static constexpr typename std::underlying_type<T>::type GetVal(T t) noexcept
{
    return static_cast<typename std::underlying_type<T>::type>(t);
}

template<typename U>
struct FlagDeducer
{
    U val;
    constexpr FlagDeducer(U _val): val(_val) {}
    constexpr operator U() const { return val; }
    constexpr operator bool() const { return GetVal(val); }
};

#define __ENUM_FLAG_FUNC__(U) \
enum class U; \
inline constexpr FlagDeducer<U> operator & (U u1, U u2) { return static_cast<U>(GetVal(u1) & GetVal(u2)); }; \
inline constexpr U operator | (U u1, U u2) { return static_cast<U>(GetVal(u1) | GetVal(u2)); }; \
inline constexpr U operator ^ (U u1, U u2) { return static_cast<U>(GetVal(u1) ^ GetVal(u2)); }; \
inline constexpr U operator ~ (U x) { return static_cast<U>(~GetVal(x)); }; \
inline constexpr U& operator &= (U& u1, U u2) { u1 = u1 & u2; return u1; }; \
inline constexpr U& operator |= (U& u1, U u2) { u1 = u1 | u2; return u1; }; \
inline constexpr U& operator ^= (U& u1, U u2) { u1 = u1 ^ u2; return u1; };

#define ENUM_FLAG_(U) \
__ENUM_FLAG_FUNC__(U) \
enum class U : int32_t

#define ENUM_2_FLAG(U) \
__ENUM_FLAG_FUNC__(U)


ENUM_FLAG_(HELLO) {
  w = 1u << 0,
  o = 1u << 1,
  r = 1u << 2,
  l = 1u << 3,
  d = 1u << 4,
};

// ENUM_FLAG_(NGPONG) {
//   a,
//   b,
//   c
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
struct Map<str("hello,world")> { static constexpr std::array<std::string_view, 2> value = { "NGPONG", "SB" }; };
// template<>
// struct Map<::str("hahahahah")> { static constexpr std::array<HELLO, 2> value = { HELLO::w, HELLO::r }; };

int main(void) {
  // constexpr std::string_view sv = "hello,world";
  // constexpr auto arr = Map<str<sv.size()>(sv)>::value;

  // constexpr HELLO h = HELLO::w;
  // constexpr HELLO hh = HELLO::o;

  constexpr HELLO flag = HELLO::w | HELLO::o;

  if constexpr (HELLO::w & flag)
  {
    std::cout << "hello,world" << std::endl;
  }
  else 
  {
    std::cout << "ok" << std::endl;
  }

  // for (const auto& str : arr) {
  //   std::cout << str << std::endl;
  // }

  return EXIT_SUCCESS;
}
