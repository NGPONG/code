#include <stdio.h>
#include <stdlib.h>

#define DESC(x, y) ((x) < (y))
#define ASC(x, y)  ((x) > (y))

int main(void) {
  int arrary[] = { 3, 44, 38, 5, 47, 15, 36, 26, 27, 2, 46, 4, 19, 50, 48 };
  int len = sizeof(arrary) / sizeof(*arrary);

  for (int i = 1; i < len; i++) {
    if (ASC(arrary[i - 1], arrary[i])) {
      int tmp = arrary[i];

      int j = i - 1;
      for (; j >= 0 && ASC(arrary[j], tmp); j--) {
        arrary[j + 1] = arrary[j];
      }
      arrary[j + 1] = tmp;
    } else {
      continue;
    }
  }

  for (size_t i = 0; i < len; i++) printf("%d\n", arrary[i]);

  return EXIT_SUCCESS;
}
