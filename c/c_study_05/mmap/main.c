#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include <fcntl.h>
#include <sys/mman.h>
#include <sys/wait.h>
#include <unistd.h>

void foo(char *file_name) {
  int fd = open(file_name, O_RDWR);
  if (fd < 0) {
    perror("open file error");
    return;
  }
  int len = lseek(fd, 0, SEEK_END);
  printf("success open file: %s, len: %d\n", file_name, len);

  void *addr = mmap(NULL, len, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
  if (addr == MAP_FAILED) {
    perror("memory map error");
    return;
  }
  close(fd);

  int pid = fork();
  if (pid < 0) {
    perror("fork error");
    return;
  } else if (pid == 0) {
    sleep(1);

    printf("[%d] child process start read data\n", getpid());
    printf("%s\n", (char *)addr);
    printf("[%d] child process end\n", getpid());

    return;
  } else {
    printf("[%d] parent process start write data\n", getpid());

    char *str = "hello,world!";
    int str_size = strlen(str) + 1;

    memcpy(addr, str, str_size);
    printf("[%d] parent process write %d bytes, value: %s\n", getpid(), str_size, str);

    wait(NULL);
    munmap(addr, len);
  }
}

int main(int argc, char *argv[]) {
  foo(argv[1]);

  return EXIT_SUCCESS;
}
