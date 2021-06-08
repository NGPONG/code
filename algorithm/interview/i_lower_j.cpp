#include <iostream>
#include <vector>

// 题目: 给一数组，找出一对 (i,j)，满足 i<j && arrary[i] < arrary[j]，并且 j - i 的值所有配对中最大

// O(n^2)
std::pair<int, int> foo_1(std::vector<int> &arrary) {
  int len = arrary.size() - 1;
  
  int idx_i = 0;
  int idx_j = 0;
  int max = 0;
  for (int i = 0; i < len; ++i) {
    int j = len;
    for (; j > i; --j) {
      if (arrary[i] < arrary[j]) {
        break;
      }
    }

    if (j - i > max) {
      idx_i = i;
      idx_j = j;
      max = j - i;
    }
  }

  return std::make_pair(idx_i, idx_j);
}



int main(void) {
  
  
  return EXIT_SUCCESS;
}
