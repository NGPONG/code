#include "common.hpp"

static unsigned int num = 0b101100111;

int solution_1(unsigned int n) {
  int count = 0;
  for (; n; ++count) {
    // 将 n 的最低位的 1 变成 0；并将后续的所有位都反转；
    unsigned int mask = n - 1;

    // 在上一步完成后，此时最低位的 1 此时为 0；且后续的所有位都被反转；

    // 此时与 mask 执行逻辑与操作的后就能够直接剔除掉找到的那一位至最低位的所有位；
    // 除非被剔除位置到最高位还有 1，否则结束循环；
    n &= mask;
  }

  return count;
}

int solution_2(unsigned int n) {
  int count = 0;

  for (; n; ++count) {
    // 统计从 num 低位开始直到到达1时需要经过几个 0
    unsigned int i = __builtin_ctz(n);

    // 左移 i 位并得到 __builtin_ctz 具体操作的那一位
    unsigned int mask = 1 << i;
    
    // 从 n 中移除那一位，并继续下一轮循环
    n &= ~mask;
  }

  return count;
}

int main (int argc, char *argv[]) {
  solution_1(num);
  solution_2(num);

  return 0;
}
