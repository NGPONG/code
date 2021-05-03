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

  int max_val = arrary[0];
  for (int i = 1; i < len; ++i) {
    if (arrary[i] > max_val) 
      max_val = arrary[i];
  }
  max_val += 1;
  
  int counted_arr[max_val];
  bzero(counted_arr, sizeof(int) * max_val);

  for (int i = 0; i < len; ++i) {
    counted_arr[arrary[i]] += 1;
  }

  int idx = 0;
  for (int i = 0; i < max_val; ++i) {
    int count = counted_arr[i];
    for (int j = 0; j < count; ++j) {
      arrary[idx++] = i;
    }
  }
}


void counting_sort() {
  printf("start counting sort\n");

  int max_val = arrary[0];
  for (int i = 1; i < len; ++i) {
    if (arrary[i] > max_val) 
      max_val = arrary[i];
  }
  max_val += 1;
  
  int counted_arr[max_val];
  bzero(counted_arr, sizeof(int) * max_val);
  int sorted_arr[len];
  bzero(sorted_arr, sizeof(int) * len);

  for (int i = 0; i < len; ++i) counted_arr[arrary[i]] += 1;
  for (int i = 1; i < max_val; ++i) counted_arr[i] += counted_arr[i - 1];

  for (int i = 0; i < len; ++i) {
    counted_arr[arrary[i]] -= 1;
    sorted_arr[counted_arr[arrary[i]]] = arrary[i];
  }
  memcpy(arrary, sorted_arr, sizeof(int) * len);
}


void quick_sort(int left, int right) {
  if (left > right) {
    return;
  }

  int i = left, j = right, pivot = arrary[left];
  while (i != j) {
    while (i < j && arrary[j] >= pivot) {
      --j;
    }
    while (i < j && arrary[i] <= pivot) {
      ++i;
    }
    if (i < j) {
      SWAP(arrary[i], arrary[j]);
    }
  }
  int mid = i;
  arrary[left] = arrary[mid];
  arrary[mid] = pivot;

  quick_sort(left, mid - 1);
  quick_sort(mid + 1, right);
}


void heapify(int last_idx, int cur_node_idx) {
  int max = cur_node_idx;

  int c_1 = cur_node_idx * 2 + 1;
  if (c_1 <= last_idx && arrary[c_1] > arrary[max]) {
    max = c_1;
  }

  int c_2 = cur_node_idx * 2 + 2;
  if (c_2 <= last_idx && arrary[c_2] > arrary[max]) {
    max = c_2;
  }

  if (max != cur_node_idx) {
    SWAP(arrary[cur_node_idx], arrary[max]);
    heapify(last_idx, max);
  }
}
void built_heap() {
  int last_idx = len - 1;
  int parent = (last_idx - 1) / 2;
  for (; parent >= 0; --parent) {
    heapify(last_idx, parent);
  }
}
void heap_sort() {
  printf("start heap sort\n");

  built_heap();
  for (int i = len - 1; i > 0; --i) {
    SWAP(arrary[0], arrary[i]);
    heapify(i - 1, 0);
  }
}


void merge_sort(int L, int M, int R) {
  int left_size = M - L;
  int left[left_size];
  for (int i = L; i < M; ++i) {
    left[i - L] = arrary[i];
  }

  int right_size = R - M + 1;
  int right[right_size];
  for (int i = M; i <= R; ++i) {
    right[i - M] = arrary[i];
  }

  int i = 0, j = 0, k = L;
  while (i < left_size && j < right_size) {
    if (left[i] < right[j]) {
      arrary[k++] = left[i++];
    } else {
      arrary[k++] = right[j++];
    }
  }

  while (i < left_size) {
    arrary[k++] = left[i++];
  }
  while (j < right_size) {
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
      int pivot = arrary[i];

      int j = i;
      for (; j >= inc && arrary[j - inc] > pivot; j -= inc) {
        arrary[j] = arrary[j - inc];
      }
      arrary[j] = pivot;
    }

  }
}


void insert_sort(void) {
  printf("start insert sort\n");

  for (int i = 1; i < len; ++i) {
    int pivot = arrary[i];

    int j = i - 1;
    for (; j >= 0 && arrary[j] > pivot; --j) {
      arrary[j + 1] = arrary[j];
    }
    arrary[j + 1] = pivot;
  }
}


void select_sort(void) {
  printf("start select sort\n");
}


void bubble_sort(void) {
  printf("start bubble sort\n");
}

int main(int argc, char *argv[]) {
  RESET;

  /* bubble_sort();        */
  /* PRINT(arrary); RESET; */

  /* select_sort();        */
  /* PRINT(arrary); RESET; */

  insert_sort();
  PRINT(arrary); RESET;

  shell_sort();
  PRINT(arrary); RESET;

  printf("start merge sort\n");
  merge_split(0, len - 1);
  PRINT(arrary); RESET;

  heap_sort();
  PRINT(arrary); RESET;

  printf("start quick sort\n");
  quick_sort(0, len - 1);
  PRINT(arrary); RESET;

  counting_sort();
  PRINT(arrary); RESET;

  bucket_sort();
  PRINT(arrary); RESET;

  return EXIT_SUCCESS;
}
