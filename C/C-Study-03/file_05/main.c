#include <math.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>

void foo(void) {
  int _fd = open("/home/ngpong/code/C/C-Study-03/file_05/test.log", O_WRONLY | O_CREAT | O_APPEND | O_TRUNC, S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH);
  if (_fd == -1) {
    perror("E");
    return;
  }

  /** 
   * 0  STDIN_FILENO  -->  stdin
   * 1 STDOUT_FILENO  -->  stdout
   * 2 STDERR_FILENO  -->  stderr
   * 3           _fd  -->  ./test.log
   * 4 stdout_fd_tmp  -->  stdout
   */
  int stdout_fd_tmp = dup(STDOUT_FILENO);

  /** 
   * 0  STDIN_FILENO  -->  stdin
   * 1 STDOUT_FILENO  -->  ./test.log
   * 2 STDERR_FILENO  -->  stderr
   * 3           _fd  -->  ./test.log
   * 4 stdout_fd_tmp  -->  stdout
   */
  dup2(_fd, STDOUT_FILENO);

  char str_buf[128] = { 0 };
  while (true) {
    scanf("%s", str_buf);
    if ((strcmp(str_buf, "exit")) == 0) {
      break;
    }
    //str_buf[strlen(str_buf)] = '\n';
    //str_buf[strlen(str_buf)] = 0x0;
    //write(STDOUT_FILENO, str_buf, strlen(str_buf));
    //
    printf("%s\n", str_buf);

    memset(str_buf, 0x0, sizeof(str_buf));
  }

  write(stdout_fd_tmp, "user exit\n", 11);

  /** 
   * 0  STDIN_FILENO  -->  stdin
   * 1 STDOUT_FILENO  -->  ./test.log
   * 2 STDERR_FILENO  -->  stderr
   * 3 
   * 4 stdout_fd_tmp  -->  stdout
   */
  close(_fd);
  close(STDOUT_FILENO);

  /** 
   * 0  STDIN_FILENO  -->  stdin
   * 1 STDOUT_FILENO  -->  stdout
   * 2 STDERR_FILENO  -->  stderr
   * 3  
   * 4 stdout_fd_tmp  -->  stdout
   */
  //dup2(stdout_fd_tmp, STDOUT_FILENO);

  /** 
   * 0  STDIN_FILENO  -->  stdin
   * 1 STDOUT_FILENO  -->  stdout
   * 2 STDERR_FILENO  -->  stderr
   * 3
   * 4 
   */
  //close(stdout_fd_tmp);

  //printf("is's ok!\n");
  //printf("hello,NGPONG!\n");
}

void foo_02(void) {
  int _fd_w = open("/home/ngpong/code/C/C-Study-03/file_05/test.log", O_WRONLY | O_CREAT | O_APPEND | O_TRUNC, S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH);
  if (_fd_w == -1) {
    perror("E");
    return;
  }
  printf("fd_write = %d\n", _fd_w);

  //int std_out = dup(STDOUT_FILENO);
  int fd = dup2(_fd_w, STDOUT_FILENO);

  printf("hello,world!\n");
  printf("hello,NGPONG!\n");
  printf("hello,C Langaers!\n");

  close(_fd_w);
  close(STDOUT_FILENO);

  //int _fd_r = open("/home/ngpong/code/C/C-Study-03/file_05/test.log", O_RDONLY);
  //if (_fd_r == -1) {
  //  perror("E");
  //  return;
  //}
  //printf("fd_read = %d\n", _fd_r);

  ////char buf[64] = { 0 };
  ////read(_fd_r, buf, strlen(buf));
  //
  //close(_fd_r);
}

int main(void) {
  //foo();
  foo_02();
  return EXIT_SUCCESS;
}
