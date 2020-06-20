#include <math.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <sys/stat.h>

void foo_01(void) {
  struct stat _s;
  if (stat("./text", &_s)) {
    perror("E");
    return;
  }

  printf("file device number = %lu\n",_s.st_dev);

  if (_s.st_mode & S_IRWXU) {
    printf("user read permission\n");
  }
  if (_s.st_mode & S_IWUSR) {
    printf("user write permission\n");
  }
  if (_s.st_mode & S_IXUSR) {
    printf("user execute perssion\n");
  }

  if ((_s.st_mode & __S_IFMT) == __S_IFREG) {
    printf("reg file\n");
  }
}

int main(void) {
  foo_01();
  return EXIT_SUCCESS;
}
