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
  for (int inc = len / 2; inc > 0; inc /= 2) {
    for (size_t i = inc; i < len; ++i) {
      int key = arrary[i];

      int j = i;
      for (; j >= inc && key < arrary[j - inc]; j -= inc) {
        arrary[j] = arrary[j - inc];
      }
      arrary[j] = key;
    }
  }

  PRINT(arrary);

  return EXIT_SUCCESS;
}
