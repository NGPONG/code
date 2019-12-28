#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

int main(void) {

	printf("\t¹þ¹þ¹þ", time(NULL));

	//srand(time(NULL));

	int num_Rand;
	while (true)
	{
		num_Rand = rand();
	}

	getchar();
	return 0;
}