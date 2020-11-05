#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <Windows.h>

int fibonacci(unsigned int n) {
	if(n < 2) return n == 0 ? 0 : 1;

  return fibonacci(n - 1) + fibonacci(n - 2);
}

int main(void) {
	/* 打印前斐波那契数列中的前 40 个数 */
	for (size_t i = 0; i < 40; ++i) {
    printf("%d(%d)\n", fibonacci(i), i);
  }

	system("pause");
	return EXIT_SUCCESS;
}
