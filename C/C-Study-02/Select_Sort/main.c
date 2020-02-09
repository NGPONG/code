#pragma warning(disable:6031)
#pragma warning(disable:4996)			

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <Windows.h>

void fun_01() {

	int arrary[7] = { 3,6,4,1,5,2,7 };

	for (size_t i = 0; i < sizeof(arrary) / sizeof(*arrary); i++) {

		int min = i;

		for (size_t j = i + 1; j < sizeof(arrary) / sizeof(*arrary); j++) {

			if (*(arrary + j) < *(arrary + min))
				min = j;
		}

		if (min != i) {

			*(arrary + i) = *(arrary + i) ^ *(arrary + min);
			*(arrary + min) = *(arrary + i) ^ *(arrary + min);
			*(arrary + i) = *(arrary + i) ^ *(arrary + min);
		}
	}
}

void fun_02() {

	char *arrary[5] = { "bbb","ddd","aaa","eee","ccc" };

	for (size_t i = 0; i < sizeof(arrary) / sizeof(*arrary); i++) {

		int min = i;

		for (size_t j = i + 1; j < sizeof(arrary) / sizeof(*arrary); j++) {

			if (strcmp(*(arrary + j), *(arrary + min)) == -1)
				min = j;
		}

		if (min != i) {
		
			char *temp = *(arrary + i);
			*(arrary + i) = *(arrary + min);
			*(arrary + min) = temp;
		}
	}
}

int main(void) {

	fun_02();

	system("pause");
	return EXIT_SUCCESS;
}
