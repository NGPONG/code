#include <math.h>
#include <pthread.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

static pthread_mutex_t mutex;
static pthread_cond_t cond;
static char data[64] = {0};

static void _init(void) {
  pthread_mutex_init(&mutex, NULL);
  pthread_cond_init(&cond, NULL);
}

static void _free(void) {
  pthread_mutex_destroy(&mutex);
  pthread_cond_destroy(&cond);
}

void *thread_start_main(void *_arg) {
  sleep(4);

  printf("main thread start lock\n");
  pthread_mutex_lock(&mutex); /* Start lock */
  
  sleep(1);

  pthread_mutex_unlock(&mutex); /* End lock */
  printf("main thread end lock\n");

  sleep(1);

  printf("main thread send wakeup signal\n");
  pthread_cond_broadcast(&cond);

  return NULL;
}

void *thread_start_child(void *_arg) {
  printf("child thread %d start lock\n", (int)pthread_self());
  pthread_mutex_lock(&mutex); /* Start lock */

  printf("child thread %d sleep and wait for wakeup signal arrived\n", (int)pthread_self());
  pthread_cond_wait(&cond, &mutex);
  
  int idx = 0;
  for (size_t i = 0; i < 5; ++i) {
    printf("child thread %d say hello [%d]\n", (int)pthread_self(), idx++);
    fflush(stdout);
    sleep(1);
  }

  printf("child thread %d end lock\n", (int)pthread_self());
  pthread_mutex_unlock(&mutex); /* End lock */

  return NULL;
}

void foo(void) {
  int t_ret;

  _init();

  pthread_t t_id_child_1;
  if ((t_ret = pthread_create(&t_id_child_1, NULL, thread_start_child, NULL))) {
    printf("%s\n", strerror(t_ret));
    exit(EXIT_FAILURE);
  }

  pthread_t t_id_child_2;
  if ((t_ret = pthread_create(&t_id_child_2, NULL, thread_start_child, NULL))) {
    printf("%s\n", strerror(t_ret));
    exit(EXIT_FAILURE);
  }

  pthread_t t_id_main;
  if ((t_ret = pthread_create(&t_id_main, NULL, thread_start_main, NULL))) {
    printf("%s\n", strerror(t_ret));
    exit(EXIT_FAILURE);
  }

  /* Wait for all thread executed */
  pthread_join(t_id_main, NULL);
  pthread_join(t_id_child_1, NULL);
  pthread_join(t_id_child_2, NULL);

  _free();
  pthread_exit(NULL);
}

int main(int argc, char *argv[]) {
  foo();

  return EXIT_SUCCESS;
}
