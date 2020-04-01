#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <Windows.h>

struct Student {
  int age;
};

int main(void) {

  int nums[10] = { 0 };
  for (int i = 0; i < 10; i++) {
    *(nums + i) = i + 1;
  }

  for (int i = 0; i < 10; i++) {
    printf("%d\n", nums[i]);
  }

  system("pause");
  return EXIT_SUCCESS;
}