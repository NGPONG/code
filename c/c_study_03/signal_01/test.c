#include <math.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <unistd.h>
#include <signal.h>

int main(int argc, char *argv[]) {
  int pid = (int) strtol(argv[1], (char **)NULL, 10);

  for (size_t i = 0; i < 10; ++i) {
    kill(pid,SIGUSR2);
    printf("OK!\n");
  }

  return EXIT_SUCCESS;
}
