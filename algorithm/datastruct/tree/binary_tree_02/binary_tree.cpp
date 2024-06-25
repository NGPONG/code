#include "binary_tree.h"
#include <queue>

/* Perfect Binary Tree
 *                                (A)
 *                                 |
 *                 o---------------+---------------o
 *                 |                               |
 *                (B)                             (C)
 *                 |                               |
 *          o------+-----o                  o------+-----o
 *          |            |                  |            |
 *         (D)          (E)                (F)          (G)
 *          |            |                  |            |
 *      o---+---o    o---+---o          o---+---o    o---+---o
 *      |       |    |       |          |       |    |       |
 *     (H)     (I)  (J)     (K)        (L)     (M)  (N)     (O)
 *
 *
 *   Don't direct Postorder create binary-tree, but we can find the last
 *   node is root, and previous node is right-child for root, and pre-previous
 *   node is left-child for root..... So, we can create binary tree like this.
 */
static size_t post_order_idx = 0;
static element_type_t perfect_binarytree_data[] = {
    'A',                                    /* ROOT */
    'B', 'D', 'H', '#', '#', 'I', '#', '#',
    'E', 'J', '#', '#', 'K', '#', '#',      /* LEFT */
    'C', 'F', 'L', '#', '#', 'M', '#', '#',
    'G', 'N', '#', '#', 'O', '#', '#'};     /* RIGHT */
binary_tree *postorder_create_binaryTree(binary_tree *parent) {
  element_type_t ch = perfect_binarytree_data[post_order_idx++];
  if (ch == '#') {
    return NULL;
  } else {
    binary_node *node = (binary_node *)malloc(sizeof(struct binary_node));
    if (node == NULL)
      return NULL;

    memset(node, 0, sizeof(struct binary_node));

    node->left = postorder_create_binaryTree(node);
    node->right = postorder_create_binaryTree(node);

    node->data = ch;
    node->parent = parent;

    return node;
  }
}

void travel_tree_by_level_order(binary_tree *tree) {
  binary_node *root = tree;

  std::queue<binary_node *> queue;
  queue.push(root);

  while (!queue.empty()) {
    int size = queue.size();
    while (size > 0) {
      binary_node *cur = queue.front(); queue.pop();
      printf("%c ", cur->data); fflush(stdout); sleep(1);

      if (cur->left != nullptr) {
        queue.push(cur->left);
      }
      if (cur->right != nullptr) {
        queue.push(cur->right);
      }

      --size;
    }
    putchar('\n');
  }
}
