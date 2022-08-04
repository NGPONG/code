#include <iostream>
#include <functional>
#include <deque>
#include <memory>
#include <string>
#include <utility>
#include <source_location>

// #include <cxxabi.h>

// class BASE {
// public:
//   virtual int foo(int a, std::string b, float c) = 0;
// };

// class ease : public BASE {
// public:
//   int foo(int a, std::string b, float c) override {
//     std::cout << a << std::endl;
//     std::cout << b << std::endl;
//     std::cout << c << std::endl;
//     return 1024;
//   }
// };

// void foo(std::string val) {}

// int main(void) {
//   BASE *b = new ease();

//   using namespace std::placeholders;

//   int g = 10;
//   float h = 20;

//   ease e;
//   std::function<int(int,std::string,float)> func = std::bind(&ease::foo, &e, _1, _2, _3);

//   std::function<void(std::string)> f = foo;

//   std::cout << func.target_type().name() << std::endl;
//   std::cout << f.target_type().name() << std::endl;

//   std::cout << abi::__cxa_demangle(f.target_type().name(), nullptr, nullptr, nullptr) << std::endl;
// }

void foo() {
  std::source_location sl;

  std::cout << "info:"
            << sl.function_name();
}

int main(void) {
  foo();

  return 0;
}
