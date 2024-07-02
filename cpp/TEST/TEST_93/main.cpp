#include <iostream>
#include <vector>
#include <memory>

#include "test.h"

int main(int argc, char *argv[]) {
  BASE b;
  b.foo();

  const std::size_t size = 1024;

  // foo(size);

  return EXIT_SUCCESS;
}
