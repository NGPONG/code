#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <sys/epoll.h>
#include <arpa/inet.h>
#include <errno.h>
#include <unistd.h>


int main(int argc, char *argv[]) {
  int sfd = socket(AF_INET, SOCK_STREAM, 0x0);

  struct sockaddr_in serv;
  bzero(&serv, sizeof(serv));
  serv.sin_family = AF_INET;
  serv.sin_port = htons(8886);
  inet_pton(AF_INET, "127.0.0.1", &serv.sin_addr.s_addr);
  int bflg = bind(sfd, (const struct sockaddr *)&serv, sizeof(serv));
  
  listen(sfd, 0x400);
  printf("[INFO] server start listen\n");

  int ep_fd = epoll_create(1024);

  struct epoll_event ev;
  ev.data.fd = sfd;
  ev.events = EPOLLIN;
  epoll_ctl(ep_fd, EPOLL_CTL_ADD, sfd, &ev);

  struct epoll_event events[1024] = { 0 };
  char buffer[1024] = { 0 };
  while (true) {
    int nready = epoll_wait(ep_fd, events, 1024, -1);
    if(nready < 0) continue;

    for (size_t i = 0; i < nready; ++i) {
      /* new client connection */
      if (events[i].data.fd == sfd) {
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
        printf("accept client [%s:%d]\n", inet_ntop(AF_INET, &client.sin_addr.s_addr, dest, sizeof(dest)), ntohs(client.sin_port));
        
        ev.data.fd = cfd;
        ev.events = EPOLLIN | EPOLLET;
        epoll_ctl(ep_fd, EPOLL_CTL_ADD, cfd, &ev);

        continue;
      }

      /* Process the read data event */
      int cfd = events[i].data.fd;

      bzero(buffer, sizeof(buffer));
      int n = read(cfd, buffer, 2);
      if (n <= 0) {
        printf("Read error or connection closed\n");
        close(cfd);
        epoll_ctl(ep_fd, EPOLL_CTL_DEL, cfd, NULL);
        continue;
      }
      
      printf("receive %s", buffer);
      write(cfd, buffer, n);
    }
  }
  
  close(ep_fd);
  close(sfd);
  return EXIT_SUCCESS;
}
