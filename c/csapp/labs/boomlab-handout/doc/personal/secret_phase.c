#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct node {
  long data;
  struct node *left;
  struct node *right;
} t_node;

long fun7(t_node *rdi, long rsi) {
  if (rdi == NULL) {
    return -1;
  }

  long rdx = rdi->data;
  if (rdx > rsi) {
    return fun7(rdi->left, rsi) * 2;
  }
  if (rdx == rsi) {
    return 0;
  }

  long rax = fun7(rdi->right, rsi);
  return rax * 2 + 1;
}

void init(t_node *tree, long *data, int *idx) {
  tree->data = data[*idx];

  *idx = *idx + 1;
  if (data[*idx] != 0) {
    tree->left = malloc(sizeof(t_node));
    init(tree->left, data, idx);
  } else {
    tree->left = NULL;
  }

  *idx = *idx + 1;
  if (data[*idx] != 0) {
    tree->right = malloc(sizeof(t_node));
    init(tree->right, data, idx);
  } else {
    tree->right = NULL;
  }
}

int main(int argc, char *argv[]) {
  long arr[] = { 0x24, 0x8, 0x6,  0x1,  0, 0,    0x7,   0,    0, 0x16, 0x14,
                 0,    0,   0x23, 0,    0, 0x32, 0x2d,  0x28, 0, 0,    0x2d,
                 0,    0,   0x6b, 0x63, 0, 0,    0x3e9, 0,    0 };
  int idx = 0;

  t_node *tree = malloc(sizeof(t_node));
  init(tree, arr, &idx);

  for (int i = 0; i < 1000; ++i) {
    long rax = fun7(tree, i);
    if (rax == 2) {
      printf("hit: %d\n", i);
    }
  }

  return EXIT_SUCCESS;
}
