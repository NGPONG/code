#include <arpa/inet.h>
#include <ctype.h>
#include <errno.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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

  fd_set tmp_fds, read_fds;
  FD_ZERO(&tmp_fds);
  FD_ZERO(&read_fds);

  FD_SET(sfd, &read_fds);

  char buf[0x400] = {0};
  int conn_count = 0;
  /**
   * 初始以监听文件描述符作为最大描述符，
   * 并在这个描述符的基础上，添加客户端
   * 读写的描述符
   */
  int max_fd = sfd;
  while (true) {
    /**
     * 为什么需要一个 temp 来暂存？
     *
     * 因为 select 函数返回后，都会改变 fd_set 原本所设置
     * 的文件描述符的状态
     */
    tmp_fds = read_fds;

    int nready = select(max_fd + 1, &tmp_fds, NULL, NULL, NULL);
    if (nready < 0)
      continue;

    if (FD_ISSET(sfd, &tmp_fds)) {
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
      printf("accept client [%s:%d]\n",
             inet_ntop(AF_INET, &client.sin_addr.s_addr, dest, sizeof(dest)),
             ntohs(client.sin_port));

      /* 这里这样写是有风险的，会造成服务器 TIME_WAIT 过多 */
      if (++conn_count == FD_SETSIZE) {
        close(cfd);
        continue;
      }

      /* 新创建的用于与 client 进行沟通的文件描述符转交由 select 进行监控 */
      FD_SET(cfd, &read_fds);
      if (max_fd < cfd)
        max_fd = cfd;

      /* 表示此刻仅仅只是监听到了连接请求，并无数据写入请求 */
      if (nready == 1)
        continue;
    }

    /**
     * 处理用于 client 通信文件描述符产生变化的情景
     *
     * 这里只需要操作用于跟 client 进行读写通信的文
     * 件描述符即可，更因为通信文件描述符的创建必定
     * 会在文件描述符之后，故初始下标仅需设置为监听
     * 描述符后面一位即可
     */
    for (size_t i = sfd + 1; i <= max_fd; ++i) {
      int cfd = i;
      if (!FD_ISSET(cfd, &tmp_fds))
        continue;

      bzero(buf, sizeof(buf));
      int n = read(cfd, buf, sizeof(buf));
      if (n <= 0) {
        printf("read over or client is closed\n");
        FD_CLR(cfd, &read_fds);
        close(cfd);
      }

      printf("receive %s", buf);
      write(cfd, buf, n);

      /* 本次仅有一个读写请求，故无需遍历后面的元素 */
      if (nready == 0)
        break;
    }
  }

  return EXIT_SUCCESS;
}
