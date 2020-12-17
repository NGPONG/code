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
  int max_val = 50;
  max_val += 1;

  int *counted_arr = malloc(sizeof(int) * max_val);
  bzero(counted_arr, sizeof(int) * max_val);

  for (int i = 0; i < len; ++i) {
    counted_arr[arrary[i]] += 1;
  }

  int idx = 0;
  for (int i = 0; i < max_val; ++i) {
    for (int j = 0; j < counted_arr[i]; ++j) {
      arrary[idx] = i;
      ++idx;
    }
  }

  free(counted_arr);

  PRINT(arrary);
  
  return EXIT_SUCCESS;
}
