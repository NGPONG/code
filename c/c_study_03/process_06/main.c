#include <math.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>

void foo_01(void) {
  pid_t pid = fork();
  if (pid < 0) {
    perror("E");
    exit(EXIT_FAILURE);
  } else if (pid > 0) {
    sleep(4);
    printf("parent process[%d] [%d]\n", getpid(), getppid());
    exit(EXIT_SUCCESS);
  } else if (pid == 0) {
    sleep(10);
    printf("child process[%d] [%d]\n", getpid(), getppid());
    exit(EXIT_SUCCESS);
  }
}

void foo_02(void) {
  /* Keep file number and PCB process control */
  int fd = open("./test.log", O_RDONLY);
  if (fd < 0) {
    perror("E");
    exit(EXIT_FAILURE);
  }
  char buf[5] = { 0 };
  read(fd, buf, sizeof(buf));

  /* Executeable file arg */
  char str_fd[32] = { 0 };
  sprintf(str_fd, "%d", fd);
  int flag = execl("./test", "test", str_fd, NULL);

  printf("i an main\n");
  printf("%d\n", flag);
}

int main(int argc, char *argv[]) {
  foo_02();

  return EXIT_SUCCESS;
}
