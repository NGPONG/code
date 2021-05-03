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

void counting_sort(int max_val) {
  max_val += 1;

  int count_arrary[max_val];
  bzero(count_arrary, sizeof(int) * max_val);
  int sorted_arrary[len];
  bzero(sorted_arrary, sizeof(int) * len);

  for (int i = 0; i < len; ++i) count_arrary[arrary[i]] += 1;
  for (int i = 1; i < max_val; ++i) count_arrary[i] += count_arrary[i - 1];

  for (int i = 0; i < len; ++i) {
    count_arrary[arrary[i]] -= 1;
    sorted_arrary[count_arrary[arrary[i]]] = arrary[i];
  }

  memcpy(arrary, sorted_arrary, sizeof(int) * len);
}

int main(int argc, char *argv[]) {
  counting_sort(50);

  PRINT(arrary);
  
  return EXIT_SUCCESS;
}
