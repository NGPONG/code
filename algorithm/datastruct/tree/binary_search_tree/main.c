#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include <time.h>

typedef struct bi_node {
  int data;
  struct bi_node *left;
  struct bi_node *right;
} bi_node, bi_tree;

bi_tree *init() {
  /* root */
  bi_tree *tree = malloc(sizeof(bi_node));
  memset(tree, 0x0, sizeof(bi_node));
  tree->data = 62;

  tree->left = malloc(sizeof(bi_node));
  memset(tree->left, 0x0, sizeof(bi_node));
  tree->left->data = 58;
  tree->left->left = malloc(sizeof(bi_node));
  memset(tree->left->left, 0x0, sizeof(bi_node));
  tree->left->left->data = 47;
  tree->left->left->left = malloc(sizeof(bi_node));
  memset(tree->left->left->left, 0x0, sizeof(bi_node));
  tree->left->left->left->data = 35;
  tree->left->left->left->right = malloc(sizeof(bi_node));
  memset(tree->left->left->left->right, 0x0, sizeof(bi_node));
  tree->left->left->left->right->data = 37;
  tree->left->left->left->right->left = malloc(sizeof(bi_node));
  memset(tree->left->left->left->right->left, 0x0, sizeof(bi_node));
  tree->left->left->left->right->left->data = 22;
  tree->left->left->left->right->right = malloc(sizeof(bi_node));
  memset(tree->left->left->left->right->right, 0x0, sizeof(bi_node));
  tree->left->left->left->right->right->data = 53;
  tree->left->left->right = malloc(sizeof(bi_node));
  memset(tree->left->left->right, 0x0, sizeof(bi_node));
  tree->left->left->right->data = 51;

  tree->right = malloc(sizeof(bi_node));
  memset(tree->right, 0x0, sizeof(bi_node));
  tree->right->data = 88;
  tree->right->right = malloc(sizeof(bi_node));
  memset(tree->right->right, 0x0, sizeof(bi_node));
  tree->right->right->data = 99;
  tree->right->right->left = malloc(sizeof(bi_node));
  memset(tree->right->right->left, 0x0, sizeof(bi_node));
  tree->right->right->left->data = 93;
  tree->right->left = malloc(sizeof(bi_node));
  memset(tree->right->left, 0x0, sizeof(bi_node));
  tree->right->left->data = 73;

  return tree;
}

bi_node *search_BST(bi_tree *tree, int key) {
  if (tree == NULL) return tree;

  if(tree->data == key) {
    return tree;
  } else if(tree->data < key) { /* 右子树 */
    return search_BST(tree->right, key);
  } else if(tree->data > key) { /* 左子树 */
    return search_BST(tree->left, key);
  } else {
    return NULL;
  }
}

/* @brief 如果不存在相同的结点，则一路往下搜索，直至无法搜索，使上一个结点的左/右子树等于新插入的值 */
bool insert_BST(bi_tree *root, int key, bi_tree *prev) {
  if(!root) {
    if(!prev) { /* 函数初始调用的状态下就给定了一颗空树 */
      return false;
    } else {
      root = (bi_node *)malloc(sizeof(bi_node));
      memset(root, 0x0, sizeof(bi_node));
      root->data = key;

      if(prev->data < key) {
        prev->right = root;
      } else {
        prev->left = root;
      }

      return true;
    }
  }

  if(root->data == key) {        /* 防止相同结点的插入 */
    return false; 
  } else if (root->data < key) { /* 从右子树继续往下搜索合适的位置以插入key */
    return insert_BST(root->right, key, root);
  } else {                       /* 从左子树继续往下搜索合适的位置以插入key */
    return insert_BST(root->left, key, root);
  }
}

bool delete_BST(bi_node **cur_node, int key) {
  if((*cur_node)->data == key) {

    if((*cur_node)->left == NULL && (*cur_node)->right == NULL) { /* 叶结点 */
      free(*cur_node);
      *cur_node = NULL;
    } else if ((*cur_node)->left == NULL) {                       /* 仅有右子树的结点 */
      bi_node *tmp = (*cur_node)->right;
      free(*cur_node); /* 释放掉父节点的左/右子结点的内存 */
      *cur_node = tmp; /* 使父节点的左/右子节点内存区指向最开始结点 */
    } else if ((*cur_node)->right == NULL) {                      /* 仅有左子树的结点 */
      bi_node *tmp = (*cur_node)->left;
      free(*cur_node); /* 释放掉父节点的左/右子结点的内存 */
      *cur_node = tmp; /* 使父节点的左/右子节点内存区指向最开始结点 */
    } else {                                                      /* 拥有左右子树的结点 */
      /* 寻找要被删除结点 **cur_node 的直接前驱，即 **cur_node 左子树的最右边的尽头结点 */
      /* 反之，寻找直接后驱就是 **cur_node 右子树的最左边尽头的结点 */
      bi_node *par = *cur_node;
      bi_node *new_root = (*cur_node)->left;
      while (new_root->right) {
        par = new_root;
        new_root = new_root->right;
      }

      /**
       * 由于上一步找到了 **cur_node 的直接前驱 new_root，也就是说
       * new_root 是没有右孩子结点的，故可以直接把它的左孩子结点写到它
       * 原先的位置来
      */
      bi_node *child = new_root->left;
      par->right = child;

      /* 替换掉需要删除的结点 */
      new_root->left = (*cur_node)->left;
      new_root->right = (*cur_node)->right;

      free(*cur_node);

      *cur_node = new_root;
    }
    
    return true;

  } else if ((*cur_node)->data < key) { /* 从右子树继续往下搜索合适的位置以插入key */
    return delete_BST(&(*cur_node)->right, key);
  } else {                              /* 从左子树继续往下搜索合适的位置以插入key */
    return delete_BST(&(*cur_node)->left, key);
  }
}

int main(void) {
  bi_tree *tree = init();

  /* bi_node *node = NULL;                       */
  /* if((node = search_BST(tree, 42)) != NULL) { */
  /*   printf("Data detected %d\n", node->data); */
  /* } else {                                    */
  /*   printf("Search error\n");                 */
  /* }                                           */

  int val = 42;
  bool flg;
  if((flg = insert_BST(tree, val, NULL)) == false) {
    printf("[error] Repeact insert %d\n", val);
  } else {
    printf("[info] Success insert %d\n", val);
  }

  /* delete_BST(&tree, 73); */

  return EXIT_SUCCESS;
}
