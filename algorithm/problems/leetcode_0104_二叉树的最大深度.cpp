#include "common.hpp"

// 题目: 求得二叉树的最大深度
//
// 采用后序遍历的方式，当搜索到一个叶子节点的时候，则代表该节点的深度为 1，然后以
// 这个节点的深度的基础上再返回其父节点的位置，其父节点再依据这个节点再 +1，以此递归

int solution_1(TreeNode *root) {
  if (root == nullptr) {
    return 0;
  }

  int l_deep = solution_1(root->left);
  int r_deep = solution_1(root->right);

  return std::max(l_deep, r_deep) + 1;
}

int solution_2(TreeNode *it) {
  int dp = 0, max = 0;

  std::stack<std::pair<TreeNode *, int>> s;
  while (it || !s.empty()) {
    while (it) {
      // 0x1: 更新最大层数
      max = std::max(max, ++dp);

      // 0x2: 对应左子树为空的情况，此时开始遍历其当前节点下的右子树； 
      //
      //      由于下面的逻辑需要在遍历完一条路径的最终节点后按照栈的顺序挨个弹出上层节点并遍历
      //      其右子树。所以，如果此时还要将该节点入栈的话，则后续会产生重复的遍历以至死循环；
      if (!it->left) {
        it = it->right;
      } 
      // 0x3: 对应左子树不为空的情况，此时开始遍历其当前节点下的左子树；
      //
      //      总是从左子树开始，并不会立刻开始遍历当前节点可能存在的右子树。相应的，右子树的遍
      //      历工作会暂时缓存至栈中，并等待下面的逻辑执行；
      //
      //      要注意的是，为了方便后续遍历该节点的右子树时方便计算，栈中还缓存了右子树起始位置
      //      所在的层数dp。
      else {
        it = it->left;
        s.push(std::make_pair(it, dp));
      }
    }

    // 0x4: 栈中存放的是还未遍历右子树的节点，该步骤逐步弹出这些节点并完成后续的遍历工作；
    if (!s.empty()) {
      auto &pair = s.top();

      it = pair.first->right;
      dp = pair.second;

      s.pop();
    }
  }

  return max;
}

int main(int argc, char *argv[]) {
  TreeNode *bt = get_binary_tree();
  std::cout << bt << std::endl;

  std::cout << solution_1(bt) << std::endl;
  std::cout << solution_2(bt) << std::endl;

  return 0;
}
