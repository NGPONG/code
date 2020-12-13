#include <stdio.h>
#include <stdlib.h>

#define DEBUG(format, ...) printf(format, ##__VA_ARGS__)


int main(int argc, char *argv[]) {
  /* printf("%s[%d]", hello,world, 1024); */
  /* 当录入了可变参数的情况，使用特殊宏定义 __VA_ARGS__ 时，会在参数前面添加 ','
   */
  DEBUG("%s[%d]", "hello, world", 1024);

  /* printf("hello,world"); */
  /* 当未使用可变参数时，则不会在前面添加 ',' */
  DEBUG("hello,world");

  return EXIT_SUCCESS;
}
