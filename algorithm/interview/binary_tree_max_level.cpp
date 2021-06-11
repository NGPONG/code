#include <algorithm>

using namespace std;

// 题目: 求得二叉树的最大深度
//
// 采用后序遍历的方式，当搜索到一个叶子节点的时候，则代表该节点的深度为 1，然后以
// 这个节点的深度的基础上再返回其父节点的位置，其父节点再依据这个节点再 +1，以此递归

struct node {
  char elem;
  struct node *left;
  struct node *right;
};

int binary_tree_max_level(node *root) {
  if (root == nullptr) return 0;

  return max(binary_tree_max_level(root->left), binary_tree_max_level(root->right)) + 1;
}
