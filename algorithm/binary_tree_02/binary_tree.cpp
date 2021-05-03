#include "binary_tree.h"
#include "queue.h"

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
    binary_tree *tree = (binary_tree *)malloc(sizeof(struct binary_node));
    if (tree == 0x0)  return NULL;

    memset(tree, 0, sizeof(struct binary_node));

    tree->left = postorder_create_binaryTree(tree);
    tree->right = postorder_create_binaryTree(tree);

    tree->data = ch;
    tree->parent = parent;

    return tree;
  }
}

void travel_tree_by_level_order(binary_tree *root) {
  queue *q = new_queue();
}
