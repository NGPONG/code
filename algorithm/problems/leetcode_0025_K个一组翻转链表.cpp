#include "common.hpp"

// 题目: 每过 k 次反转一次链表
// 例如: K = 3, 12345678 -> 32165478
//
// 利用栈的思想即可，每次遍历的时候压入栈中，到达第 k 次的时候，将栈中的元素挨个弹出就是一个反转的形态，拼接回即可

std::pair<ListNode *, ListNode *> constuct_newlist(std::stack<ListNode *> &s) {
  ListNode *head = s.top(); s.pop();

  ListNode *tail = head;
  while (!s.empty()) {
    ListNode *node = s.top(); s.pop();

    tail->next = node;
    tail = tail->next;
  }
  tail->next = nullptr;

  return { head, tail };
}

ListNode *solutions(ListNode *list, std::int32_t k) {
  if (list == nullptr || list->next == nullptr) {
    return list;
  }

  std::stack<ListNode *> s;

  // 1 2 3 4 5 6 7 8
  //
  // 3 2 1 6 5 4 7 8

  ListNode *it = list, *head = list, *tail = nullptr;

  for (std::int32_t idx = 1; it; ++idx) {
    if (!(idx % k + 1)) {
      auto [h, t] = constuct_newlist(s);
      tail->next = it;
    }

    s.push(it);

    it = it->next;
  }

  return new_list;
}

int main(void) {
  ListNode* node = get_desc_list(10);

  solutions(node, 3)->Foreach();


  return EXIT_SUCCESS;
}

// list<int> link = { 1, 2, 3, 4, 5, 6, 7, 8 };
// stack<int> cnt;
// int k = 3;
//
// int link_size = link.size();
// for (int i = 1; i <= link_size; ++i) { // 仅作为计数，所以从 1 开始
//   // 考虑最后的遍历的次数无法达到 k 的情况
//   if (link_size - i + 1 < k) {
//     for (int j = 1; j <= link_size - i + 1; ++j) {
//       link.push_back(link.front());
//       link.pop_front();
//     }
//
//     break;
//   }
//
//   cnt.push(link.front()); link.pop_front();
//
//   if (i % k == 0) {
//     for (int j = 1; j <= k; ++j) {
//       link.push_back(cnt.top());
//       cnt.pop();
//     }
//   }
// }
//
// for (auto val = link.begin(); val != link.end(); ++val) {
//   std::cout << *val;
// }
//
// std::cout << std::endl;
