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

void quick_sort(int left, int right) {
  if (left > right) {
    return;
  }

  int i = left;
  int j = right;
  int key = arrary[left];

  while (i != j) {
    while (i < j && arrary[j] >= key) 
      --j;

    while (i < j && arrary[i] <= key) 
      ++i;

    if (i < j) {
      SWAP(arrary[i], arrary[j]);
    }
  }
  int mid = i;
  arrary[left] = arrary[mid];
  arrary[mid] = key;

  quick_sort(left, mid - 1);
  quick_sort(mid + 1, right);
}

int main(int argc, char *argv[]) {
  quick_sort(0, len - 1);

  PRINT(arrary);
  
  return EXIT_SUCCESS;
}
