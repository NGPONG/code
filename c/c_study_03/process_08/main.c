#include <math.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char *argv[]) {
  int pid = fork();
  if (pid == 0) {
    int idx = 0;
    while ((++idx) < 0x400) {
      printf("child executeing %d\n", idx);
      sleep(1);
    }

    exit(EXIT_SUCCESS);
  }

  int idx = 0;
  while ((++idx) < 5) {
    printf("parent executeing %d\n",idx);
    sleep(1);
  }

  return EXIT_SUCCESS;
}
