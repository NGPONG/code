#include <iostream>

#include "binary_tree.h"

int main(void) {
  binary_tree *tree = postorder_create_binaryTree(nullptr);
  travel_tree_by_level_order(tree);

  return EXIT_SUCCESS;
}
