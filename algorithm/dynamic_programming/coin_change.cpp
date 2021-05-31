#include <iostream>
#include <stdlib.h>
#include <algorithm>
#include <limits.h>
#include <time.h>
#include <vector>

// 假设我有3种类型的硬币，分别为 2元、5元、7元，问: 最少使用多少个硬币可以拼出 27 元
//
// 分析得到最优子问题为: 
//  最少使用多少个硬币可以拼出 27 - a_k 元
// 这里，a_k 则为所提供的三种类型的硬币中的一种，因为它仅能取这三种情况，那么当我们对该最优子问题进行划分，并取得最小值，则为所提供的公式:
//  f(x) = min{ f(x - a_2) + 1, f(x - a_5) + 1, f(x - a_7) + 1 }
// 在这里，+1 的目的是为了加上减去的 a_k 
//
// 代码实现中稍微优化了以下，即原题所提供的恒定的币种改为 k 种币种

void print_res(int ret, clock_t t_start, clock_t t_end) {
  if (ret != INT_MAX) {
    std::cout << ret << std::endl;
  } else {
    std::cout << "not pair" << std::endl;
  }

  std::cout << t_end - t_start << std::endl;
}

int coin_change_1_impl(int value, std::vector<int> &coins) {
  if (value == 0) {
    return value;
  }
  if (value < 0) {
    return INT_MAX;
  }

  int res = INT_MAX;
  for (auto coin = coins.begin(); coin != coins.end(); ++coin) {
    int opt = coin_change_1_impl(value - *coin, coins);
    res = std::min(res, opt);
  }

  return res == INT_MAX ? INT_MAX : res + 1;
}
int coin_change_1(int value, std::vector<int> &coins) {
  return coin_change_1_impl(value, coins);
}

int coin_change_2_imp(int value, int *dp, std::vector<int> &coins) {
  if (value == 0) {
    return value;
  }
  if (value < 0) {
    return INT_MAX;
  }
  if (dp[value] != INT_MIN) {
    return dp[value];
  }

  int res = INT_MAX;
  for (auto coin = coins.begin(); coin != coins.end(); ++coin) {
    int opt = coin_change_2_imp(value - *coin, dp, coins);
    res = std::min(res, opt);
  }

  dp[value] = res == INT_MAX ? INT_MAX : res + 1;
  return dp[value];
}
int coin_change_2(int value, std::vector<int> &coins) {
  int dp[value + 1];
  dp[0] = 0;
  for (int i = 1; i <= value; ++i) {
    dp[i] = INT_MIN;
  }

  return coin_change_2_imp(value, dp, coins);
}

void coin_change_3(int value, std::vector<int> &coins) {
  std::vector<int> dp(value + 1, INT_MIN);
  dp[0] = 0;

  for (int i = 1; i <= value; ++i) {
    for (auto coin = coins.begin(); coin != coins.end(); ++coin) {
      
    }
  }
}

int main(void) {
  clock_t start,end;
  int N = 50, ret = 0;

  std::vector<int> coins = { 2, 5 ,7 };

  start = clock();
  ret = coin_change_1(N, coins);
  end = clock();
  print_res(ret, start, end);

  start = clock();
  ret = coin_change_2(N, coins);
  end = clock();
  print_res(ret, start, end);

  return 1;
}
