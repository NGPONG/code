// 题目：
// 给你链表的头结点 head ，请将其按 升序 排列并返回 排序后的链表 。

#include "common.hpp"

// 计数排序；考虑如何处理负值的问题
void solutions(ListNode *head) {
  int max_val = head->val;
  int min_val = head->val;
  for (auto it = head; it; it = it->next) {
    max_val = std::max(it->val, max_val);
    min_val = std::min(it->val, min_val);
  }

  int size = max_val - min_val + 1;

  int *count_arr = new int[size]{ 0 };
  for (auto it = head; it; it = it->next) {
    count_arr[it->val - min_val]++;
  }

  auto it = head;
  for (int i = 0; i < size; ++i) {
    for (int j = 0; j < count_arr[i]; ++j) {
      it->val = i + min_val;
      it      = it->next;
    }
  }

  delete[] count_arr;
}

int main(int argc, char *argv[]) {
  ListNode *list = get_list_desc();
  std::cout << list << std::endl;

  solutions(list);

  std::cout << list << std::endl;

  return 0;
}
