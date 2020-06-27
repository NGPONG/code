#include <math.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <unistd.h>

void foo(void) {
  int idx = 0;
  while (true) {
    printf("child [%d]: %d\n", getpid(), ++idx);
    sleep(1);

    if(idx == 0x9999) break;
  }
}

void foo_fth(void) {
  int idx = 0;
  while (true) {
    printf("father [%d]: %d\n", getpid(), ++idx);
    sleep(1);

    if(idx == 20) break;
  }
}

int g_idx = 0;

int main(int argc, char *argv[]) {
  int f_idx = 0;

  for (int i = 0; i < 3; ++i) {
    ++g_idx;
    ++f_idx;
    int _pid = fork();
    if (_pid < 0) {
      perror("E");
      return EXIT_FAILURE;
    }

    if (_pid == 0) {
      printf("The [%d] loop\n", i);
      printf("g: [%d]\n", g_idx);
      printf("f: [%d]\n", f_idx);
      foo();
      break;
    }

    printf("create [%d]\n", _pid);
  }

  foo_fth();

  return EXIT_SUCCESS;
}
