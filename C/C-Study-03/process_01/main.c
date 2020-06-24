#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <unistd.h>
#include <fcntl.h>

#include <sys/time.h>
#include <sys/types.h>

void init(void) {
  int _fd = open("test.log", O_WRONLY | O_CREAT, 0644);
  if (_fd < 0x0) {
    perror("E");
    return;
  }

  char buf[0x8] = { 0 };
  for (int i = 0; i < 0x1024; ++i) {
    sprintf(buf, "%d\n", i);
    write(_fd, buf, strlen(buf));

    /* reset */
    memset(buf, 0x0, 0x8);
  }  
}

void foo_IO(void) {
}

void foo_mem(void) {

}

int main(int argc, char *argv[]) {
  struct timeval start;
  struct timeval end;

  /* start time */
  gettimeofday(&start, NULL);


  /* end time */
  gettimeofday(&end, NULL);

  /* complute time for use */
  unsigned long timer = 1000000 * (end.tv_sec - start.tv_sec) + end.tv_usec - start.tv_usec;
  printf("timer = %ld us\n", timer);

  return EXIT_SUCCESS;
}
