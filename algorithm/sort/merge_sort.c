#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define PRINT(arr)                                       \
  for (int i = 0; i < sizeof(arr) / sizeof(*arr); ++i) { \
    printf("%d\n", arr[i]);                              \
  }

static int arrary[] = { 3, 44, 38, 5, 47, 15, 36, 26, 27, 2, 46, 4, 19, 50, 48 };
static int len = sizeof(arrary) / sizeof(*arrary);

void merge_sort(int L, int M, int R) {
  int LEFT_SIZE = M - L;
  int left[LEFT_SIZE];
  /* 1. Fill in left sub arrary */
  for (size_t i = L; i < M; ++i) {
    left[i - L] = arrary[i];
  }

  /* 1. Fill in right sub arrary */
  int RIGHT_SIZE = R - M + 1;
  int right[RIGHT_SIZE];
  for (size_t i = M; i <= R; ++i) {
    right[i - M] = arrary[i];
  }

  int i = 0, j = 0, k = L;
  while (i < LEFT_SIZE && j < RIGHT_SIZE) {
    if (left[i] < right[j]) {
      arrary[k] = left[i];
      ++i; ++k;
    } else {
      arrary[k] = right[j];
      ++j; ++k;
    }
  }

  while (i < LEFT_SIZE) {
    arrary[k] = left[i];
    ++i; ++k;
  }

  while (j < RIGHT_SIZE) {
    arrary[k] = right[j];
    ++j; ++k;
  }
}

void merge_split(int low, int high) {
  if (low == high) {
    return;
  } else {
    int mid = (low + high) / 2;

    /* split left sub arrary */
    merge_split(low, mid);
    /* split right sub arrary */
    merge_split(mid + 1, high);

    merge_sort(low, mid + 1, high);
  }
}

int main(int argc, char *argv[]) {
  merge_split(0, len - 1);

  PRINT(arrary);

  return EXIT_SUCCESS;
}
