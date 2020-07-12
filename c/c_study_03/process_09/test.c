#include <math.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <unistd.h>
#include <pthread.h>

void *thread_start_1(void *arg) {
  int idx = 0;
  while (true) {
    printf("[%lu] %d\n", pthread_self(), ++idx);
    sleep(1);
  }

  return NULL;
}

void *thread_start_2(void *arg) {
  int idx = 0;
  while (true) {
    printf("[%lu] %d\n", pthread_self(), ++idx);
    sleep(1);

    if (idx == 5) {
      pthread_exit(NULL);
    }
  }

  return NULL;
}

int main(int argc, char *argv[]) {
  pthread_t tid_1;
  int s_1 = pthread_create(&tid_1, NULL, thread_start_1, NULL);
  printf("[%lu] create %lu\n",pthread_self(),tid_1);

  pthread_t tid_2;
  int s_2 = pthread_create(&tid_2, NULL, thread_start_2, NULL);
  printf("[%lu] create %lu\n",pthread_self(),tid_2);

  int pid = fork();
  if (pid == 0) {
    int idx = 0;
    while (true) {
      if (++idx == 10) {
        exit(EXIT_SUCCESS);
      }
      printf("child process\n");
      sleep(1);
    }
  }

  while (true) {
    printf("parent process\n");
    sleep(1);
  }
  return EXIT_SUCCESS;
}
