#include <iostream>
#include <string>

using namespace std;

int main(void) {
  // 题目: 给定一个字符串 s 仅包含字符 '[' 和 ']'，要求输出该字符串完整的括号匹配
  // 例如: "]][][" -> "[[]][][]"
  //
  // 我们设定一个累加量，该累加量标示着 [] 的稳定性
  // 什么是稳定性？假设出现了一个 '[' 我们就让累加量 +1，假设下一个出现了一个 ']' 我们就让累加量 -1，也就意味着
  // 字符串 "[]" 是一个稳定的状态
  //
  // 那么在不稳定的情况下，假设累加量变成 -1，那么就意味着 ']' 多出了一个，那么相应的我们就需要想办法在字符串左
  // 变补齐一个 '['，反之，累加量不等于 0 的情况下，表示拥有富裕的 '['，那么我们就要在结束后，在字符串的右边补齐
  // ']'

  string s = "]][][";
  string l = "";
  string r = "";

  int cnt = 0;
  for (int i = 0; i < s.size(); ++i) {
    if (s[i] == '[') // 匹配到 '[' 的情况，那么累加量要 +1，相应的，在结束循环后，字符串的右边根据该累加量的总和来补齐 ']'
      ++cnt;
    else             // 匹配到 ']' 的情况，那么累加量要 -1，相应的字符串左边要补齐一个 '['
      --cnt;

    if (cnt < 0) {   // 出现了 ']' 不平衡的情况
      ++cnt;
      l += '[';
    }
  }

  for (int i = 0; i < cnt; ++i) 
    r += ']';

  string result = l + s + r;

  std::cout << result << std::endl;

  return EXIT_SUCCESS;
}
