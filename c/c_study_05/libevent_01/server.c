#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <arpa/inet.h>
#include <signal.h>
#include <sys/stat.h> 
#include <fcntl.h>
#include <unistd.h>
#include <netinet/tcp.h>
#include <ctype.h>

#include <event2/event.h>
#include <event2/bufferevent.h>
#include <event2/buffer.h>
#include <event2/listener.h>
#include <event2/util.h>

#define MB 1024 * 1024

void listener_cb(struct evconnlistener *, evutil_socket_t, struct sockaddr *, int socklen, void *);
void conn_writecb(struct bufferevent *, void *);
void conn_readcb(struct bufferevent *, void *);
void conn_eventcb(struct bufferevent *, short, void *);

static int g_pkg_idx = 1;

int main(int argc, char *argv[]) {
  // redirect stdout to file
  int server_out_fd = open("./server.out", O_WRONLY | O_CREAT, S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH);
  if (server_out_fd == -1) {
    perror("create out file error");
    exit(EXIT_FAILURE);
  }
  dup2(server_out_fd, STDOUT_FILENO);

  // create new listener socket
  int sfd = socket(AF_INET, SOCK_STREAM, 0x0);
  if (sfd < 0) {
    perror("create socket pair error");
    exit(EXIT_FAILURE);
  }

  // set event base config and create new
  struct event_config* cfg = event_config_new();
  if (event_config_set_flag(cfg, EVENT_BASE_FLAG_EPOLL_USE_CHANGELIST) < 0)
    exit(EXIT_FAILURE);
  struct event_base *base = event_base_new_with_config(cfg);

  // set listing address info
  struct sockaddr_in serv;
  memset(&serv, 0x0, sizeof(serv));
  serv.sin_family = AF_INET;
  serv.sin_port = htons(8886);
  inet_pton(AF_INET, "0.0.0.0", &serv.sin_addr.s_addr);

  // create new listener
  struct evconnlistener *listener = evconnlistener_new_bind(
      base, 
      listener_cb, 
      (void *)base,
      LEV_OPT_REUSEABLE|LEV_OPT_CLOSE_ON_FREE, /* ser port reuse and dispose socket(file decriptor) when listener dispose */
      -1, 
      (struct sockaddr*)&serv,
      sizeof(serv));
  if (listener == NULL) {
    perror("could not create listener");
    exit(EXIT_FAILURE);
  }
  
  // blocked and wait for new event callback occur
  event_base_dispatch(base);
  
  // free resource
  evconnlistener_free(listener);
  event_base_free(base);
  close(server_out_fd);

  return EXIT_SUCCESS;
}

void listener_cb(struct evconnlistener *listener, evutil_socket_t fd, struct sockaddr *sa, int socklen, void *user_data) {
  struct event_base *base = user_data;

  struct bufferevent *bev = bufferevent_socket_new(base, fd, BEV_OPT_CLOSE_ON_FREE);
  if (!bev) {
    perror("Error constructing bufferevent!");
    event_base_loopbreak(base);
    return;
  }

  int optval = 1;
  int result = setsockopt(fd, IPPROTO_TCP, TCP_NODELAY, &optval, sizeof(optval));
  if (result < 0) {
    exit(EXIT_FAILURE);
  }
  int recv_buf_len = MB;
  setsockopt(fd, SOL_SOCKET, SO_RCVBUF, (char*)&recv_buf_len, sizeof(int));

  bufferevent_setcb(bev, conn_readcb, conn_writecb, conn_eventcb, NULL);

  bufferevent_enable(bev, EV_WRITE);
  bufferevent_enable(bev, EV_READ);

  struct evbuffer* input = bufferevent_get_input(bev);
  struct evbuffer* output = bufferevent_get_output(bev);
  evbuffer_expand(input, 20 * MB);
  evbuffer_expand(output, 20 * MB);

  bufferevent_set_max_single_read(bev, MB);
  bufferevent_set_max_single_write(bev, MB);
}

void conn_readcb(struct bufferevent *bev, void *user_data) {
  struct evbuffer *input = bufferevent_get_input(bev);
  if (!input) return;

  char *buf = malloc(sizeof(char) * 0x200);
  size_t len = evbuffer_get_length(input);
  unsigned char *data = evbuffer_pullup(input, len);
  memcpy(buf, data, len);
  evbuffer_drain(input, len);

  printf("[%d] %s\n", g_pkg_idx++, buf);
  fflush(stdout);

  usleep(100);
  free(buf);

  /* send msg */
  /* for (size_t i = 0; i < len; ++i) { */
  /*   buf[i] = toupper(buf[i]);        */
  /* }                                  */
  /* bufferevent_write(bev, buf, len);  */
}

void conn_writecb(struct bufferevent *bev, void *user_data) {
  struct evbuffer *output = bufferevent_get_output(bev);
  if (evbuffer_get_length(output) == 0) {
    printf("flushed answer\n");
  }
}

void conn_eventcb(struct bufferevent *bev, short events, void *user_data) {
  if (events & BEV_EVENT_EOF) {
    printf("Connection closed.\n");
  } else if (events & BEV_EVENT_ERROR) {
    printf("Got an error on the connection: %s\n", strerror(errno)); /* XXX win32 */
  }

  /* None of the other events can happen here, since we haven't enabled
   * timeouts */
  bufferevent_free(bev);
}
