#include "common.hpp"

// 题目: 判断一棵树是否为平衡二叉树，当某个子树的其高度差大于 1 的话，那么就一定不是平衡二叉树
// 参考: https://leetcode-cn.com/problems/balanced-binary-tree/solution/ping-heng-er-cha-shu-by-leetcode-solution/

// 依据二叉树求最大深度的思想；
// 在每次过程中，当递归返回了当前节点的左子树和右子树的深度后，我们就可以计算这两个子树的深度是否符合规范；
// 另外，在递归返回上层节点的时候，则又是一个子问题的求解过程；

bool solution(TreeNode *root) {
  bool is_balance = true;

  auto _solution = make_y_combinator([&](auto _solution, TreeNode *node) -> int {
    if (!node || !is_balance) {
      return 0;
    }

    int l_deep = _solution(node->left);
    int r_deep = _solution(node->right);

    if (l_deep - r_deep >= 2 || r_deep - l_deep >= 2) {
      is_balance = false;
    }

    return std::max(l_deep, r_deep) + 1;
  });

  _solution(root);

  return is_balance;
}

int main(int argc, char *argv[]) {
  TreeNode *bt = get_binary_tree();
  std::cout << bt << std::endl;

  solution(bt);

  return 0;
}
