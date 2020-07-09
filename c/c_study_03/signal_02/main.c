#include <math.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <signal.h>
#include <unistd.h>
#include <sys/time.h>
#include <pthread.h>

void foo_01_SIGINT_handler(int _sig) {
  printf("Catch SIGINT signal, and disable terminate action by default\n");
}
void foo_01(void) {
  signal(SIGINT, &foo_01_SIGINT_handler);

  /* Blocked 3 senconds and then send a SIGINT signal to current process */
  sleep(3);
  kill(getpid(), SIGINT);
}

void foo_02_SIGALRM_handler(int _sig) {
  printf("Time out\n");
  exit(EXIT_SUCCESS);
}
void foo_02(void) {
  /* Registered the SIGALRM signal handler */
  signal(SIGALRM, foo_02_SIGALRM_handler);

  /* Count down two seconds, then send a SIGALRM signal to the current process */
  alarm(2);

  sleep(1024);
}

int idx = 0;
void foo_03_SIGALRM_handler(int _sig) {
  printf("KEN_MODE [%lu] %d\n", pthread_self(), ++idx);
}
void foo_03(void) {
  signal(SIGALRM, foo_03_SIGALRM_handler);

  struct itimerval time_value;
  time_value.it_value.tv_sec = 0;
  time_value.it_value.tv_usec = 1 * 1000;
  time_value.it_interval.tv_sec = 1;
  time_value.it_interval.tv_usec = 0;
  setitimer(ITIMER_REAL, &time_value, NULL);

  while (true) {
    printf("USR_MODE [%lu] %d\n", pthread_self(), ++idx);
    sleep(1);
  }
}



int main(int argc, char *argv[]) {
  /* foo_01(); */

  foo_03();

  return EXIT_SUCCESS;
}
