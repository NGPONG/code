#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "balance_binary_tree.h"

int main(void) {
  int a[10] = { 3, 2, 1, 4, 5, 6, 7, 10, 9, 8 };
  bi_tree *tree = NULL;
  bool taller;
  for (size_t i = 0; i < sizeof(a) / sizeof(int); ++i) {
    insert_AVL(&tree, a[i], &taller);
  }

  return EXIT_SUCCESS;
}
