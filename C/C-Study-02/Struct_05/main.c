#pragma warning(disable:6031)
#pragma warning(disable:4996)			

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <Windows.h>

struct Person2 {

	char ch;				// 0 ~ 3
	int a;					// 4 ~ 7 
};

struct Person {

	char ch;				// 0 ~ 3
	int a;					// 4 ~ 7 
	struct Person2 person2;
};

int main(void) {

	struct Person per = { 'a',128,'b',256 };

	printf("%d\n", *(int *)((char *)&per + (size_t)&(((struct Person *)0)->person2) + (size_t)&(((struct Person2 *)0)->a)));

	system("pause");
	return EXIT_SUCCESS;
}
