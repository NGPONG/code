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
	char *Name;
};

void fun_Test(struct Person per) {

	int i = 0;
}

void fun_Test2(int *p) {

	*p = 10;
}

int main(void) {

	int i = 2;

	char *str = malloc(sizeof(char) * 10);

	strcpy(str, "World!");

	system("pause");
	return EXIT_SUCCESS;
}