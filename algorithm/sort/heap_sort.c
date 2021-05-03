#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define SWAP(x, y) \
  if (x != y) { \
    x = x ^ y; \
    y = x ^ y; \
    x = x ^ y; \
  }

#define PRINT(arr)                                       \
  for (int i = 0; i < sizeof(arr) / sizeof(*arr); ++i) { \
    printf("%d\n", arr[i]);                              \
  }

static int arrary[] = { 3, 44, 38, 5, 47, 15, 36, 26, 27, 2, 46, 4, 19, 48, 50 };
static int len = sizeof(arrary) / sizeof(*arrary);

void heapify(int n, int idx) {
  int c_1 = idx * 2 + 1; /* Complute the left child node idx from current node. */
  int c_2 = idx * 2 + 2; /* Complute the right child node idx from current node. */

  int max = idx;
  if (c_1 <= n && arrary[c_1] > arrary[max]) {
    max = c_1;
  }
  if (c_2 <= n && arrary[c_2] > arrary[max]) {
    max = c_2;
  }

  /**
   * This means that some childs node is bigger than the
   * current one, so we need to replace them.
  */
  if (max != idx) {
    SWAP(arrary[idx], arrary[max]);
    heapify(n, max);
  }
}

void built_heap() {
  int last_idx = len - 1;
  int parent = (last_idx - 1) / 2;

  for (int i = parent; i >= 0; --i) {
    heapify(last_idx, i);
  }
}

void heap_sort() {
  /* built max-heap */
  built_heap();
  
  /* When the loop reaches the root element, the only eleme
   * nt left to heapify proves to be the root element, so w
   * e can just skip it, so the conditional expression her
   * e is i >= 1 */
  for (int i = len - 1; i >= 1; --i) {
    SWAP(arrary[0], arrary[i]);
    heapify(i - 1, 0); /* Previous code has already moved the maximum elemen
                        * t to i, so we should not take that position into a-
                        * ccount in this heapify, we need i - 1 here. */
  }
}

int main(int argc, char *argv[]) {
  heap_sort();

  PRINT(arrary);
  
  return EXIT_SUCCESS;
}
