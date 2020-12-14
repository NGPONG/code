#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <arpa/inet.h>
#include <signal.h>

#include <event2/event.h>
#include <event2/bufferevent.h>
#include <event2/buffer.h>
#include <event2/listener.h>
#include <event2/util.h>

void get_method_sys_supported(struct event_base *base);
void listener_cb(struct evconnlistener *, evutil_socket_t, struct sockaddr *, int socklen, void *);
void signal_cb(evutil_socket_t sig, short events, void *user_data);
void conn_writecb(struct bufferevent *, void *);
void conn_readcb(struct bufferevent *, void *);
void conn_eventcb(struct bufferevent *, short, void *);

int main(int argc, char *argv[]) {
  struct event_base *base = event_base_new();

  struct sockaddr_in serv;
  bzero(&serv, sizeof(serv));
  serv.sin_family = AF_INET;
  serv.sin_port = htons(8886);
  inet_pton(AF_INET, "127.0.0.1", &serv.sin_addr.s_addr);
  
  /* create listener */
  struct evconnlistener *listener = evconnlistener_new_bind(base, listener_cb, (void *)base,
      LEV_OPT_REUSEABLE|LEV_OPT_CLOSE_ON_FREE, /* ser port reuse and dispose socket(file decriptor) when listener dispose */
      -1, 
      (struct sockaddr*)&serv,
      sizeof(serv));
  if (listener == NULL) {
    perror("could not create listener");
    exit(EXIT_FAILURE);
  }

  /* register signal interrupt event */
  struct event *signal_event = evsignal_new(base, SIGINT, signal_cb, (void *)base);
  
  /* blocked and wait for new event callback occur  */
  event_base_dispatch(base);
  
  /* free resource */
  evconnlistener_free(listener);
  event_free(signal_event);
  event_base_free(base);

  return EXIT_SUCCESS;
}

void get_method_sys_supported(struct event_base *base) {
  /* poll */
  /* epoll */
  /* select */

  /* if base is null, then output the all methods supported in sys */
  if (base == NULL) {
    const char **methods = event_get_supported_methods();

    int idx = 0;
    while (methods[idx] != NULL) {
      printf("[%s]\n", methods[idx++]);
    }
  } else {
    const char *method = event_base_get_method(base);
    printf("[%s]\n", method);
  }
}

void listener_cb(struct evconnlistener *listener, evutil_socket_t fd, struct sockaddr *sa, int socklen, void *user_data) {
  struct event_base *base = user_data;

  struct bufferevent *bev = bufferevent_socket_new(base, fd, BEV_OPT_CLOSE_ON_FREE);
  if (!bev) {
    perror("Error constructing bufferevent!");
    event_base_loopbreak(base);
    return;
  }

  bufferevent_setcb(bev, conn_readcb, conn_writecb, conn_eventcb, NULL);
  bufferevent_enable(bev, EV_WRITE);
  bufferevent_enable(bev, EV_READ);
}

void signal_cb(evutil_socket_t sig, short events, void *user_data) {
  struct event_base *base = user_data;
  struct timeval delay = {2, 0};

  printf("Caught an interrupt signal; exiting cleanly in two seconds.\n");

  event_base_loopexit(base, &delay);
}

void conn_readcb(struct bufferevent *bev, void *user_data) {
  char buf[1024];
  bzero(buf, sizeof(buf));

  int n = bufferevent_read(bev, buf, sizeof(buf));
  printf("receive: %s", buf);

  bufferevent_write(bev, buf, n);
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
