#pragma warning(disable:6031)
#pragma warning(disable:4996)			

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stddef.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <Windows.h>

struct Person {

	char name[64];
	int age;
	int id;
	double score;
};

int main(void) {

	int nums[3] = { 1,2,3, };
	int *p;


	const struct Person per = { "Hello,World!",22,1,99 };

	int i = (size_t)(&(((struct Person *)0)->score));
	printf("%x\n", &(((struct Person *)0)->name));
	printf("%x\n", &(((struct Person *)0)->age));
	printf("%x\n", &(((struct Person *)0)->id));

	printf("%x\n", &(((struct Person *)0)->score));

	char *ptr = &per;
	*((double *)(ptr + offsetof(struct Person, age))) = 20;

	system("pause");
	return EXIT_SUCCESS;
}
