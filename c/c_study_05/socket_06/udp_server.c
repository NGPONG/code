#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUF_LEN 0X400

int main(int argc, char *argv[]) {
  int sfd = socket(AF_INET, SOCK_DGRAM, 0x0);

  struct sockaddr_in serv;
  bzero(&serv, sizeof(serv));
  serv.sin_family = AF_INET;
  serv.sin_port = htons(8886);
  inet_pton(AF_INET, "127.0.0.1", &serv.sin_addr.s_addr);
  int bflg = bind(sfd, (const struct sockaddr *)&serv, sizeof(serv));
  
  listen(sfd, 0x400);
  printf("[INFO] server start listen at [127.0.0.1:8886]\n");

  char buf[BUF_LEN];
  char dest[16];
  struct sockaddr_in client;
  socklen_t len = sizeof(struct sockaddr);
  while (true) {
    bzero(buf, BUF_LEN);
    bzero(&client, sizeof(struct sockaddr_in));

    int n = recvfrom(sfd, buf, BUF_LEN, 0, (struct sockaddr *)&client, &len);

    printf("[INFO] received [%s:%d] len: %d, msg: %s\n",
           inet_ntop(AF_INET, &client.sin_addr.s_addr, dest, sizeof(dest)),
           ntohs(client.sin_port), 
           n, 
           buf);

    bzero(buf, BUF_LEN);
    sprintf(buf, "hello,world! [%s:%d]",
            inet_ntop(AF_INET, &client.sin_addr.s_addr, dest, sizeof(dest)),
            ntohs(client.sin_port));

    sendto(sfd, buf, strlen(buf), 0, (struct sockaddr *)&client, len);
  }

  return EXIT_SUCCESS;
}

