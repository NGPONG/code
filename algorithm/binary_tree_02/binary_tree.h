#ifndef __BINARY_TREE_H__
#define __BINARY_TREE_H__
#define _CRT_SECURE_NO_WARNINGS

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

typedef char element_type_t;

typedef struct binary_node {
  element_type_t data;
  struct binary_node *parent;
  struct binary_node *left;  /* Left sub tree */
  struct binary_node *right; /* Right sub tree */
  char tag;
} binary_tree;

binary_tree *postorder_create_binaryTree(binary_tree *parent);

#endif // !__BINARY_TREE_H__
