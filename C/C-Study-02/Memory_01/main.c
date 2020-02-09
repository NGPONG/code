#pragma warning(disable:6031)
#pragma warning(disable:4996)			

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <Windows.h>

int main(void) {

	int *p = malloc(sizeof(int) * 3);

	for (size_t i = 0; i < 3; i++) {

		p[i] = i + 1;
	}

	printf("%x\n", p);

	p = realloc(p, sizeof(int) * 10);

	for (size_t i = 0; i < 10; i++) {

		p[i] = i + 1;
	}

	for (size_t i = 0; i < 11; i++) {

		printf("%x = %d\n", &p[i], p[i]);
	}

	system("pause");
	return EXIT_SUCCESS;
}
