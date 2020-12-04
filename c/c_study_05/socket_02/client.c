#include <arpa/inet.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void EXIT(bool show_perror, int cfd) {
  /* close connection */
  if (cfd > 0)
    close(cfd);
  if (show_perror)
    perror("[ERROR]");

  exit(EXIT_FAILURE);
}

int main(int argc, char *argv[]) {
  int cfd = socket(AF_INET, SOCK_STREAM, 0x0);
  if (cfd < 0) EXIT(true, cfd);

  struct sockaddr_in serv;
  serv.sin_family = AF_INET;
  serv.sin_port = htons(8886);
  inet_pton(AF_INET, "127.0.0.1", &serv.sin_addr.s_addr);
  int cflg = connect(cfd, (struct sockaddr *)&serv, sizeof(serv));
  if (cflg < 0) EXIT(true, cfd);

  printf("[INFO] Success connect to server [%s:%d]\n", "127.0.0.1", ntohs(serv.sin_port));

  char buf[256] = {0};
  while (true) {
    bzero(buf, sizeof(buf));
    int n = read(STDIN_FILENO, buf, sizeof(buf));

    write(cfd, buf, n);

    bzero(buf, sizeof(buf));
    if (read(cfd, buf, sizeof(buf)) <= 0) {
      printf("[ERROR] Read error or server closed\n");
      EXIT(false, cfd);
    }
    printf("[INFO] Receive %s\n", buf);
  }

  return EXIT_SUCCESS;
}
