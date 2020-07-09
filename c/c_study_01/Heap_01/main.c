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
	
	int arrary[3][2] = { {1,3},{5,7},{9,11} };

	int (*p)[2] = arrary;
	
	//for (size_t i = 0; i < 3; i++) {

	//	(*p)[i] = malloc(sizeof(int) * 4);
	//}

	int a = 10;
	int *ptr = &a;
	int **ptr_a = &ptr;

	system("pause");
	return EXIT_SUCCESS;
}
