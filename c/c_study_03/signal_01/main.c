#include <math.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <sys/time.h>
#include <signal.h>

void sig_handler(int _sig) {
  printf("[%d] Delivered signal: %d\n", getpid(), _sig);
  exit(EXIT_FAILURE);
}

void foo_01(void) {
  int fd[2] = { 0 };
  if (pipe(fd) == -1) {
    perror("open pipe error");
    return;
  }

  close(fd[0]);
  printf("start write\n");

  char *data = "hello,world!\n";
  write(fd[1], data, strlen(data) + 1);

  printf("end write\n");

  close(fd[1]);
}

void foo_02(void) {
  int pid = fork();
  if (pid < 0) {
    perror("create child process error");
    exit(EXIT_FAILURE);
  } else if (pid == 0) {
    int idx = 0;
    while (idx++ < 20) {
      printf("[%d] %d\n", getpid(), idx);
      sleep(1);
    }

    printf("[%d] child return\n", getpid());
  } else {
    while (true) {
      if (getchar() == 'a') {
        kill(pid, SIGINT);
        printf("parent exit\n");
        exit(EXIT_SUCCESS);
      }
    }
  }
}

void foo_03(void) {
  signal(SIGALRM, sig_handler);

  printf("%d\n", alarm(10));

  sleep(3);

  printf("%d\n", alarm(0));
}

void timer_invoker(int _sig) {
  printf("hello,world!\n");
}
void foo_04(void) {
  signal(SIGALRM, timer_invoker);

  struct itimerval ival;
  ival.it_interval.tv_sec = 1;
  ival.it_interval.tv_usec = 0;
  ival.it_value.tv_sec = 1;
  ival.it_value.tv_usec = 0;

  setitimer(ITIMER_REAL, &ival, NULL);

  usleep(1000 * 1000);
  sleep(10);
  printf("OK!");
}

void foo_05_timer_invoker(int sig) {
  printf("child process exit\n");
  exit(EXIT_SUCCESS);
}
void foo_05(void) {
  int pid = fork();
  if (pid < 0) {
    perror("create child process error");
    exit(EXIT_FAILURE);
  } else if (pid == 0) {
    signal(SIGALRM,foo_05_timer_invoker);

    sleep(0x400);
  } else if (pid > 0) {
    sleep(2);
    kill(pid, SIGALRM);
  }
}

void foo_06_timer(int sig) {
  printf("time out!\n");
  exit(EXIT_SUCCESS);
}
void foo_06(void) {
  signal(SIGALRM,foo_06_timer);
  
  alarm(5);

  sleep(10);
  printf("process exit!\n");
}

void foo_07_SIGINIT(int _sig) {
  printf("SIGINIT START\n");
  sleep(1024);
  printf("SIGINIT EXECUTED\n");
}
void foo_07_SIGUSER(int _sig) {
  printf("SIGUSER2 START\n");
  sleep(2);
  printf("SIGUSER2 EXECUTED\n");
}
void foo_07_SIGARM(int _sig) {
  printf("SIGARM START\n");
  printf("SIGARM EXECUTED\n");
}
void foo_07(void) {
  signal(SIGINT, foo_07_SIGINIT);
  signal(SIGALRM,foo_07_SIGARM);
  
  /* ignore SIGUSR2 signal */
  struct sigaction action;
  action.sa_handler = SIG_IGN;
  sigemptyset(&action.sa_mask);
  action.sa_flags = 0;
  sigaction(SIGUSR2,&action,NULL);

  signal(SIGUSR2, foo_07_SIGUSER);

  int idx = 0;
  while (true) {
    printf("[%d] executed %d times\n", getpid(), ++idx);
    sleep(1);
  }
}

int main(int argc, char *argv[]) {
  /* foo_01(); */
  /* foo_02(); */
  /* foo_03(); */
  /* foo_04(); */
  /* foo_05(); */
  /* foo_06(); */

  foo_07();

  return EXIT_SUCCESS;
}
