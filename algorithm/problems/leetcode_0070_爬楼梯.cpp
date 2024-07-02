#include <iostream>
#include <vector>
#include <time.h>

#define STAIRS 40

// 题目: 每次只能走1步或者两步，求计算 N 级台阶最多拥有多少种走法
//
// 假设有 3 级台阶，那么就拥有 3 种走法，分别是:
// 1 1 1
// 1 2
// 2 1

// 暴力递归法
int stairs_100_1_impl(int stair) {
  if (stair <= 0) {
    return 0;
  }
  if (stair == 1) {
    return 1;
  }
  if (stair == 2) {
    return 2;
  }

  return stairs_100_1_impl(stair - 1) + stairs_100_1_impl(stair - 2);
}
void stairs_100_1(int stair) {
  clock_t start,end;
  start = clock();
  std::cout << stairs_100_1_impl(stair) << std::endl;
  end = clock();

  std::cout << end - start << std::endl;
}

// 记忆优化法
int stairs_100_2_impl(int stair, std::vector<int> &mem) {
  if (mem[stair] != -1) {
    return mem[stair];
  }
  if (stair <= 0) {
    return 0;
  }
  if (stair == 1) {
    return 1;
  }
  if (stair == 2) {
    return 2;
  }

  mem[stair] = stairs_100_2_impl(stair - 1, mem) + stairs_100_2_impl(stair - 2, mem);

  return mem[stair];
}
void stairs_100_2(int stair) {
  clock_t start,end;

  std::vector<int> mem(stair + 1, -1);
  start = clock();
  std::cout << stairs_100_2_impl(stair, mem) << std::endl;
  end = clock();

  std::cout << end - start << std::endl;
}

// 自底向上的动态规划
int stairs_100_3_impl(int stair) {
  std::vector<int> dp(stair + 1, -1);
  dp[0] = 0;
  dp[1] = 1;
  dp[2] = 2;

  for (int i = 3; i <= stair; ++i) {
    dp[i] = dp[i - 1] + dp[i - 2];
  }

  return dp[stair];
}
void stairs_100_3(int stair) {
  clock_t start,end;

  start = clock();
  std::cout << stairs_100_3_impl(stair) << std::endl;
  end = clock();

  std::cout << end - start << std::endl;
}


int main(void) {
  stairs_100_1(STAIRS);
  stairs_100_2(STAIRS);
  stairs_100_3(STAIRS);

  return EXIT_SUCCESS;
}
