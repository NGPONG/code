#include <arpa/inet.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
  int cfd = socket(AF_INET, SOCK_STREAM, 0x0);
  if (cfd < 0) {
    perror("create socket pair error");
    exit(EXIT_FAILURE);
  }

  struct sockaddr_in serv;
  serv.sin_family = AF_INET;
  serv.sin_port = htons(8886);
  inet_pton(AF_INET, "127.0.0.1", &serv.sin_addr.s_addr);
  int cflg = connect(cfd, (struct sockaddr *)&serv, sizeof(serv));
  if (cflg < 0) {
    perror("connect to server error");
    exit(EXIT_FAILURE);
  }
  printf("success connect to server <%s:%d>\n", "127.0.0.1", ntohs(serv.sin_port));
  fflush(stdout);

  char *buf = "hello,world";
  while (true) {
    write(cfd, buf, strlen(buf));
    usleep(200);
  }

  close(cfd);
  return EXIT_SUCCESS;
}
