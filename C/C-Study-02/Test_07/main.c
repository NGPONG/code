#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <Windows.h>

static int a;

static int a = 1024;

void fun_test() { printf("OK!\n"); }

int main(void) {

  printf("%d\n", a);

  system("pause");
  return EXIT_SUCCESS;
}
