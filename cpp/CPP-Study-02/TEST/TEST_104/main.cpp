#include <iostream>
#include <thread>
#include <chrono>
#include <dlfcn.h>

using namespace std::chrono_literals;

extern std::int32_t g_val;
extern std::int32_t foo();

int main (int argc, char *argv[]) {
  while (true) {
    std::this_thread::sleep_for(2000ms);

    std::cout << g_val << std::endl;
    foo();
    
    // typedef void (* foo_fp)(void);
    //
    // void *handler = dlopen("./libvar.so", RTLD_LOCAL | RTLD_NOW);
    //
    // foo_fp handler_foo = (foo_fp)dlsym(handler, "foo");
    // int *handler_g_val = (int *)dlsym(handler, "g_val");
    //
    // std::cout << *handler_g_val << std::endl;
    // handler_foo();
    //
    // dlclose(handler);
  }

  return 0;
}
