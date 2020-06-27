#include <math.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <unistd.h>
#include <pthread.h>
#include <sys/syscall.h>
#include <sys/types.h>

void *foo(void *arg) {
  while (true) {
    int pid = gettid(); /* syscall(__NR_gettid); */
    printf("C:%d\n", pid);
    sleep(3);
  }

  return NULL;
}

void foo_prc(void) {
  printf("create child process [%d]\n", getpid());

  for (size_t i = 0; i < 5; ++i) {
    pthread_t tid;
    pthread_create(&tid, NULL, &foo, NULL);
  }

  while (true) {
    /* printf("P:%d\n", getpid()); */
    sleep(1);
  }
}

int main(int argc, char *argv[]) {
  for (int i = 0; i < 3; ++i) {
    int _pid = fork();
    if (_pid < 0) {
      perror("E");
      exit(EXIT_FAILURE);
    }
    if (_pid > 0) continue;

    /* Child process context */
    if (_pid == 0) {
      foo_prc();
      break;
    }
  }

  while (true) {
    /* printf("R:%d\n", getpid()); */
    sleep(1);
  }

  return EXIT_SUCCESS;
}
