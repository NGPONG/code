#include <iostream>
#include <thread>
#include <atomic>
#include <chrono>
#include <functional>
#include <future>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <thread>
#include <time.h>
#include <utility>
#include <time.h>

void foo() {
  std::cout << "hello,world!" << std::endl;
}

void func() {
  auto f = std::async(std::launch::deferred, std::bind(foo));
  f.get();
}

int main(void) {
  func();

  return EXIT_SUCCESS;
}
