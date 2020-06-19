#include <math.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>


void foo_01(void) {
  int _fd = open("test", O_WRONLY | O_CREAT, S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP);
  if (_fd == -1) {
    perror("E");
    return;
  }

  printf("%d\n", _fd);

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

  printf("%d\n", _fd);

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

  printf("%d\n", _fd);

  char *str = "123qwe\n";
  write(_fd, str, strlen(str));

  close(_fd);
}

void foo_04(void) {
  printf("123");
}

void foo_05(void) {
  int _fd = open("/home/ngpong/code/C/C-Study-03/file_02/text", O_WRONLY | O_APPEND);
  if (_fd == -1) {
    return;
  }
  printf("file postion pointer = %lu\n", lseek(_fd, 0, SEEK_CUR));

  // char str_r[0x8] = { 0 };
  // read(_fd, str_r, sizeof(str_r));

  char *str_w = "NGPONG!\n";
  write(_fd, str_w, strlen(str_w));

  printf("file postion pointer = %lu\n", lseek(_fd, 0, SEEK_CUR));

  char *str_w_2 = "hello,keesung!";

  close(_fd);
}

int main(void) {
  foo_05();
  return EXIT_SUCCESS;
}
