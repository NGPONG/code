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

static int arrary[] = { 3, 44, 38, 5, 47, 15, 36, 26, 27, 2, 46, 4, 19, 50, 48 };
static int len = sizeof(arrary) / sizeof(*arrary);

void heapify(int n, int idx) {
  int c_1 = 2 * idx + 1;
  int c_2 = 2 * idx + 2;

  int max = idx;
  if (c_1 < n && arrary[c_1] > arrary[max]) {
    max = c_1;
  }
  if (c_2 < n && arrary[c_2] > arrary[max]) {
    max = c_2;
  }

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
  built_heap();

  for (int i = len - 1; i >= 0; --i) {
    SWAP(arrary[0], arrary[i]);
    heapify(i, 0);
  }
}

int main(int argc, char *argv[]) {
  heap_sort();

  PRINT(arrary);
  
  return EXIT_SUCCESS;
}
