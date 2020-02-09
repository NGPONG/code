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

	char *name;
	int age;
};

void fun_01(void) {

	struct Person tom;
	tom.name = malloc(sizeof(char) * 128);
	strcpy(tom.name, "Tom");
	tom.age = 18;

	struct Person jerry;
	jerry.name = malloc(sizeof(char) * 256);
	strcpy(jerry.name, "Jerry");
	jerry.age = 30;

	/*tom = jerry;*/
	realloc(tom.name, strlen(jerry.name) + 1);
	strcpy(tom.name, jerry.name);

	tom.age = jerry.age;

	printf("jerry name:%s\n", jerry.name);
	printf("jerry age:%d\n", jerry.age);

	printf("tom name:%s\n", tom.name);
	printf("tom age:%d\n", tom.age);

	free(tom.name);
	free(jerry.name);
}

int main(void) {

	fun_01();

	system("pause");
	return EXIT_SUCCESS;
}
