#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <unistd.h>
#include <signal.h>

void handler(int _sig) { printf("handler executed!\n"); }

int main(int argc, char *argv[]) {
  printf("%d\n", getpid());

  struct sigaction act;
  act.sa_handler = handler;
  sigemptyset(&act.sa_mask);
  act.sa_flags = 0;

  sigaction(SIGINT, &act, NULL);

  sleep(1000);
  printf("process exited\n");

  return EXIT_SUCCESS;
}
