#include "test.hpp"

__attribute__((visibility("hidden")))
std::int32_t Base::val = 1024;

// __attribute__((visibility("hidden")))
void Base::set_val(std::int32_t _val) {
  std::cout << "hello set: " << _val << std::endl;
  val = _val;
}

void BaseWrapper::foo() {
  std::cout << "hello,world" << std::endl;
  Base::set_val(111);
}
