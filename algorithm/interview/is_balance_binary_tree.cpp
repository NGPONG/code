#include <vector>
#include <algorithm>

using namespace std;

// 题目: 判断一棵树是否为平衡二叉树，当某个子树的其高度差大于 1 的话，那么就一定不是平衡二叉树
// 参考: https://leetcode-cn.com/problems/balanced-binary-tree/solution/ping-heng-er-cha-shu-by-leetcode-solution/

struct node {
  char elem;
  struct node *left;
  struct node *right;
};

int is_balance_binary_tree(node *root) {
  if (root == nullptr) {
    return 0;
  }

  int l_hight = is_balance_binary_tree(root->left);
  int r_hight = is_balance_binary_tree(root->left);
  if (l_hight == -1 || r_hight == -1 || abs(l_hight - r_hight) > 1) {
    return -1;
  } else {
    return max(l_hight, r_hight) + 1;
  }
}
