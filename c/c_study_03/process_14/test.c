#include <math.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <semaphore.h>

void foo_01(void) {
  sem_t sem;
  sem_init(&sem, 1, 0);

  sem_post(&sem);
  sem_post(&sem);
  sem_post(&sem);

  sem_wait(&sem);
  printf("hello,");
  fflush(stdout);
  
  
  sem_wait(&sem);
  printf("world\n");
}

int main(int argc, char *argv[]) {
  foo_01();

  return EXIT_SUCCESS;
}
