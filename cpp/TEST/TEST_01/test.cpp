#include <cstdint>
#include <vector>

#include "main.hpp"

class BASE;

void test_foo();

void test_foo() {
    const std::string& str = "hello,world!";

    std::vector<std::int32_t> v;

    BASE b = BASE(str);
}
