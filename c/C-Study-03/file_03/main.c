#include <math.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <sys/stat.h>

void foo_02(void) {
  struct stat _s;
  if (stat("./text", &_s)) {
    perror("E");
    return;
  }

  if (_s.st_mode & S_IROTH) {
    printf("user read permission\n");
  }
  if (_s.st_mode & S_IWOTH) {
    printf("user write permission\n");
  }
  if (_s.st_mode & S_IXUSR) {
    printf("user execute perssion\n");
  }
}

void foo_01(void) {
  struct stat _s;
  if (stat("./text", &_s)) {
    perror("E");
    return;
  }

  switch (_s.st_mode & __S_IFMT) {
  case __S_IFREG:
    printf("ref file\n");
    break;
  case __S_IFDIR:
    printf("dir file\n");
    break;
  case __S_IFBLK:
    printf("blk file\n");
    break;
  case __S_IFCHR:
    printf("chr file\n");
    break;
  case __S_IFSOCK:
    printf("sock file\n");
    break;
  case __S_IFLNK:
    printf("lnk file\n");
    break;
  case __S_IFIFO:
    printf("ifo file\n");
    break;
  defult:
    printf("unknown file\n");
    break;
  }


  if (S_ISLNK(_s.st_mode)) {
    printf("lnk file\n");
  } else if (S_ISBLK(_s.st_mode)) {
    printf("blk file\n");
  } else if (S_ISCHR(_s.st_mode)) {
    printf("chr file\n");
  } else if (S_ISREG(_s.st_mode)) {
    printf("reg file\n");
  } else if (S_ISDIR(_s.st_mode)) {
    printf("dir file\n");
  } else if (S_ISFIFO(_s.st_mode)) {
    printf("fifo file\n");
  } else {
    printf("unknown file\n");
  }
}

int main(void) {
  foo_01();
  return EXIT_SUCCESS;
}
