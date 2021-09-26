#include <iostream>
#include <functional>

void test(int a) {
  std::cout << a << std::endl;
}

template<class... Args>
void foo(Args... b, std::function<void(Args...)> handler) {
  handler(b...);
}

int main() {
  foo<int>(1, test);
}
