#include <math.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>


void foo_01(void) {
  int _fd = open("test", O_WRONLY | O_CREAT, S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP);
  if (_fd == -1) {
    perror("E");
    return;
  }

  char *str1 = "hello,world!\n";
  char *str2 = "NGPONG!\n";
  char *str3 = "like C";

  write(_fd, str1, strlen(str1));
  write(_fd, str2, strlen(str2));
  write(_fd, str3, strlen(str3));

  close(_fd);
}

void foo_02(void) {
  int _fd = open("test", O_WRONLY | O_CREAT, S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP);
  if (_fd == -1) {
    perror("E");
    return;
  }

  char *str = "hello!\n";
  write(_fd, str, strlen(str));

  close(_fd);
}

void foo_03(void) {
  int _fd = open("test", O_WRONLY | O_CREAT | O_APPEND, S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP);
  if (_fd == -1) {
    perror("E");
    return;
  }
  
  char *str = "123qwe\n";
  write(_fd, str, strlen(str));

  close(_fd);
}

int main(void) {
  foo_03();
  return EXIT_SUCCESS;
}
