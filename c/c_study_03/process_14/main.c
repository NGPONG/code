#include <math.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>

static sem_t sem_producer;
static sem_t sem_consumer;
static char data[64] = { 0 };

static void _init(void) {
  sem_init(&sem_producer, 0, 2);
  sem_init(&sem_consumer, 0, 0);
}

static void _free(void) {
  sem_destroy(&sem_producer);
  sem_destroy(&sem_consumer);
}

void *producer_thread_start(void *_arg) {
  int idx = 0;

  while (true) {
    sem_wait(&sem_producer); /* Start lock, sem-- */
    int val = 0;
    sem_getvalue(&sem_producer, &val);
    printf("p = %d\n",val);

    memset(data, 0x0, sizeof(data));
    sprintf(data, "%d\n", ++idx);

    sem_post(&sem_consumer); /* End lock, sem++ */
  }

  return NULL;
}
void *consumer_thread_start(void *_arg) {
  while (true) {
    /* 当 sem 执行前 == 0 或者本次操作后 == 0 则阻塞 */
    sem_wait(&sem_consumer); /* Start lock, sem-- */
    int val = 0;
    sem_getvalue(&sem_consumer, &val);
    printf("c = %d\n",val);

    printf("%s", data);
    memset(data, 0x0, sizeof(data));

    sem_post(&sem_producer); /* End lock, sem++ */

    sleep(1);
  }

  return NULL;
}
void foo(void) {
  int t_ret;

  _init();

  /* Create producter process */
  pthread_t t_id_producer;
  if ((t_ret = pthread_create(&t_id_producer, NULL, producer_thread_start, NULL))) {
    printf("%s\n", strerror(t_ret));
    exit(EXIT_FAILURE);
  }
  /* Create consumer process */
  pthread_t t_id_consumer;
  if ((t_ret = pthread_create(&t_id_consumer, NULL, consumer_thread_start, NULL))) {
    printf("%s\n", strerror(t_ret));
    exit(EXIT_FAILURE);
  }

  /* Wait for all thread executed */
  pthread_join(t_id_producer, NULL);
  pthread_join(t_id_consumer, NULL);

  _free();
  pthread_exit(NULL);
}

int main(int argc, char *argv[]) {
  foo();

  return EXIT_SUCCESS;
}
