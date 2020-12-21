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

void merge_sort(int L, int M, int R) {
  int l_size = M - L;
  int r_size = R - M + 1;

  int left[l_size];
  int right[r_size];

  for (int i = L; i < M; ++i) left[i - L] = arrary[i];
  for (int i = M; i <= R; ++i) right[i - M] = arrary[i];

  int i = 0, j = 0, k = L;
  while (i < l_size || j < r_size) {
    if (i < l_size && left[i] < right[j]) {
      arrary[k] = left[i];
      ++k; ++i;
    } else if (j < r_size && right[j] < left[i]) {
      arrary[k] = right[j];
      ++k; ++j;
    }
  }

  /* while (i < l_size) {    */
  /*   arrary[k] = left[i];  */
  /*   ++k; ++i;             */
  /* }                       */
  /* while (j < r_size) {    */
  /*   arrary[k] = right[j]; */
  /*   ++k; ++j;             */
  /* }                       */
}
void merge_split(int low, int high) {
  if (low == high) {
    return;
  } else {
    int mid = (low + high) / 2;
    merge_split(low, mid);
    merge_split(mid + 1, high);
    merge_sort(low, mid + 1, high);
  }
}

int main(int argc, char *argv[]) {
  merge_split(0, len - 1);
  
  PRINT(arrary);

  return EXIT_SUCCESS;
}
