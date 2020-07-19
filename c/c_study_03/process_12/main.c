#include <math.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <pthread.h>
#include <unistd.h>
#include <wait.h>

void *foo_01_thread_start(void *arg) {
  pthread_mutex_t *mutex = (pthread_mutex_t *)arg;
  
  /* start lock */
  /* pthread_mutex_lock(mutex); */
  int errno;
  if ((errno = pthread_mutex_trylock(mutex)) != 0) {
    printf("[%lu] %s\n", pthread_self(), strerror(errno));
    pthread_exit(NULL);
  }

  sleep(2);
  printf("[%lu] child-thread executed\n", pthread_self());

  /* end lock */
  pthread_mutex_unlock(mutex);
  return NULL;
}

void foo_01(void) {
  pthread_mutex_t mutex;
  pthread_mutex_init(&mutex, NULL);

  pthread_t threads[2] = { 0 };
  for (size_t i = 0; i < 2; ++i) {
    pthread_t t_id;
    pthread_create(&t_id, NULL, foo_01_thread_start, (void *)&mutex);

    printf("[%lu] create child thread (%lu)\n", pthread_self(), t_id);
    threads[i] = t_id;
  }

  for (int i = 1; i >= 0; --i) {
    pthread_join(threads[i], NULL);
    printf("[%lu] Recyle (%lu)\n", pthread_self(), threads[i]);
  }

  pthread_mutex_destroy(&mutex);
  pthread_exit(NULL);
}


void *foo_02_thread_start(void *arg) {
  pthread_spinlock_t *locker = (pthread_spinlock_t *)arg;
  
  /* start lock */
  pthread_spin_lock(locker);
  /* int errno;                                               */
  /* if ((errno = pthread_spin_trylock(locker)) != 0) {       */
  /*   printf("[%lu] %s\n", pthread_self(), strerror(errno)); */
  /*   pthread_exit(NULL);                                    */
  /* }                                                        */

  usleep(500 * 1000);
  
  /* end lock */
  pthread_spin_unlock(locker);

  printf("[%lu] child-thread executed\n", pthread_self());
  return NULL;
}
void foo_02(void) {
  pthread_spinlock_t locker;
  pthread_spin_init(&locker, PTHREAD_PROCESS_PRIVATE);

  pthread_t threads[20] = { 0 };
  for (size_t i = 0; i < 20; ++i) {
    pthread_t t_id;
    pthread_create(&t_id, NULL, foo_02_thread_start, (void *)&locker);

    printf("[%lu] create child thread (%lu)\n", pthread_self(), t_id);
    threads[i] = t_id;
  }

  for (int i = 0; i < 20; ++i) {
    pthread_join(threads[i], NULL);
    printf("[%lu] Recyle (%lu)\n", pthread_self(), threads[i]);
  }

  pthread_spin_destroy(&locker);
  pthread_exit(NULL);
}

void *foo_03_thread_start_1(void *arg) {
  pthread_rwlock_t *rwlocker = (pthread_rwlock_t *)arg;
  
  /* wait for read locker executed */
  sleep(1);

  /* start lock */
  pthread_rwlock_wrlock(rwlocker);
  printf("[%lu] Write lock\n", pthread_self());

  sleep(2);
  
  /* end lock */
  pthread_rwlock_unlock(rwlocker);

  printf("[%lu] Write locker executed\n", pthread_self());
  return NULL;
}

void *foo_03_thread_start_2(void *arg) {
  pthread_rwlock_t *rwlocker = (pthread_rwlock_t *)arg;

  /* start lock */
  pthread_rwlock_rdlock(rwlocker);
  printf("[%lu] Read lock\n", pthread_self());
  
  sleep(2);
  
  /* end lock */
  pthread_rwlock_unlock(rwlocker);

  printf("[%lu] Read locker executed\n", pthread_self());
  return NULL;
}

void foo_03(void) {
  pthread_rwlock_t rwlocker;
  pthread_rwlock_init(&rwlocker, NULL);

  pthread_t t_id_1;
  pthread_create(&t_id_1, NULL, foo_03_thread_start_1, (void *)&rwlocker);
  printf("[%lu] create child thread (%lu)\n",pthread_self(), t_id_1);

  pthread_t t_id_2;
  pthread_create(&t_id_2, NULL, foo_03_thread_start_2, (void *)&rwlocker);
  printf("[%lu] create child thread (%lu)\n",pthread_self(), t_id_2);

  pthread_join(t_id_1, NULL);
  pthread_join(t_id_2, NULL);

  pthread_rwlock_destroy(&rwlocker);
  pthread_exit(NULL);
}

pthread_mutex_t foo_04_mutex;
pthread_cond_t foo_04_cond;

void *foo_04_thread_start_01(void *arg) {
  while (true) {
    pthread_mutex_lock(&foo_04_mutex);
    printf("thread_01 locked\n");

    pthread_mutex_unlock(&foo_04_mutex);
    printf("thread_01 unlock\n");

    /* 唤醒任意一个使用了当前条件变量 pthread_cond_wait 的线程  */
    int flag = pthread_cond_signal(&foo_04_cond);
    printf("%d\n", flag);
    printf("send signal\n");
    int idx = 0x40;
    while (++idx <= 67) {
      printf("send thread [%d]\n", idx);
      sleep(1);
    }
  }
  return NULL;
}

void *foo_04_thread_start_02(void *arg) {
  pthread_mutex_lock(&foo_04_mutex);
  printf("thread_02 locked\n");
  
  /* 阻塞当前线程,并且唤醒一个使用了当前 mutex 的线程,直至那个线程调用了 唤醒 */
  printf("wait for signal\n");
  pthread_cond_wait(&foo_04_cond, &foo_04_mutex);
  printf("receive signal\n");
  int idx = 0;
  while (++idx <= 3) {
    printf("wait thread [%d]\n", idx);
    sleep(1);
  }

  pthread_mutex_unlock(&foo_04_mutex);
  printf("thread_02 unlock\n");

  return NULL;
}

void foo_04(void) {
  pthread_mutex_init(&foo_04_mutex, NULL);
  pthread_cond_init(&foo_04_cond, NULL);

  pthread_t t_id_1;
  pthread_create(&t_id_1, NULL, foo_04_thread_start_01, NULL);

  pthread_t t_id_2;
  pthread_create(&t_id_2, NULL, foo_04_thread_start_02, NULL);

  pthread_join(t_id_1, NULL);
  pthread_join(t_id_2, NULL);

  pthread_mutex_destroy(&foo_04_mutex);
  pthread_cond_destroy(&foo_04_cond);

  pthread_exit(NULL);
}

int main(int argc, char *argv[]) {
  /* foo_01(); */
  /* foo_02(); */
  /* foo_03(); */
  foo_04();

  return EXIT_SUCCESS;
}
