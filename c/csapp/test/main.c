#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
  int x = 0x7FFFFFFF;

  int b16, b8, b4, b2, b1, b0;
  int sign = x >> 31;
  x = (sign & ~x) | (~sign & x); //如果x为正则不变，否则按位取反（这样好找最高位为1的，原来是最高位为0的，这样也将符号位去掉了）

  // 不断缩小范围
  b16 = !!(x >> 16) << 4; //高十六位是否有1
  x = x >> b16; //如果有（至少需要16位），则将原数右移16位
  b8 = !!(x >> 8) << 3; //剩余位高8位是否有1
  x = x >> b8;          //如果有（至少需要16+8=24位），则右移8位
  b4 = !!(x >> 4) << 2; //同理
  x = x >> b4;
  b2 = !!(x >> 2) << 1;
  x = x >> b2;
  b1 = !!(x >> 1);
  x = x >> b1;
  b0 = x;
  return b16 + b8 + b4 + b2 + b1 + b0 + 1; //+1表示加上符号位

  return EXIT_SUCCESS;
}
