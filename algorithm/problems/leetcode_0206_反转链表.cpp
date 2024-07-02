#include "common.hpp"

// 题目：
// 给你单链表的头节点 head ，请你反转链表，并返回反转后的链表。

// 双链表实现
ListNode *solutions_1(ListNode *head) {
  ListNode *new_list = nullptr;

  while (head) {
    ListNode *next = head->next; // 暂存 next 指针

    ListNode *tmp = head;     // 获取链表的头节点
    tmp->next     = new_list; // 提取链表的头节点并拼接到新链表
    new_list      = tmp;

    head = next;
  }

  return new_list;
}

// 栈实现
ListNode *solutions_2(ListNode *head) {
  if (head == nullptr || head->next == nullptr) {
    return head;
  }

  std::stack<ListNode *> s;

  ListNode *it = head;
  while (it) {
    s.push(it);
    it = it->next;
  }

  ListNode *first = s.top(); s.pop();

  it = first;
  while (true) {
    ListNode *prev = s.top(); s.pop();

    it->next = prev;
    it       = it->next;

    if (s.empty()) {
      it->next = nullptr;
      break;
    }
  }

  return first;
}

std::int32_t main(std::int32_t argc, char *argv[]) {
  ListNode *node = get_desc_list(10);

  solutions_1(node)->Foreach();
  // solutions_2(node)->Foreach();

  return 0;
}
