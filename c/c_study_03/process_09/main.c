#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <pthread.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/syscall.h>
#include <sys/types.h>

void *thread_start(void *_arg) {
  sigset_t mask;
  sigemptyset(&mask);
  sigaddset(&mask, SIGINT);
  pthread_sigmask(SIG_BLOCK, &mask, NULL);

  printf("[%lu] child-thread executed\n", pthread_self());

  while (true) {
    sleep(1);
  }

  return NULL;
}

void sig_handler(int _sig) {
  printf("executed, tid = %lu\n", pthread_self());
  fflush(stdout);

  exit(EXIT_SUCCESS);
}

int main(int argc, char *argv[]) {
  pthread_t t_id;
  int s = pthread_create(&t_id, NULL, thread_start, NULL);
  if (s != 0) {
    char *msg = strerror(s);
    printf("%s\n", msg);
  }

  sleep(2);

  struct sigaction act;
  sigemptyset(&act.sa_mask);
  act.sa_handler = sig_handler;
  act.sa_flags = 0;
  sigaction(SIGINT, &act, NULL);

  printf("[%lu] main-thread executed, create [%lu]\n", pthread_self(), t_id);

  /* pthread_kill(t_id, SIGINT); */

  while (true) {
    sleep(1);
  }

  return EXIT_SUCCESS;
}
