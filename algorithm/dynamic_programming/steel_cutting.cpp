#include <iostream>
#include <vector>
#include <math.h>
#include <limits.h>
#include <algorithm>

int cut_steel_1_impl(int length, std::vector<int> &prices) {
  if (length == 0) {
    return 0;
  }

  int opt = -1;
  for (int i = 1; i <= length; ++i) {
    opt = std::max(opt, prices[i] + cut_steel_1_impl(length - i, prices));
  }

  return opt;
}
void cut_steel_1(std::vector<int> &prices) {
  for (int i = 1; i <= 10; ++i) {
    int opt = cut_steel_1_impl(i, prices);
    printf("尺寸为%d的最大收益为%d\n", i, opt);
  }
}


int cut_steel_2_impl(int length, std::vector<int> &prices, std::vector<int> &dp) {
  if (length == 0) {
    return 0;
  }
  if (dp[length] != INT_MAX) {
    return dp[length];
  }

  int opt = -1;
  for (int i = 1; i <= length; ++i) {
    opt = std::max(opt, prices[i] + cut_steel_2_impl(length - i, prices, dp));
  }

  if (opt == -1) {
    printf("detected opt = -1, length: %d\n", length);
    fflush(stdout);
  }

  dp[length] = opt;
  return opt;
}
void cut_steel_2(std::vector<int> &prices) {
  std::vector<int> dp(27, INT_MAX);

  for (int i = 1; i <= 27; ++i) {
    int opt = cut_steel_2_impl(i, prices, dp);
    printf("尺寸为%d的最大收益为%d\n", i, opt);
  }
}


int main(void) {
  std::vector<int> prices = { 0, 1, 5, 8, 9, 10, 17, 17, 20, 24, 30 };
  cut_steel_1(prices);
  // cut_steel_2(prices);

  return 0;
}
