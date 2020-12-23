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

void bucket_sort() {
  printf("start bucket sort\n");
}


void counting_sort() {
  printf("start counting sort\n");
}


void quick_sort(int left, int right) {
}


void heapify(int n, int idx) {
}
void built_heap() {
}
void heap_sort() {
  printf("start heap sort\n");
}


void merge_sort(int L, int M, int R) {
}
void merge_split(int low, int high) {
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
  /* bubble_sort(); */
  /* select_sort(); */
  /* insert_sort(); */
  /* shell_sort(); */
  /* merge_split(0, len - 1); */
  /* heap_sort(); */
  /* quick_sort(0, len - 1); */
  /* counting_sort(); */
  bucket_sort();
  
  PRINT(arrary);

  return EXIT_SUCCESS;
}
