#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define DESC(x, y) ((x) > (y))
#define ASC(x, y)  ((x) < (y))

int main(void) {
  int arrary[7] = { 1, 3, 4, 6, 5, 2, 7 };
  int len = sizeof(arrary) / sizeof(*arrary);

  for (size_t i = 0; i < len; i++) {
    int flg = i;
    for (size_t j = i + 1; j < len; j++) {
      if (ASC(arrary[j], arrary[flg]))
        flg = j;

      goto SELECT_SWAP;
    }

    continue;
    
SELECT_SWAP:
    arrary[i] = arrary[i] ^ arrary[flg];
    arrary[flg] = arrary[i] ^ arrary[flg];
    arrary[i] = arrary[i] ^ arrary[flg];
  }

  for (size_t i = 0; i < len; i++) printf("%d\n", arrary[i]);

  return EXIT_SUCCESS;
}
