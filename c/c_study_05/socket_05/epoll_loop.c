#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <sys/epoll.h>
#include <arpa/inet.h>
#include <errno.h>
#include <unistd.h>

#define LISTEN_MAX_LIMIT 0x400

typedef struct ev_handler {
  void (*invoker)(int, void *);
  int fd;
  char buffer[128];
} ev_handler;

static ev_handler handlers[LISTEN_MAX_LIMIT] = { 0 };
static int sfd = 0;
static int epfd = 0;

void write_data(int cfd, void *arg);
void read_data(int cfd, void *arg);
void accept_new_client(int sf, void *arg);

void write_data(int cfd, void *arg) {
  ev_handler *handler = (ev_handler *)arg;

  if (strlen(handler->buffer) > 0) {
    write(cfd, handler->buffer, 128);
  }

  struct epoll_event ev;
  ev.events = EPOLLIN;
  handler->invoker = read_data;
  ev.data.ptr = handler;
  
  epoll_ctl(epfd, EPOLL_CTL_MOD, cfd, &ev);
}

void read_data(int cfd, void *arg) {
  ev_handler *handler = (ev_handler *)arg;

  bzero(handler->buffer, 128);
  int n = read(cfd, handler->buffer, 128);
  if (n <= 0) {
    printf("Read error or connection closed\n");

    handler->fd = -1;
    close(cfd);
    epoll_ctl(epfd, EPOLL_CTL_DEL, cfd, NULL);
  }
  
  struct epoll_event ev;
  ev.events = EPOLLOUT;
  handler->invoker = write_data;
  ev.data.ptr = handler;
  
  epoll_ctl(epfd, EPOLL_CTL_MOD, cfd, &ev);
}

void accept_new_client(int sf, void *arg) {
  struct sockaddr_in client;
  bzero(&client, sizeof(struct sockaddr_in));
  socklen_t len = sizeof(struct sockaddr);

  int cfd = accept(sfd, (struct sockaddr *)&client, &len);
  if (cfd < 0) exit(EXIT_FAILURE);

  char dest[16] = {0};
  printf("accept client [%s:%d]\n", inet_ntop(AF_INET, &client.sin_addr.s_addr, dest, sizeof(dest)), ntohs(client.sin_port));

  int idx = 0;
  for (;idx < LISTEN_MAX_LIMIT; ++idx) if (handlers[idx].fd == -1) break;
    
  handlers[idx].fd = cfd;
  handlers[idx].invoker = read_data;

  struct epoll_event ev;
  ev.events = EPOLLIN;
  ev.data.ptr = &handlers[idx];

  epoll_ctl(epfd, EPOLL_CTL_ADD, cfd, &ev);
}

void init_socket() {
  sfd = socket(AF_INET, SOCK_STREAM, 0x0);
  if (sfd < 0) exit(EXIT_FAILURE);

  struct sockaddr_in serv;
  bzero(&serv, sizeof(serv));
  serv.sin_family = AF_INET;
  serv.sin_port = htons(8886);
  inet_pton(AF_INET, "127.0.0.1", &serv.sin_addr.s_addr);
  int bflg = bind(sfd, (const struct sockaddr *)&serv, sizeof(serv));
  
  listen(sfd, LISTEN_MAX_LIMIT);
  printf("[INFO] Server start listen at [127.0.0.1:8886]\n");
}

void init_epoll() {
  for (size_t i = 0; i < LISTEN_MAX_LIMIT; ++i) handlers[i].fd = -1;

  epfd = epoll_create(LISTEN_MAX_LIMIT);

  ev_handler *handler = &handlers[LISTEN_MAX_LIMIT - 1];
  handler->fd = sfd;
  handler->invoker = accept_new_client;

  struct epoll_event ev;
  ev.events = EPOLLIN;
  ev.data.ptr = (void *)handler;

  epoll_ctl(epfd, EPOLL_CTL_ADD, sfd, &ev);
}

int main(int argc, char *argv[]) {
  init_socket();
  init_epoll();

  struct epoll_event events[LISTEN_MAX_LIMIT];
  while (true) {
    int nready = epoll_wait(epfd, events, LISTEN_MAX_LIMIT, -1);

    for (size_t i = 0; i < nready; ++i) {
      ev_handler *handler = (ev_handler *)events[i].data.ptr;
      handler->invoker(handler->fd, handler);
    }
  }

  close(epfd);
  close(sfd);
  
  return EXIT_SUCCESS;
}
