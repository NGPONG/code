#include <stdio.h>
#include <stdlib.h>

char* foo(int32_t rdi, const char* rsi, int64_t rdx, int32_t* rcx) {
  return "hello,world!";
}

int main(int argc, char *argv[]) {
  const char* str = foo(0x400, NULL, 0x100, NULL);
  printf("%s\n", str);

  return EXIT_SUCCESS;
}
