#include <math.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <pthread.h>
#include <unistd.h>
#include <signal.h>

#include <sys/types.h>
#include <sys/syscall.h>

void *foo_01_thread_thread_start(void *_arg) {
  printf("child-child-thread executing\n");
  sleep(10);

  pthread_exit(NULL);
}
void *foo_01_thread_start(void *_agr) {
  pthread_t t_id;
  pthread_create(&t_id, NULL, foo_01_thread_thread_start, NULL);

  void *ret_val;
  pthread_join(t_id, &ret_val);

  printf("child-thread executing\n");

  sleep(5);

  return NULL;
}
void foo_01(void) {
  pthread_t t_id;
  pthread_create(&t_id, NULL, foo_01_thread_start, NULL);

  void *ret_val = NULL;
  pthread_join(t_id, &ret_val);

  printf("main-thread executing\n");
}

void *foo_02_thread_start(void *_arg) {
  printf("%p\n", _arg);

  exit(EXIT_SUCCESS);
}
void foo_02(void) {
  int i = 0x400;
  printf("%p\n", &i);
  pthread_t t_id;
  pthread_create(&t_id, NULL, foo_02_thread_start, &i);

  pthread_exit(NULL);
}

void *foo_03_thread_start(void *arg) {
  int idx = 0;
  while (true) {
    if (++idx == 5) {
      printf("[%lu] child thread exited\n", pthread_self());
      pthread_exit(NULL);
    }
    sleep(1);
  }
}
void foo_03(void) {
  for (size_t i = 0; i < 10; ++i) {
    pthread_t t_id;
    pthread_create(&t_id, NULL, foo_03_thread_start, NULL);

    printf("[%lu] create thread (%lu)\n", pthread_self(), t_id);
    fflush(stdout);

    /* pthread_detach(t_id); */
  }

  sleep(2);

  printf("[%lu] main thread exited\n", pthread_self());
  fflush(stdout);

  pthread_exit(NULL);
}

void *foo_04_thread_start(void *arg) {
  int idx = 0;
  while (true) {
    printf("%d\n", ++idx);
    sleep(1);

    if (idx == 60) {
      pthread_exit(NULL);
    }
  }

  return NULL;
}
void foo_04(void) {
  pthread_t t_id;
  pthread_create(&t_id, NULL, foo_04_thread_start, NULL);

  sleep(5);

  printf("main thread exit\n");

  pthread_exit(NULL);
}

void *foo_05_thread_handler(void *_arg) {
  int idx = 0;
  while (true) {
    if (idx == 5) {
      pthread_exit(NULL);
    }

    printf("[%lu] %d\n", pthread_self(), ++idx);
    sleep(1);
  }

  return NULL;
}
void foo_05(void) {
  pthread_t t_id;
  pthread_create(&t_id, NULL, foo_05_thread_handler, NULL);
  pthread_detach(t_id);

  sleep(5);

  pthread_exit(NULL);
}

void *foo_06_thread_start(void *_arg) {
  printf("child thread executed\n");

  int idx = 0;
  while (true) {
    printf("[%lu] %d\n", pthread_self(), ++idx);
    sleep(1);
  }

  return NULL;
}
void foo_06(void) {
  pthread_t t_id;
  pthread_create(&t_id, NULL, foo_06_thread_start, NULL);

  /* Sleep 3 sec. and kill child thread */
  sleep(3);

  pthread_cancel(t_id);

  printf("main thread executed\n");
  exit(EXIT_SUCCESS);
}

void foo_07(void) {
  printf("%d\n",pthread_equal(1,1));
}

void *foo_08_wait_sig_handler(void *_arg) {
  printf("[%lu](%lu) child-thread-signal executing\n", pthread_self(), syscall(SYS_gettid));

  sigset_t mask;
  sigemptyset(&mask);
  sigaddset(&mask, SIGUSR2);
  pthread_sigmask(SIG_BLOCK, &mask, NULL);

  siginfo_t sig_info;
  memset(&sig_info, 0, sizeof(siginfo_t));

  /* When this thread received SIGUSR2 siganl, exied immediately */
  int signum = sigwaitinfo(&mask, &sig_info);
  printf("[%lu] {%d} deliverd\n", pthread_self(), signum);

  pthread_exit(NULL);
  return NULL;
}

void *foo_08_thread_start(void *arg) {
  pthread_t wait_sig_tid;
  pthread_create(&wait_sig_tid, NULL, foo_08_wait_sig_handler, NULL);

  printf("[%lu](%lu) child-thread executing, create (%lu)\n", pthread_self(), syscall(SYS_gettid), wait_sig_tid);
  
  /* Wait for signal-child-thread exited */
  pthread_join(wait_sig_tid, NULL);

  printf("[%lu](%lu) child-thread exited\n", pthread_self(), syscall(SYS_gettid));
  return NULL;
}

void foo_08(void) {
  pthread_t t_id;
  pthread_create(&t_id, NULL, foo_08_thread_start, NULL);

  printf("[%lu](%lu) main-thread executing, create (%lu)\n", pthread_self(), syscall(SYS_gettid), t_id);
  
  /** 
   * Waiting for the exit of the signal sub-thread, 
   * BTW, this does not necessarily need to block waiting, 
   * it can handle anything asynchronously
   */
  pthread_join(t_id, NULL);
  printf("[%lu](%lu) man-thread exited\n", pthread_self(), syscall(SYS_gettid));

  exit(EXIT_SUCCESS);
}

int main(int argc, char *argv[]) {
  /* foo_01(); */
  /* foo_02(); */
  /* foo_03(); */
  /* foo_04(); */
  /* foo_05(); */
  /* foo_06(); */
  /* foo_07(); */

  foo_08();

  return EXIT_SUCCESS;
}
