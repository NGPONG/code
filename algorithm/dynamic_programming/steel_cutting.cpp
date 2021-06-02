#include <iostream>
#include <vector>
#include <math.h>
#include <time.h>

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
  clock_t start,end;
  start = clock();

  for (int i = 1; i <= 27; ++i) {
    int opt = cut_steel_1_impl(i, prices);
    printf("尺寸为%d的最大收益为%d\n", i, opt);
  }

  end = clock();
  printf("%lu\n", end - start);
}

int cut_steel_2_impl(int length, std::vector<int> &prices, std::vector<int> &dp) {
  if (length == 0) {
    return 0;
  }
  if (dp[length] != -1) {
    return dp[length];
  }

  int opt = -1;
  for (int i = 1; i <= length; ++i) {
    opt = std::max(opt, prices[i] + cut_steel_2_impl(length - i, prices, dp));
  }
  
  dp[length] = opt;
  return opt;
}
void cut_steel_2(std::vector<int> &prices) {
  std::vector<int> dp(27, -1);

  clock_t start,end;
  start = clock();

  for (int i = 1; i <= 27; ++i) {
    int opt = cut_steel_2_impl(i, prices, dp);
    printf("尺寸为%d的最大收益为%d\n", i, opt);
  }

  end = clock();
  printf("%lu\n", end - start);
}


int main(void) {
  std::vector<int> prices = { 0, 1, 5, 8, 9, 10, 17, 17, 20, 24, 30 };
  cut_steel_1(prices);
  cut_steel_2(prices);

  return 0;
}
