#include <iostream>
#include <vector>
#include <string>

using namespace std;

// 题目: 将给定的字符串 str 循环右移动 k 位
//
// abcd1234 -> 1234abcd
// 首先将字符串下标为 0 ~ k - 1 位进行翻转
// 将剩下的部分再进行反转
// 二者合并后，整体再进行一次反转

void reverse(string &str, int start, int end) {
  char tmp;
  for (; start < end; ++start, --end) {
    tmp = str[start];
    str[start] = str[end];
    str[end] = tmp;
  }
}

void string_right_shift(string str, int k) {
  int n = str.size();
  reverse(str, 0, n - k - 1);
  reverse(str, k, n - 1);
  reverse(str, 0, n - 1);

  cout << str << endl;
}

int main(void) {
  string str = "abcd1234";
  int k = 4;
  string_right_shift(str, k);
  
  return EXIT_SUCCESS;
}
