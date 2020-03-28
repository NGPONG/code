#ifndef __BINARY_TREE_H__
#define __BINARY_TREE_H__
#define _CRT_SECURE_NO_WARNINGS

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

typedef char ElementType_t;

typedef struct binary_node {

  ElementType_t data;
  struct binary_node *parent;
  struct binary_node *left;  /* Left sub tree */
  struct binary_node *right; /* Right sub tree */
  char tag;
} Binary_Tree;

int Preorder_Create_BinaryTree(Binary_Tree **tree, Binary_Tree *parent);
Binary_Tree *Postorder_Create_BinaryTree(Binary_Tree *parent);
int Preorder_Traverse_BinaryTree_WithoutRecursion(Binary_Tree *tree);
int Preorder_Traverse_BinaryTree(Binary_Tree *tree);
int Postorder_Traverse_BinaryTree(Binary_Tree *tree);
int Middorder_Traverse_BinaryTree(Binary_Tree *tree);
int Postorder_Free_BinaryTree(Binary_Tree **tree);
int BinaryTree_Deep(struct binary_node *node);

#endif // !__BINARY_TREE_H__
