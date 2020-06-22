#include <math.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>

void foo_02(void) {
  ssize_t size = write(STDOUT_FILENO, "hello", 6);
  printf("%lu\n", size);
}

void foo(void) {
  int _fd = open("/home/ngpong/code/C/C-Study-03/file_05/test.log", O_WRONLY | O_CREAT | O_APPEND, S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH);
  if (_fd == -1) {
    perror("E");
    return;
  }

  /** 
   * 0  STDIN_FILENO  -->  stdin
   * 1 STDOUT_FILENO  -->  ./test.log
   * 2 STDERR_FILENO  -->  stderr
   * 3           _fd  -->  ./test.log
   * 4 stdout_fd_tmp  -->  stdout
   */
  int stdout_fd_tmp = dup(STDOUT_FILENO);
  dup2(_fd, STDOUT_FILENO);

  char str_buf[128] = { 0 };
  while (true) {
    scanf("%s", str_buf);
    if ((strcmp(str_buf, "exit")) == 0) {
      break;
    }
    printf("%s\n", str_buf);

    memset(str_buf, 0x0, sizeof(str_buf));
  }

  /** 
   * 0  STDIN_FILENO  -->  stdin
   * 1 STDOUT_FILENO  -->  ./test.log
   * 2 STDERR_FILENO  -->  stderr
   * 3 
   * 4 stdout_fd_tmp  -->  stdout
   */
  close(_fd);
  dup2(stdout_fd_tmp, STDOUT_FILENO);
  close(stdout_fd_tmp);

  printf("is's ok!\n");
  printf("hello,NGPONG!\n");
}

int main(void) {
  foo();
  return EXIT_SUCCESS;
}
