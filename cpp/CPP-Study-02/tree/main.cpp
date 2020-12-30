#include <queue>
#include <iostream>

#include "binary_tree.h"

int main(void) {
  Binary_Tree *root = NULL;
  Postorder_Create_BinaryTree(root);

  std::queue<Binary_Tree *>q;
  q.push(root);

  uint32_t depth = 0;
  while (!q.empty()) {
    ++depth;

    int count = q.size();
    for (int i = 0; i < count; ++i) {
      Binary_Tree* node = q.front(); q.pop();
      if (node->left) q.push(node->left);
      if (node->right) q.push(node->right);
    }
  }

  std::cout << depth << std::endl;
  
  return EXIT_SUCCESS;
}
