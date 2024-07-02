#include <iostream>
#include <csignal>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <dlfcn.h>

extern std::int32_t x;

void foo(std::int32_t val);

std::int32_t y = 1024;

int main (int argc, char *argv[]) {
  std::raise(SIGSTOP);

  std::cout << y << std::endl;
  std::cout << x << std::endl;
  foo(x);

  return 0;
}
