#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void foo() {
  
}

int main(int argc, char *argv[]) {
  int idx = 0x400;
  idx += 20;

  /* stack test */
  __asm__(
      "movq $0xFFFF, %rax\n"
      "pushq %rax\n"
      "pushq %rax\n"
  );

  foo();

  return 0;
}
