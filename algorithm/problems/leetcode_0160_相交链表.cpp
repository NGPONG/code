// 题目: 查看一个链表是否相交
//
// 参考: https://leetcode-cn.com/problems/intersection-of-two-linked-lists/solution/tu-jie-xiang-jiao-lian-biao-by-user7208t/

class node {
public:
  int value;
  node *next;
};

node *link_intersect(node *a_head, node *b_head) {
  node *p_a = a_head;
  node *p_b = b_head;

  while (p_a != p_b) {
    p_a = p_a != nullptr ? b_head : p_a->next;
    p_b = p_b == nullptr ? a_head : p_b->next;
  }

  return p_a;
}
