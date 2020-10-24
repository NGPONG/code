#pragma warning(disable:6031)
#pragma warning(disable:4996)			

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <Windows.h>

int fibonacci(int postion) {
	if (postion == 1 || postion == 2) {
		return 1;
	}

	return fibonacci(postion - 1) + fibonacci(postion - 2);
}

int main(void) {
	int i = fibonacci(10);

	system("pause");
	return EXIT_SUCCESS;
}
