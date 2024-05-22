#include <iostream>

std::int32_t a1 = 1;
std::int32_t a2 = 2;
std::int32_t a3 = 3;
static std::int32_t b1 = 1;
static std::int32_t b2 = 2;
static std::int32_t b3 = 3;
const std::int32_t c1 = 1;
const std::int32_t c2 = 2;
const std::int32_t c3 = 3;

constinit std::int32_t val = 10;

auto foo() {
  return 0x400;
}

int main (int argc, char *argv[]) {
  std::cout << &a1 << std::endl;
  std::cout << &a2 << std::endl;
  std::cout << &a3 << std::endl;
  std::cout << &b1 << std::endl;
  std::cout << &b2 << std::endl;
  std::cout << &b3 << std::endl;
  std::cout << &c1 << std::endl;
  std::cout << &c2 << std::endl;
  std::cout << &c3 << std::endl;
  std::cout << (void *)&foo << std::endl;

  constinit static std::int32_t _val = 2024;

  return 0;
}
