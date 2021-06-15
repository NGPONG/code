#include <iostream>
#include <vector>
#include <list>
#include <queue>

using namespace std;

// 题目: 二叉树 Z 型遍历
//
// 和层序遍历的思想相同，只是我们维护多一个标量，来识别是单数层还是双数层
// 如果是单数层，那么正常插入，如果是双数层，因为要逆序输出，所以我们从头
// 插入即可

struct binary_tree {
  int elem;
  struct binary_tree *left;
  struct binary_tree *right;

  binary_tree(int elem) : elem(elem), left(nullptr), right(nullptr) {}
};

void binary_tree_z_shaped_traversal(binary_tree *root) {
  if (root == nullptr) return;

  vector<int> res;
  queue<binary_tree *> tree_q;
  tree_q.push(root);
  bool need_reverse = false;
  while (!tree_q.empty()) {
    list<int> tmp;

    int n = tree_q.size();
    for (int i = 0; i < n; ++i) {
      binary_tree *node = tree_q.front();
      tree_q.pop();

      if (need_reverse) {
        tmp.push_front(node->elem);
      } else {
        tmp.push_back(node->elem);
      }

      if (node->left) {
        tree_q.push(node->left);
      }
      if (node->right) {
        tree_q.push(node->right);
      }
    }

    for (auto i = tmp.begin(); i != tmp.end(); ++i) {
      res.push_back(*i);
    }
    need_reverse = !need_reverse;
  }

  for (auto val = res.begin(); val != res.end(); ++val) {
    cout << *val << endl;
  }
}

int main(void) {
  binary_tree root(1);

  binary_tree root_l(2);
  root.left = &root_l;
  binary_tree root_r(3);
  root.right = &root_r;

  binary_tree root_r_l(6);
  root_r.left = &root_r_l;
  binary_tree root_r_r(7);
  root_r.right = &root_r_r;

  binary_tree root_l_l(4);
  root_l.left = &root_l_l;
  binary_tree root_l_r(5);
  root_l.right = &root_l_r;

  binary_tree root_l_l_l(8);
  root_l_l.left = &root_l_l_l;

  binary_tree root_l_r_l(9);
  root_l_r.left = &root_l_r_l;

  binary_tree_z_shaped_traversal(&root);
  
  return EXIT_SUCCESS;
}
