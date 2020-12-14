#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

int binary_search(int *arrary, int key, int len) {
  int low = 0;
  int high = len - 1;

  int mid = 0;
  while (true) {
    mid = (low + high) / 2;

    if (arrary[mid] < key) {
      low = mid + 1;
    } else if (arrary[mid > key]) {
      high = mid - 1;
    } else if(arrary[mid] == key) {
      return mid;
    } else {
      return -1;
    }
  }
}

int main(void) {
  int arrary[] = { 0, 1, 16, 24, 35, 47, 59, 62, 73, 88, 99 };
  
  int idx = 0;
  if((idx = binary_search(arrary, 88, sizeof(arrary) / sizeof(int)) != -1)) {
    printf("dected [%d]\n", idx);
  } else {
    printf("none\n");
  }

  return EXIT_SUCCESS;
}
