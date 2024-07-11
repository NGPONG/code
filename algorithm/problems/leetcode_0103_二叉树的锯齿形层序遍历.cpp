#include "common.hpp"

// 题目：
// 给你二叉树的根节点 root ，返回其节点值的 锯齿形层序遍历 。（即先从左往右，再从右往左进行下一层遍历，以此类推，层与层之间交替进行）。

std::vector<int> solutions(TreeNode *root) {
  std::vector<int> ret;

  std::queue<TreeNode *> qe;
  qe.push(root);

  bool reverise = false;
  while (!qe.empty()) {
    std::list<int> lst;
    
    // 操作本层所有的非空节点
    for (int i = 0, size = qe.size(); i < size; ++i) {
      TreeNode *node = qe.front(); qe.pop();
      
      // 如果需要反转，则执行头插；否则执行尾插
      if (reverise) {
        lst.push_front(node->val);
      } else {
        lst.push_back(node->val);
      }
      
      // 继续遍历下一层
      if (node->left) {
        qe.push(node->left);
      }
      if (node->right) {
        qe.push(node->right);
      }
    }
    // 将本轮（层）所需遍历的数据插入到返回集
    std::copy(std::begin(lst), std::end(lst), std::back_inserter(ret));
    
    // 每一层结束后调转一次反转关系
    reverise = !reverise;
  }

  return ret;
}

int main(int argc, char *argv[]) {
  TreeNode *bt = get_binary_tree(10);
  std::cout << bt << std::endl;

  std::cout << solutions(bt) << std::endl;

  return 0;
}
