#include <math.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <unistd.h>
#include <ctype.h>
#include <signal.h>

void handler(int _sig) { printf("handler executed!\n"); }

int main(int argc, char *argv[]) {
  printf("%d\n", getpid());

  struct sigaction act;
  act.sa_handler = handler;
  sigemptyset(&act.sa_mask);
  act.sa_flags = 0;

  sigaction(SIGINT, &act, NULL);

  int sfd = socket(AF_INET, SOCK_STREAM, 0x0);
  if (sfd < 0) {
    perror("create socket pair error");
    exit(EXIT_FAILURE);
  }
  
  struct sockaddr_in serv;
  bzero(&serv, sizeof(serv));
  serv.sin_family = AF_INET;
  serv.sin_port = htons(8886);
  inet_pton(AF_INET, "0.0.0.0", &serv.sin_addr.s_addr);
  int bflg = bind(sfd, (const struct sockaddr *)&serv, sizeof(serv));
  if (bflg < 0) {
    perror("socket bind error");
    exit(EXIT_FAILURE);
  }
  
  /* start listen, client can connect to server right now */
  listen(sfd, 0x400);
  printf("start listen\n");

  /* pick a connection in connection queue */
  struct sockaddr_in client;
  bzero(&client, sizeof(struct sockaddr_in));
  socklen_t len = sizeof(struct sockaddr);
  int cfd = accept(sfd, (struct sockaddr *)&client, &len);
  if (cfd < 0) {
    perror("accept connect error");
    exit(EXIT_FAILURE);
  }
  char dest[16] = {0}; /* 4*3 + 3 + 1 */
  printf("accept client [%s:%d]\n",inet_ntop(AF_INET, &client.sin_addr.s_addr, dest, sizeof(dest)), ntohs(client.sin_port));
  
  char buf[0x400] = { 0 };
  while (true) {
    bzero(buf, sizeof(buf));
    
    printf("start waitting for new msg arrived\n");
    /* receive msg */
    int n = read(cfd, buf, sizeof(buf));
    if (n == -1) {
      perror("read msg error\n");
      exit(EXIT_FAILURE);
    }

    printf("receive: %s\n", buf);
    
    /* send msg */
    for (size_t i = 0; i < n; ++i) {
      buf[i] = toupper(buf[i]);
    }
    write(cfd, buf, n);
  }
  
  /* close connection */
  close(sfd);
  close(cfd);

  return EXIT_SUCCESS;
}
