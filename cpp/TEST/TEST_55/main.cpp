#include <iostream>
#include <string>
#include <vector>
#include <array>

template <typename T>
inline constexpr bool KWIsEnum = std::is_enum_v<T> && std::is_same_v<T, std::decay_t<T>>;

enum class ENUM_CLASS : int64_t {
  A,
  B,
};

enum ENUM_BASE {
  C = 0,
  D = 1,
};

class TEST {};

class BASE {
public:
  template<typename T, typename = typename std::enable_if<KWIsEnum<T>>::type>
  BASE& operator<<(T t) {
    std::cout << "ENUM" << std::endl;

    return *this;
  }

  BASE& operator<<(const std::string& str) {
    std::cout << "STRING" << std::endl;

    return *this;
  }

  BASE& operator<<(int32_t t) {
    std::cout << "int32_t" << std::endl;

    return *this;
  }

  BASE& operator<<(const TEST& t) {
    std::cout << "TEST" << std::endl;

    return *this;
  }

  BASE& operator<<(const std::vector<int32_t>& t) {
    std::cout << "vector<int32>" << std::endl;

    return *this;
  }

  BASE& operator<<(const std::vector<std::string>& t) {
    std::cout << "vector<std::string>" << std::endl;

    return *this;
  }

  // template<typename T, typename Reques = typename std::enable_if<!KWIsEnum<T>>::type>
  // BASE& operator<<(T t) {
  //   std::cout << "hahahah" << std::endl;

  //   return *this;
  // }

};

int main(void) {
  BASE b;
  b << ENUM_BASE::C;
  b << ENUM_CLASS::A;

  ENUM_BASE eb = ENUM_BASE::D;
  const auto& enc = eb;
  b << enc;

  b << 1;
  b << "";
  b << TEST();
  b << std::vector<int32_t>();
  b << std::vector<std::string>();
  b << 1.0;

  std::underlying_type_t<ENUM_BASE> ut;
  std::cout << typeid(ut).name()<< std::endl;

  static_assert(std::is_pointer_v<char *>, "Invalid type not supported.");
  // static_assert(std::is_pointer_v<int32_t>, "Invalid type not supported.");

  // b << "asdasd";
  // b << 1;
  // b << 1;

  return EXIT_SUCCESS;
}
