#pragma warning(disable:6031)
#pragma warning(disable:4996)			

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <Windows.h>

int *fun_Test(int a) {

	a = 20;

	int b = 30;

	return &a;
}

void fun_Test2() {

	int a = 20;

	int b = 30;
}

int main(void) {

	int a = 10;

	int *p = fun_Test(a);

	for (size_t i = 0; i < 100000; i++) {

		fun_Test2();
	}

	system("pause");
	return EXIT_SUCCESS;
}
