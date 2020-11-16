#ifndef __BALANCE_BINARY_TREE_H__
#define __BALANCE_BINARY_TREE_H__

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define L_H +1 /* 左高 */
#define E_H +0 /* 等高 */
#define R_H -1 /* 右高 */

typedef struct bi_node {
  int data;
  int bf;
  struct bi_node *left;
  struct bi_node *right;
} bi_node, bi_tree;

void right_rotate(bi_node **root);
void left_rotate(bi_node **root);
void left_balance(bi_tree **root);
void right_balance(bi_tree **root);
bool insert_AVL(bi_tree **T, int e, bool *taller);

#endif /* end of include guard: __BALANCE_BINARY_TREE_H__ */
