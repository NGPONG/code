#include <iostream>
#include <vector>
#include <map>

enum class NGPONG {
  A,B,C,D,E
};

std::map<std::string, int32_t> m = {
  {"NGPONG", 3},
  {"hello,world", 2},
};

template<typename U>
struct BASE {
  U under;

  BASE(U _under): under(_under) {}

  template<typename T>
  operator T() {
    return static_cast<T>(under);
  }

  template<typename T>
  bool operator==(T t) {
    return static_cast<T>(under) == t;
  }
};

BASE<int32_t> GetEnum(const std::string& key) {
  return m[key];
}

template<typename T>
T GetEnum(const std::string& key) { 
  return static_cast<T>(m[key]);
}

NGPONG foo_ng() {
  return GetEnum("hello,world");
}

int main(void) {
  // if (NGPONG::A == foo_ng()) {
  //   std::cout << "A" << std::endl;
  // }
  // else if (NGPONG::B == foo_ng()) {
  //   std::cout << "B" << std::endl;
  // }
  // else if (NGPONG::C == foo_ng()) {
  //   std::cout << "C" << std::endl;
  // }
  // else {
  //   std::cout << "ops" << std::endl;
  // }

  // NGPONG a = GetEnum("hello,world");
  // foo(a);

  // std::cout << typeid(a).name() << std::endl;

  // std::cout << static_cast<int32_t>(a) << std::endl;

  // NGPONG b = GetEnum("NGPONG");

  // std::cout << static_cast<int32_t>(b) << std::endl;

  return EXIT_SUCCESS;
}
