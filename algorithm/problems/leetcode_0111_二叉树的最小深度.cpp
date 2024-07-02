#include <algorithm>
#include <queue>

using namespace std;

// 题目: 求得二叉树的最小深度
//
// 该题采用广度优先遍历写法，层级从左往右的方式去遍历每个节点，并且每个子节点要在
// 其父节点所维护的 depth 的基础上 +1，切记一条特性是，由于是层级从左往右遍历节点
// 所以当最先出现某个节点为叶子节点的时候，则代表从根节点到该节点的深度最小，那么
// 我们返回维护的这个 depth 即可

struct node {
  char elem;
  struct node *left;
  struct node *right;
};

int binary_tree_min_level(node *root) {
  queue<pair<node *, int>> q;
  q.emplace(root, 1);

  while (!q.empty()) {
    node *cur_node = q.front().first;
    int depth = q.front().second;
    q.pop();

    if (cur_node->left == nullptr && cur_node->right == nullptr) {
      return depth;
    }

    if (cur_node->left != nullptr) {
      q.emplace(cur_node->left, depth + 1);
    }
    if (cur_node->right != nullptr) {
      q.emplace(cur_node->right, depth + 1);
    }
  }

  return 0;
}
