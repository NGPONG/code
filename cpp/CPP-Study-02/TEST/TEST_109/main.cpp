#include <iostream>
#include <thread>
#include <memory>
#include <chrono>
#include <csignal>
#include <dlfcn.h>

using namespace std::chrono_literals;

extern std::int32_t x;
extern std::int32_t z;

extern "C" void foo();

int main (int argc, char *argv[]) {
  std::raise(SIGSTOP);

  std::cout << x << std::endl;
  std::cout << z << std::endl;

  foo();

  // =================================================================

  typedef void (* foo_fp)(void);

  void *handler = dlopen("./libvar.so", RTLD_LOCAL | RTLD_NOW);

  foo_fp handler_foo = (foo_fp)dlsym(handler, "foo");
  int *handler_x = (int *)dlsym(handler, "x");
  int *handler_z = (int *)dlsym(handler, "z");

  std::cout << *handler_x << std::endl;
  std::cout << *handler_z << std::endl;

  handler_foo();

  return 0;
}
