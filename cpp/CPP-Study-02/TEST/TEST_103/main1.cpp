#include <stdio.h>
#include <dlfcn.h>

int main() {
  typedef int (* foo_fp)(void);

  void *handler = dlopen("/home/ngpong/code/cpp/CPP-Study-02/TEST/TEST_103/libtest.so", RTLD_LOCAL | RTLD_NOW);

  foo_fp handler_foo = (foo_fp)dlsym(handler, "foo");
  int *handler_g_val = (int *)dlsym(handler, "g_val");

  printf("main1 ==>\n");
  printf("  handler::g_val: %d\n", *handler_g_val);
  printf("  handler::&g_val: %p\n", handler_g_val);

  while (1) {
    printf("  handler::foo(): %d\n", handler_foo());
    printf("  handler::&foo(): %p\n", (void *)handler_foo);

    getchar();
  }

  return 0;
}
