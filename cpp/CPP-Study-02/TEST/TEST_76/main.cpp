#include <iostream>

class KWEnum {
public:
  template<typename U>
  struct TypeDeducer {
    U val;

    TypeDeducer(U _val)
      : val(_val) {}

    template<typename T>
    operator T() {
      return static_cast<T>(val);
    }

    template<typename T>
    bool operator==(T t) {
      return static_cast<T>(val) == t;
    }

    template<typename T>
    bool operator!=(T t) {
      return static_cast<T>(val) != t;
    }
  };

  template<typename U>
  struct FlagDeducer {
    U val;

    FlagDeducer(U _val)
      : val(_val) {}

    operator U() const {
      return val;
    }
    operator bool() const {
      return KWEnum::GetVal(val);
    }
  };

  template<typename T>
  static constexpr typename std::underlying_type<T>::type GetVal(T t) noexcept {
    return static_cast<typename std::underlying_type<T>::type>(t);
  }
};


#define ENUM2FLAGS(U)                                             \
enum class U;                                                     \
inline KWEnum::FlagDeducer<U> operator&(U u1, U u2) {             \
  return static_cast<U>(KWEnum::GetVal(u1) & KWEnum::GetVal(u2)); \
};                                                                \
inline U operator|(U u1, U u2) {                                  \
  return static_cast<U>(KWEnum::GetVal(u1) | KWEnum::GetVal(u2)); \
};                                                                \
inline U operator^(U u1, U u2) {                                  \
  return static_cast<U>(KWEnum::GetVal(u1) ^ KWEnum::GetVal(u2)); \
};                                                                \
inline U operator~(U x) {                                         \
  return static_cast<U>(~KWEnum::GetVal(x));                      \
};                                                                \
inline U &operator&=(U &u1, U u2) {                               \
  u1 = u1 & u2;                                                   \
  return u1;                                                      \
};                                                                \
inline U &operator|=(U &u1, U u2) {                               \
  u1 = u1 | u2;                                                   \
  return u1;                                                      \
};                                                                \
inline U &operator^=(U &u1, U u2) {                               \
  u1 = u1 ^ u2;                                                   \
  return u1;                                                      \
};

ENUM2FLAGS(Hello)
enum class Hello : int32_t {
  a = 1u << 0,
  b = 1u << 1,
  c = 1u << 2,
  d = 1u << 3,
};

int main() {
  Hello h;
  h |= Hello::a;
  h |= Hello::a | Hello::b;

  if (h & Hello::a) 
  {
    std::cout << "hahaha" << std::endl;
  }

  if (h & Hello::b) 
  {
    std::cout << "1111" << std::endl;
  }

  std::cout << static_cast<int32_t>(h) << std::endl;
}
