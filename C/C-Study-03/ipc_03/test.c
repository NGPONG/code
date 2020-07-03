#include <math.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <fcntl.h>
#include <unistd.h>

void foo(void) {
  int fd = open("./myfifo.p",O_WRONLY);
  if (fd < 0) {
    perror("e");
    exit(EXIT_FAILURE);
  }

  char *str = "hello,world!";
  int size = write(fd,str,strlen(str) + 1);
  printf("size = %d",size);
  
  close(fd);
}

int main(int argc, char *argv[]) {
  foo();
  
  return EXIT_SUCCESS;
}

