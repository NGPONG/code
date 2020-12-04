#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <ctype.h>

void EXIT(bool show_perror, int cfd, int sfd) {
  /* close connection */
  if (sfd > 0)
    close(sfd);
  if (cfd > 0)
    close(cfd);
  if (show_perror)
    perror("[ERROR]");

  exit(EXIT_FAILURE);
}

void connection_handler(int _cfd) {
  printf("[INFO] [%d] start waitting for new msg arrived\n", getpid());

  char buf[0x400] = {0};
  while (true) {
    bzero(buf, sizeof(buf));

    /* receive msg */
    int n = read(_cfd, buf, sizeof(buf));
    if (n <= 0) break;
    printf("receive: %s\n", buf);

    /* send msg */
    for (size_t i = 0; i < n; ++i) {
      buf[i] = toupper(buf[i]);
    }
    write(_cfd, buf, n);
  }
}

int main(int argc, char *argv[]) {
  int sfd = socket(AF_INET, SOCK_STREAM, 0x0);
  if (sfd < 0) EXIT(true, 0, sfd);

  struct sockaddr_in serv;
  bzero(&serv, sizeof(serv));
  serv.sin_family = AF_INET;
  serv.sin_port = htons(8886);
  inet_pton(AF_INET, "127.0.0.1", &serv.sin_addr.s_addr);
  int bflg = bind(sfd, (const struct sockaddr *)&serv, sizeof(serv));
  if (bflg < 0) EXIT(true, 0, sfd); 
  
  listen(sfd, 0x400);
  printf("[INFO] server start listen\n");

  while (true) {
    /* pick a connection in connection queue */
    struct sockaddr_in client;
    bzero(&client, sizeof(struct sockaddr_in));
    socklen_t len = sizeof(struct sockaddr);
    int cfd = accept(sfd, (struct sockaddr *)&client, &len);
    if (cfd < 0) EXIT(true, cfd, sfd);

    /* print connection header info */
    char dest[16] = {0}; /* 4*3 + 3 + 1 */
    printf("[INFO] Accept client [%s:%d]\n", inet_ntop(AF_INET, &client.sin_addr.s_addr, dest, sizeof(dest)), ntohs(client.sin_port));
    
    /* create a new child process to handle msg connection */
    int pid = fork();
    if (pid > 0) {
      continue;
    } else if (pid == 0) {
      connection_handler(cfd);
      EXIT(true, cfd, sfd);
    } else {
      EXIT(true, cfd, sfd);
    }
  }

  return EXIT_SUCCESS;
}
