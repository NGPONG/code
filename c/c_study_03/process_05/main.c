#include <math.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <fcntl.h>
#include <unistd.h>
#include <wait.h>
#include <sys/stat.h>

int main(int argc, char *argv[]) {
  int fd = open("./test.log", O_RDONLY);
  if (fd < 0) {
    perror("E");
    exit(EXIT_FAILURE);
  }

  char buf[5] = { 0 };

  int pid = fork();
  if (pid < 0) {
    perror("E");
    exit(EXIT_FAILURE);
  } else if (pid > 0) {  /* parent process */
    /* wait for child process complete and cycle resources */
    int stat;
    wait(&stat);

    read(fd, buf, sizeof(buf));
    printf("%s\n", buf);

    close(fd);
    exit(EXIT_SUCCESS);
  } else if (pid == 0) { /* child process */
    while ((read(fd, buf, sizeof(buf)))) {
      if (strcmp(buf, "\n") == 0) {
        break;
      }

      printf("%s\n", buf);
      memset(buf, 0x0, sizeof(buf));
    }
    
    /* child process open a new file and try to read it */
    int fd_chd = open("./test2.log", O_RDONLY);
    if (fd_chd < 0) {
      perror("E");
      exit(EXIT_SUCCESS);
    }

    read(fd_chd, buf, sizeof(buf));
    printf("%s\n", buf);
    
    close(fd_chd);
    exit(EXIT_SUCCESS);
  }

  return EXIT_SUCCESS;
}
