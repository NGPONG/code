// 题目: 求得二叉树的最小深度
//
// 该题采用广度优先遍历写法，层级从左往右的方式去遍历每个节点，并且每个子节点要在
// 其父节点所维护的 depth 的基础上 +1，切记一条特性是，由于是层级从左往右遍历节点
// 所以当最先出现某个节点为叶子节点的时候，则代表从根节点到该节点的深度最小，那么
// 我们返回维护的这个 depth 即可

#include "common.hpp"

int solution_1(TreeNode *root) {
  int min = 0;

  auto _solution = make_y_combinator([&](auto _solution, TreeNode *node, int depth = 0) -> void {
    if (!node) {
      return;
    }

    depth++;

    if (!node->left && !node->right) {
      min = !min ? depth : std::min(depth, min);
    } else {
      _solution(node->left, depth);
      _solution(node->right, depth);
    }
  });

  _solution(root);

  return min;
}

int solution_2(TreeNode *root) {
  int min = 0;

  if (!root) {
    return min;
  }

  int dp = 0;
  std::stack<std::pair<TreeNode *, int>> s;

  for (TreeNode *it = root; it || !s.empty();) {
    while (it) {
      dp++;

      if (it->left) {
        s.push(std::make_pair(it, dp));
        it = it->left;
      } else if (it->right) {
        it = it->right;
      } else {  
        min = !min ? dp : std::min(min, dp);
        it = nullptr;
      }
    }

    if (!s.empty()) {
      auto &pair = s.top();
      
      it = pair.first->right;
      dp = pair.second;

      s.pop();
    }
  }

  return min;
}

int main(int argc, char *argv[]) {
  TreeNode *bt = get_binary_tree();
  std::cout << bt << std::endl;

  std::cout << solution_1(bt) << std::endl;
  std::cout << solution_2(bt) << std::endl;

  return 0;
}


// #include <algorithm>
// #include <queue>
//
// using namespace std;
//
// struct node {
//   char elem;
//   struct node *left;
//   struct node *right;
// };
//
// int binary_tree_min_level(node *root) {
//   queue<pair<node *, int>> q;
//   q.emplace(root, 1);
//
//   while (!q.empty()) {
//     node *cur_node = q.front().first;
//     int depth = q.front().second;
//     q.pop();
//
//     if (cur_node->left == nullptr && cur_node->right == nullptr) {
//       return depth;
//     }
//
//     if (cur_node->left != nullptr) {
//       q.emplace(cur_node->left, depth + 1);
//     }
//     if (cur_node->right != nullptr) {
//       q.emplace(cur_node->right, depth + 1);
//     }
//   }
//
//   return 0;
// }
