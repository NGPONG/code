#include <iostream>
#include <dlfcn.h>

std::int32_t g_val = 256;

int main (int argc, char *argv[]) {
  typedef void (* foo_fp)(void);

  void* handler = dlopen ("./libtest.so", RTLD_NOW);

  foo_fp foo = (foo_fp)dlsym(handler, "foo");
  foo();

  std::cout << g_val << std::endl;

  return 0;
}

