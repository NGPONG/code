#include <iostream>
#include <list>
#include <stack>

using namespace std;

// 题目: 每过 k 次反转一次链表
// 例如: K = 3, 12345678 -> 32165478
//
// 利用栈的思想即可，每次遍历的时候压入栈中，到达第 k 次的时候，将栈中的元素挨个弹出就是一个反转的形态，拼接回即可

int main(void) {
  list<int> link = { 1, 2, 3, 4, 5, 6, 7, 8 };
  stack<int> cnt;
  int k = 3;

  int link_size = link.size();
  for (int i = 1; i <= link_size; ++i) { // 仅作为计数，所以从 1 开始
    // 考虑最后的遍历的次数无法达到 k 的情况
    if (link_size - i + 1 < k) {
      for (int j = 1; j <= link_size - i + 1; ++j) {
        link.push_back(link.front());
        link.pop_front();
      }

      break;
    }

    cnt.push(link.front()); link.pop_front();

    if (i % k == 0) {
      for (int j = 1; j <= k; ++j) {
        link.push_back(cnt.top());
        cnt.pop();
      }
    }
  }

  for (auto val = link.begin(); val != link.end(); ++val) {
    std::cout << *val;
  }

  std::cout << std::endl;

  return EXIT_SUCCESS;
}
