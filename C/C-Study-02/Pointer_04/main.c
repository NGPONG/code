#pragma warning(disable:6031)
#pragma warning(disable:4996)			

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <Windows.h>

int fun_test1(void) {

	printf("Hello,World1!\n");
}

int fun_test2(void) {

	printf("Hello,World2!\n");
}

int fun_test3(void) {

	printf("Hello,World3!\n");
}

int main(void) {

	int (*invokers[3])(void);
	*(invokers) = fun_test1;
	invokers[1] = fun_test2;
	invokers[2] = fun_test3;

	for (size_t i = 0; i < sizeof(invokers) / sizeof(int (*)()); i++) {

		invokers[i]();
	}

	system("pause");
	return EXIT_SUCCESS;
}
