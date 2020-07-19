#include <math.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <pthread.h>
#include <unistd.h>

static pthread_mutex_t mutex;
static pthread_cond_t cond;
static char data[64] = { 0 };

static void _init(void) {
  pthread_mutex_init(&mutex, NULL);
  pthread_cond_init(&cond, NULL);
}

static void _free(void) {
  pthread_mutex_destroy(&mutex);
  pthread_cond_destroy(&cond);
}

void *producer_thread_start(void *_arg) {
  int idx = 0;

  while (true) {
    pthread_mutex_lock(&mutex);   /* Start lock */

    memset(data, 0x0, sizeof(data));
    sprintf(data, "%d\n", ++idx);

    pthread_mutex_unlock(&mutex); /* End lock */

    sleep(1);

    /* Notify consumer-thread to resume the context */
    pthread_cond_signal(&cond);
  }

  return NULL;
}
void *consumer_thread_start(void *_arg) {
  while (true) {
    pthread_mutex_lock(&mutex);   /* Start lock */

    if (strlen(data) == 0) {
      /* Suspend current thread executed and resume producter thread executed */
      pthread_cond_wait(&cond, &mutex);
    }
    printf("%s", data);

    /** 
     * It needs to be cleared to 0 after each read is completed, 
     * in order to prevent the current thread from preempting the CPU time slice in the next loop
     */
    memset(data, 0x0, sizeof(data));

    pthread_mutex_unlock(&mutex); /* End lock */
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
