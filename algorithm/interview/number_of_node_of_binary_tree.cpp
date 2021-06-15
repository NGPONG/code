#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// 题目: 求得二叉树第 k 层节点的个数
//
// 使用二叉树层序遍历的解法即可

struct node {
  char elem;
  struct node *left;
  struct node *right;
};

int binary_tree_number_of_node(node *root, int k) {
  queue<node *> q;
  q.push(root);

  int lv = 0;
  int lv_number = 0;
  while (!q.empty()) {
    ++lv;
    lv_number = q.size();
    if (lv == k) {
      break;
    }

    int n = q.size();
    for (int i = 0; i < n; ++i) {
      node *cur_nd = q.front();
      q.pop();

      if (cur_nd->left) {
        q.push(cur_nd->left);
      } else if (cur_nd->right) {
        q.push(cur_nd->right);
      }
    }
  }

  return lv_number;
}

int main(void) {

  return EXIT_SUCCESS;
}
