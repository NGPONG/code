#include <math.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <semaphore.h>

void foo_01(void) {
  sem_t sem;
  sem_init(&sem, 1, 1);

  int val;

  sem_getvalue(&sem, &val);
  printf("%d\n", val);

  int ret = sem_trywait(&sem);
  printf("[%d] %s\n", ret, strerror(ret));

  sem_getvalue(&sem, &val);
  printf("%d\n", val);

  printf("world\n");
}

int main(int argc, char *argv[]) {
  foo_01();

  return EXIT_SUCCESS;
}
