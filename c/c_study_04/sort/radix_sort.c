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

int main(int argc, char *argv[]) {
  int max_val = arrary[0];
  for (int i = 1; i < len; ++i) {
    if (arrary[i] > max_val) {
      max_val = arrary[i];
    }
  }

  int bucket[10] = { 0 };
  int *sorted_arr = malloc(sizeof(int) * len);
  bzero(sorted_arr, sizeof(int) * len);
  int base = 1;
  while (max_val / base > 0) {
    for (int i = 0; i < len; ++i) {
      bucket[arrary[i] / base % 10] += 1;
    }
    for (int i = 1; i < 10; ++i) {
      bucket[i] += bucket[i - 1];
    }
    for (int i = 0; i < len; ++i) {
      bucket[arrary[i] / base % 10]--;
      sorted_arr[bucket[arrary[i] / base % 10]] = arrary[i];
    }

    memcpy(arrary, sorted_arr, sizeof(int) * len);
    bzero(sorted_arr, sizeof(int) * len);

    base *= 10;
  }
  printf("1\n");
  free(sorted_arr);
  printf("2\n");

  PRINT(arrary);

  return EXIT_SUCCESS;
}
