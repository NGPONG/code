#pragma warning(disable:6031)
#pragma warning(disable:4996)			

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <Windows.h>

int a = 1000;

extern void fun(void) {

	printf("123");
}

int main(void) {


	int arrary[3] = { 1,2,3 };

	int (*p_arrary)[3] = arrary;

	printf("%d\n", *(*p_arrary));         // Print 1
	printf("%d\n", *((*p_arrary) + 1));	    // Print 2

	system("pause");
	return EXIT_SUCCESS;
}
