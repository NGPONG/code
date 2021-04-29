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
}
void built_heap() {
}
void heap_sort() {
}


void merge_sort(int L, int M, int R) {
}
void merge_split(int low_idx, int high_idx) {
}


void shell_sort(void) {
  printf("start shell sort\n");
}


void insert_sort(void) {
  printf("start insert sort\n");
}


void select_sort(void) {
  printf("start select sort\n");
}


void bubble_sort(void) {
  printf("start bubble sort\n");
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
