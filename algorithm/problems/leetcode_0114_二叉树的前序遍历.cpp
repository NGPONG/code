#include "common.hpp"

// 题目：给你二叉树的根节点 root ，返回它节点值的 前序 遍历。

void solutions_1(TreeNode *root) {
  if (!root) {
    return;
  }

  std::cout << root->val << std::endl;
  solutions_1(root->left);
  solutions_1(root->right);
}

void solutions_2(TreeNode *root) {
  std::stack<TreeNode *> s;

  while (!s.empty() || root) {
    while (root) {
      std::cout << root->val << std::endl;
      s.push(root);
      root = root->left;
    }

    if (!s.empty()) {
      root = s.top()->left; s.pop();
    }
  }
}

std::int32_t main (std::int32_t argc, char *argv[]) {
  TreeNode *bt = get_binary_tree(10);
  std::cout << bt << std::endl;

  solutions_1(bt);
  std::cout << "=====================" << std::endl;
  solutions_2(bt);

  return 0;
}
