#pragma warning(disable:6031)
#pragma warning(disable:4996)			

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <Windows.h>

union object {

	char var;
	short int_16;
	int int_32;
};

enum color {
	red,
	blue,
	green
};

int main(void) {
	
	FILE *p = NULL;
	p = fopen("‪D:/1.txt", "w+");

	perror("1");

	system("pause");
	return EXIT_SUCCESS;
}
