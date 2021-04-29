#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define SWAP(x, y) \
  if (x != y) {    \
    x = x ^ y;     \
    y = x ^ y;     \
    x = x ^ y;     \
  }

#define PRINT(arr)                               \
  printf("-------------------------------\n");   \
  for (int i = 0; i < len; ++i) {                \
    printf("%d\n", arr[i]);                      \
  }                                              \
  printf("-------------------------------\n\n"); \

#define RESET reset_arrary();

static int *arrary;
static int len;

void reset_arrary() {
  int tmp[] = { 3, 44, 38, 5, 47, 15, 36, 26, 27, 2, 46, 4, 19, 50, 48 };
  len = sizeof(tmp) / sizeof(*tmp);

  if (arrary == NULL) {
    arrary = malloc(sizeof(tmp));
  }

  for (int i = 0; i < len; ++i) {
    arrary[i] = tmp[i];
  }
}

void bucket_sort() {
  printf("start bucket sort\n");
}


void counting_sort() {
  printf("start counting sort\n");
}


void quick_sort(int left, int right) {
}


void heapify(int n, int cur_node_idx) {
  int c_1_idx = cur_node_idx * 2 + 1;
  int c_2_idx = cur_node_idx * 2 + 2;
  
  int max = cur_node_idx;
  if (c_1_idx < n )
}
void built_heap() {
}
void heap_sort() {
}


void merge_sort(int L, int M, int R) {
  int L_SIZE = M - L;
  int left[L_SIZE];
  for (int i = L; i < M; ++i) {
    left[i - L] = arrary[i];
  }

  int R_SIZE = R - M + 1;
  int right[R_SIZE];
  for (int i = M; i <= R; ++i) {
    right[i - M] = arrary[i];
  }

  int i = 0, j = 0, k = L;
  while (i < L_SIZE && j < R_SIZE) {
    if (left[i] < right[j]) {
      arrary[k++] = left[i++];
    } else {
      arrary[k++] = right[j++];
    }
  }

  while (i < L_SIZE) {
    arrary[k++] = left[i++];
  }

  while (j < R_SIZE) {
    arrary[k++] = right[j++];
  }
}
void merge_split(int low_idx, int high_idx) {
  if (low_idx == high_idx) {
    return;
  } else {
    int mid = (low_idx + high_idx) / 2;
    merge_split(low_idx, mid);
    merge_split(mid + 1, high_idx);
    merge_sort(low_idx, mid + 1, high_idx);
  }
}


void shell_sort(void) {
  printf("start shell sort\n");

  for (int inc = len / 2; inc > 0; inc /= 2) {

    for (int i = inc; i < len; ++i) {
      int flg = arrary[i];

      int j = i;
      for (; j >= inc && arrary[j - inc] > flg; j -= inc) {
        arrary[j] = arrary[j - inc];
      }
      arrary[j] = flg;
    }

  }
}


void insert_sort(void) {
  printf("start insert sort\n");

  for (int i = 1; i < len; ++i) {
    int flg = arrary[i];

    int j = i - 1;
    for (; j >= 0 && arrary[j] > flg; --j) {
      arrary[j + 1] = arrary[j];
    }
    arrary[j + 1] = flg;
  }
}


void select_sort(void) {
  printf("start select sort\n");

  for (int i = 0; i < len; ++i) {
    int flg = i;
    for (int j = i + 1; j < len; ++j) {
      if (arrary[j] < arrary[flg]) {
        flg = j;
      }
    }

    if (flg != i) {
      SWAP(arrary[i], arrary[flg]);
    }
  }
}


void bubble_sort(void) {
  printf("start bubble sort\n");

  for (int i = 0; i < len; ++i) {
    for (int j = 0; j < len - 1 - i; ++j) {
      if (arrary[j] > arrary[j + 1]) {
        SWAP(arrary[j], arrary[j + 1]);
      }
    }
  }
}

int main(int argc, char *argv[]) {
  RESET;

  bubble_sort();
  PRINT(arrary); RESET;

  select_sort();
  PRINT(arrary); RESET;

  insert_sort();
  PRINT(arrary); RESET;

  shell_sort();
  PRINT(arrary); RESET;

  printf("start merge sort\n");
  merge_split(0, len - 1);
  PRINT(arrary); RESET;

  /* heap_sort(); */
  /* PRINT(arrary); RESET; */

  /* quick_sort(0, len - 1); */
  /* PRINT(arrary); RESET; */

  /* counting_sort(); */
  /* PRINT(arrary); RESET; */

  /* bucket_sort(); */
  /* PRINT(arrary); RESET; */

  return EXIT_SUCCESS;
}
