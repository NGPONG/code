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
  int _fd = open("/home/ngpong/code/C/C-Study-03/file_02/text", O_WRONLY);
  if (_fd == -1) {
    return;
  }
  printf("file postion pointer = %lu\n", lseek(_fd, 0, SEEK_CUR));

  char *str_w = "NGPONG!\n";
  write(_fd, str_w, strlen(str_w));
  printf("file postion pointer = %lu\n", lseek(_fd, 0, SEEK_CUR));

  char *str_w_2 = "hello,keesung!";
  write(_fd, str_w_2, strlen(str_w_2));
  printf("file postion pointer = %lu\n", lseek(_fd, 0, SEEK_CUR));

  close(_fd);
}

void foo_06(void) {
  int _fd = open("/home/ngpong/code/C/C-Study-03/file_02/text", O_RDONLY);
  if (_fd == -1) {
    return;
  }

  char buf[5] = { 0 };
  read(_fd, buf, sizeof(buf));

  printf("%s\n", buf);

  close(_fd);
}

void foo_07(void) {
  int _fd = open("/dev/tty", O_RDONLY);
  if (_fd == -1) {
    perror("E");
    return;
  }

  char *buf = malloc(sizeof(char) * 0x40);
  if (buf == NULL) {
    perror("E");
    return;
  }

  while (true) {
    read(_fd, buf, sizeof(buf));
  }
  
  free(buf);
  close(_fd);
}

int main(void) {
  foo_07();
  return EXIT_SUCCESS;
}
