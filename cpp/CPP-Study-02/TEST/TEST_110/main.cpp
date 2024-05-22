#include <stdio.h>

extern int x;
extern int y;

extern void foo();

int z = 100;

int main (int argc, char *argv[]) {
  // std::raise(SIGSTOP);

  printf("%p\n", &z);

  int u = 2024;
  printf("%p\n", &u);
  // printf("%d\n", x);
  // printf("%d\n", y);

  // foo();

  return 0;
}
