#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>
#include <poll.h>

int main(int argc, char *argv[]) {
  int sfd = socket(AF_INET, SOCK_STREAM, 0x0);

  struct sockaddr_in serv;
  bzero(&serv, sizeof(serv));
  serv.sin_family = AF_INET;
  serv.sin_port = htons(8886);
  inet_pton(AF_INET, "127.0.0.1", &serv.sin_addr.s_addr);
  int bflg = bind(sfd, (const struct sockaddr *)&serv, sizeof(serv));
  
  listen(sfd, 0x400);
  printf("[INFO] Server start listen in [127.0.0.1:8888]\n");

  struct pollfd fds[0x400];
  for (size_t i = 0; i < 0x400; ++i) fds[i].fd = -1;
  
  /* monitor connection file descriptor */
  fds[0].fd = sfd;
  fds[0].events = POLLIN;
  int max_fd = 0;

  char buffer[0x400] = { 0 };
  while (true) {
    int nready = poll(fds, max_fd + 1, -1);
    if (nready < 0) continue;

    /* new connection arrived */
    if (fds[0].revents == POLLIN) {
      struct sockaddr_in client;
      bzero(&client, sizeof(struct sockaddr_in));
      socklen_t len = sizeof(struct sockaddr);

      int cfd = accept(sfd, (struct sockaddr *)&client, &len);
      if (cfd < 0) {
        if (errno == ECONNABORTED || errno == EINTR) {
          continue;
        }
        break;
      }
      char dest[16] = {0};
      printf("accept client [%s:%d]\n",inet_ntop(AF_INET, &client.sin_addr.s_addr, dest, sizeof(dest)), ntohs(client.sin_port));
      
      int i = 0;
      for (i = 0; i < 0x400; ++i) {
        if (fds[i].fd == -1) {
          fds[i].fd = cfd;
          fds[i].events = POLLIN;
          break;
        }
      }

      if (i == 0x400) {
        printf("Arrived the max limit connection, please wait a monents\n");
        close(cfd); /* This code has security risks. */
        continue;
      }
      if (max_fd < i) {
        max_fd = i;
      }
      /**
       * It's means that only one connection event occurs at the moment,
       * so we dont't need to executed flowing code at all
      */
      if (nready == 1) {
        continue;
      }
    }

    /* Process the read data event */
    for (size_t i = 1; i <= max_fd; ++i) {
      if (fds[i].fd == -1) continue;
      if (fds[i].revents != POLLIN) continue;

      int cfd = fds[i].fd;
      bzero(buffer, sizeof(buffer));

      int n = read(cfd, buffer, sizeof(buffer));
      if (n <= 0) {
        shutdown(cfd, SHUT_RDWR);
        fds[i].fd = -1;
        printf("[INFO] Read error or client closed\n");
        continue;
      } else {
        printf("receive %s", buffer);
        write(cfd, buffer, n);
      }

      if (nready == 1) break;
    }
  }

  shutdown(sfd, SHUT_RDWR);
  return EXIT_SUCCESS;
}
