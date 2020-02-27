#pragma warning(disable:6031)
#pragma warning(disable:4996)			

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <Windows.h>

#include "arrary.h"

int arrary_compare_int(void *data_source, void *data_compare) {

	return *(int *)data_source == *(int *)data_compare;
}

int main(void) {

	struct dynamicArrary *arrary = InitDynamicArrary(2);

	for (size_t i = 0; i < 10; i++) {

		int *a = malloc(sizeof(int));
		if (a == NULL)
			break;
		*a = 10 + i;

		Add(arrary, a);
	}

	RemoveByPostion(arrary, 7);

	int a = 13;
	RemoveByValue(arrary, &a, arrary_compare_int);

	for (size_t i = 0; i < arrary->length; i++) {

		printf("address = %p, value = %d\n", *(arrary->ptr_arrary + i), *(int *)*(arrary->ptr_arrary + i));
	}

	system("pause");
	return EXIT_SUCCESS;
}
