#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct bi_node {
  int data;
  int bf;
  struct bi_node *left;
  struct bi_node *right;
} bi_node, bi_tree;

/** 
 * @brief LL(left-left)调整，右单旋转
 * @note 
 *  - LL调整: 新结点在某个最小不平衡树上的左子节点的左子树上进行插入的
 *  - 将根节点的左子结点变为根节点
 *  - 根节点变为变为新的根节点的右结点
 *  - 如果新根节点的左子结点存在右结点，则变为旧根节点的左子结点
*/
void right_rotate(bi_node **root) {
  bi_node *left = (*root)->left;
  if(left->right != NULL) (*root)->left = left->right;
  left->right = *root;
  *root = left;
}

/** 
 * @brief RR(right-right)调整，左单旋转
 * @note
 *  - RR调整: 新结点在某个最小不平衡树上的右子节点的右子树上进行插入的
 *  - 将根节点的右子结点变为根节点
 *  - 根节点变为变为新的根节点的左结点
 *  - 如果新根节点的右子结点存在左结点，则变为旧根节点的右子结点
*/
void left_rotate(bi_node **root) {
  bi_node *right = (*root)->right;
  if (right->left != NULL) (*root)->right = right->left;
  right->left = *root;
  *root = right;
}


int main(void) {
  bi_node *node = NULL;

  return EXIT_SUCCESS;
}
