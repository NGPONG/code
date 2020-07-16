#include <math.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <pthread.h>
#include <unistd.h>

#include <sys/syscall.h>
#include <sys/types.h>

void *child_thread_start(void *arg) {
  printf("[%lu] child-child-thread executed\n", syscall(SYS_gettid));

  while (true) {
    sleep(1);
  }

  return NULL;
}

void *thread_start(void *_arg) {
  pthread_t t_id;
  pthread_create(&t_id, NULL, child_thread_start, NULL);

  printf("[%lu] child-thread executed, cretae (%lu)\n", syscall(SYS_gettid), t_id);

  sleep(0x40);
  pthread_exit(NULL);

  return NULL;
}

void foo(void) {
  pthread_t t_id;
  pthread_create(&t_id, NULL, thread_start, NULL);

  printf("[%lu] main-thread executed, create (%lu)\n", syscall(SYS_gettid), t_id);

  while (true) {
    sleep(1);
  }
}

int main(int argc, char *argv[]) {
  foo();

  return EXIT_SUCCESS;
}
