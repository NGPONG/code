#pragma warning(disable:6031)
#pragma warning(disable:4996)			

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <Windows.h>

int main(void) {

	int a = 10;

	int *p_a = &a;

	printf("value: %p\n", &a);
	printf("value: %p\n", &p_a);
	printf("value: %p\n", &*p_a);

	system("pause");
	return EXIT_SUCCESS;
}
