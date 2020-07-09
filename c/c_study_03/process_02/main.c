#include <math.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>

int main(int argc, char *argv[]) {
  pid_t _pid = fork();
  if (_pid < 0) {
    perror("E");
    return EXIT_FAILURE;
  }
  
   
  int idx = 0;
  while (true) {
    printf("%s [%d]:%d\n", _pid == 0 ? "CHILD" : "FATHER", getpid(), ++idx);
    sleep(2);

    printf("---------------------------------------------\n");

    if (idx == 100000) {
      return EXIT_SUCCESS;
    }
  }

  return EXIT_SUCCESS;
}
