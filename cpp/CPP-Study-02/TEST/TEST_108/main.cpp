#include <iostream>
#include <elf.h>

void foo() __attribute__((weak));

void foo() {
  std::cout << __FILE__ << std::endl;
}

int main (int argc, char *argv[]) {
  foo();
  PT_LOAD;

  return 0;
}
