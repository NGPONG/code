#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <Windows.h>

typedef int Element_type;

#define DESC(x, y) ((x) < (y))
#define ASC(x, y)  ((x) > (y))

int main(void) {
  Element_type arrary[] = { 7, 2, 9, 4, 1, 3, 5, 8, 6 };
  Element_type buff;

  for (int i = 1; i < sizeof(arrary) / sizeof(Element_type); i++) {
    if (ASC(arrary[i - 1], arrary[i])) {
      buff = arrary[i];

      int j = i - 1;
      for (; j >= 0 && ASC(arrary[j], buff); j--) {
        arrary[j + 1] = arrary[j];
      }
      arrary[j + 1] = buff;
    } else {
      continue;
    }
  }

  for (size_t i = 0; i < sizeof(arrary) / sizeof(Element_type); i++) {
    printf("%d\n", arrary[i]);
  }

  system("pause");
  return EXIT_SUCCESS;
}
