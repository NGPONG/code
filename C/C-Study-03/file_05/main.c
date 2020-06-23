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
  /** 
   * 0 STDIN_FILENO  -> stdin
   * 1 STDOUT_FILENO -> stdout
   * 2 STDERR_FILENO -> stderr
   */

  /** 
   * 0 STDIN_FILENO  -> stdin
   * 1 STDOUT_FILENO -> stdout
   * 2 STDERR_FILENO -> stderr
   * 3 _fd_w         -> test.log
   */
  int _fd_w = open("/home/ngpong/code/C/C-Study-03/file_05/test.log", O_WRONLY | O_CREAT | O_APPEND, S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH);
  if (_fd_w == -1) {
    perror("E");
    return;
  }

  /** 
   * 0 STDIN_FILENO  -> stdin
   * 1 STDOUT_FILENO -> stdout
   * 2 STDERR_FILENO -> stderr
   * 3 _fd_w         -> test.log
   * 4 std_out       -> stdout
   */
  int std_out = dup(STDOUT_FILENO);
  /** 
   * 0 STDIN_FILENO  -> stdin
   * 1 STDOUT_FILENO -> test.log
   * 2 STDERR_FILENO -> stderr
   * 3 _fd_w         -> test.log
   * 4 std_out       -> stdout
   */
  dup2(_fd_w, STDOUT_FILENO);

  printf("hello,world!\n");
  printf("hello,NGPONG!\n");
  printf("hello,C Langaers!\n");
  fflush(stdout);

  /** 
   * 0 STDIN_FILENO  -> stdin
   * 1 STDOUT_FILENO -> test.log
   * 2 STDERR_FILENO -> stderr
   * 3
   * 4 std_out       -> stdout
   */
  close(_fd_w);
  /** 
   * 0 STDIN_FILENO  -> stdin
   * 1 
   * 2 STDERR_FILENO -> stderr
   * 3
   * 4 std_out       -> stdout
   */
  close(STDOUT_FILENO);

  /** 
   * 0 STDIN_FILENO  -> stdin
   * 1 STDOUT_FILENO -> stdout
   * 2 STDERR_FILENO -> stderr
   * 3
   * 4 std_out       -> stdout
   */
  int i = dup(std_out);
  /** 
   * 0 STDIN_FILENO  -> stdin
   * 1 STDOUT_FILENO -> stdout
   * 2 STDERR_FILENO -> stderr
   * 3
   * 4 
   */
  close(std_out);

  /** 
   * 0 STDIN_FILENO  -> stdin
   * 1 STDOUT_FILENO -> stdout
   * 2 STDERR_FILENO -> stderr
   * 3 _fd_r         -> test.log
   * 4 
   */
  int _fd_r = open("/home/ngpong/code/C/C-Study-03/file_05/test.log", O_RDONLY);
  if (_fd_r == -1) {
    perror("E");
    return;
  }

  char buf[64] = { 0 };
  while ((read(_fd_r, buf, sizeof(buf))) != 0) {
    printf("%s",buf);
  }
  fflush(stdout);

  /** 
   * 0 STDIN_FILENO  -> stdin
   * 1 STDOUT_FILENO -> test.log
   * 2 STDERR_FILENO -> stderr
   * 3
   * 4 
   */
  close(_fd_r);
}

void foo_03(void) {
  /* read */
  int _fd_r = open("/home/ngpong/code/C/C-Study-03/file_05/test.log", O_RDONLY);
  if (_fd_r == -1) {
    perror("E");
    return;
  }

  char buf[64] = { 0 };
  while ((read(_fd_r, buf, sizeof(buf))) != 0) {
    printf("%s",buf);
  }

  close(_fd_r);
}

void foo_02(void) {
  int _fd = open("./test.log", O_WRONLY);
  if (_fd == -1) {
    perror("E");
    return;
  }

  int flag = fcntl(_fd, F_GETFL);
  printf("%d\n", flag);

  close(_fd);
}


int main(void) {
  /* foo(); */
  foo_02();
  return EXIT_SUCCESS;
}
