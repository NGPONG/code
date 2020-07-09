#include <math.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <wait.h>
#include <unistd.h>

#define MAX_PROC_LENGTH 64

void wait_all_proc(int _sig) {
  int state;
  int pid;
  while ((pid = waitpid(-1, &state, 0)) != -1) {
    printf("Reclaim child process [%d] resources, state = %d\n", pid, WTERMSIG(state));
  }
}

void child_wake_up(int _sig) {
  printf("[%d] child process wake-up\n", getpid());
}

/**
 * @brief 创建 N 个子进程，最后通过信号机制完成对子进程的资源回收
 */
void foo(void) {
  int pids[MAX_PROC_LENGTH] = { 0 };

  for (size_t i = 0; i < MAX_PROC_LENGTH; ++i) {
    pids[i] = fork();
    if (pids[i] < 0) {
      perror("create child process error");
      wait_all_proc(0);
      exit(EXIT_FAILURE);
    } else if (pids[i] == 0) {
      /* child process context */

      signal(SIGALRM, child_wake_up);
      sleep(1024); /* sleep until reveive any signal */

      int idx = 0;
      while (++idx < (i + 1) *2) {
        /* printf("[%d] child process executeing, idx = %d\n",getpid(),idx); */
        sleep(1);
      }

      exit(EXIT_FAILURE);
    }
  }
  
  /* Register SIGCHLD signal caughter */
  signal(SIGCHLD, wait_all_proc);

  /* Notify all child processes */
  for (size_t i = 0; i < MAX_PROC_LENGTH; ++i) {
    printf("Notify process [%d] wake-up\n", pids[i]);
    kill(pids[i],SIGALRM);
  }

  /* parnet context */
  int idx = 0;
  while (++idx < 1024) {
    /* printf("[%d] parent process executeing, idx = %d\n", getpid(), idx); */
    sleep(1);
  }
}

int main(int argc, char *argv[]) {
  foo();

  return EXIT_SUCCESS;
}
