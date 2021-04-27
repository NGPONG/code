#include <stdio.h>
#include <stdlib.h>

#define DESC(x, y) ((x) < (y))
#define ASC(x, y)  ((x) > (y))

int main(void) {
  int arrary[] = { 8, 1, 6, 3, 9, 4, 7, 2, 5 };
  int len = sizeof(arrary) / sizeof(arrary[0]);

  for (size_t i = 0; i < len; i++)
    for (size_t j = 0; j < len - 1 - i; j++) {
      /**
       * 8,1,6,3,9,4,7,2,5  ()
       * 1,6,3,9,4,7,2,5    (8)
       * 1,6,3,4,7,2,5      (8,9)
       * 1,6,3,4,2,5		    (7,8,9)
       * 1,3,4,2,5		      (6,7,8,9)
       * 1,3,4,2		        (5,6,7,8,9)
       * 1,3,2		          (4,5,6,7,8,9)
       * 1,2		            (3,4,5,6,7,8,9)
       * 1		              (2,3,4,5,6,7,8,9)
       *                    (1,2,3,4,5,6,7,8,9)
      */
      if (DESC(arrary[j], arrary[j + 1])) {
        int num_Temp = arrary[j + 1];
        arrary[j + 1] = arrary[j];
        arrary[j] = num_Temp;
      }
    }

  for (size_t i = 0; i < len; i++) printf("%d\n", arrary[i]);

  return 0;
}
