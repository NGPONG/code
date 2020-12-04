#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <ctype.h>
#include <pthread.h>

void *connection_handler(void *arg) {
  int cfd = *(int *)arg;

  printf("[INFO] [%lu] start waitting for new msg arrived\n", pthread_self());

  char buf[0x400] = {0};
  while (true) {
    bzero(buf, sizeof(buf));

    /* receive msg */
    int n = read(cfd, buf, sizeof(buf));
    if (n <= 0) {
      printf("read error or client closed\n");
      close(cfd);
      break;
    }
    printf("[%d] receive: %s\n", n, buf);

    /* send msg */
    for (size_t i = 0; i < n; ++i) {
      buf[i] = toupper(buf[i]);
    }
    write(cfd, buf, n);
  }
  
  pthread_exit(NULL);
  return NULL;
}

int main(int argc, char *argv[]) {
  int sfd = socket(AF_INET, SOCK_STREAM, 0x0);

  struct sockaddr_in serv;
  bzero(&serv, sizeof(serv));
  serv.sin_family = AF_INET;
  serv.sin_port = htons(8887);
  inet_pton(AF_INET, "127.0.0.1", &serv.sin_addr.s_addr);
  int bflg = bind(sfd, (const struct sockaddr *)&serv, sizeof(serv));
  
  listen(sfd, 0x400);
  printf("[INFO] server start listen at [127.0.0.1:8887]\n");

  while (true) {
    /* pick a connection in connection queue */
    struct sockaddr_in client;
    bzero(&client, sizeof(struct sockaddr_in));
    socklen_t len = sizeof(struct sockaddr);
    int cfd = accept(sfd, (struct sockaddr *)&client, &len);

    /* print connection header info */
    char dest[16] = {0};
    printf("[INFO] Accept client [%s:%d]\n", inet_ntop(AF_INET, &client.sin_addr.s_addr, dest, sizeof(dest)), ntohs(client.sin_port));
    
    /* create a new thread to handle msg connection */
    pthread_t thread_id = 0;
    pthread_create(&thread_id, NULL, connection_handler, &cfd);
    pthread_detach(thread_id);
  }

  return EXIT_SUCCESS;
}
