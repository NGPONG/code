#pragma warning(disable:6031)
#pragma warning(disable:4996)			

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <Windows.h>

struct Person {

	int Age;
	int Gender;
	char Name[24];
};

int main(void) {

	struct Person pers[2] = { {22,1,"NGPONG"},{99,0,"who?"} };

	struct Person per = { 22,1,"NGPONG" };

	system("pause");
	return EXIT_SUCCESS;
}
