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

void func_01(void) {

	struct Person *per = malloc(sizeof(struct Person));
	if (per == NULL) {

		perror("malloc error");
		return EXIT_FAILURE;
	}

	per->name = "Hello";
	per->age = 22;

	free(per);
}

void func_02(void) {

	struct Person pers[2] = {

		{"NGPONG",22},
		{"Hello,World!",10}
	};

	struct Person (*per_ptr)[2] = &pers;

	printf("name = %s\n", (**per_ptr).name);
	printf("age = %d\n", (**per_ptr).age);
	printf("name = %s\n", (*(*per_ptr + 1)).name);
	printf("age = %d\n", (*(*per_ptr + 1)).age);
}

void func_03(void) {

	struct Person *pers[2];
	
	struct Person *per1 = malloc(sizeof(struct Person));
	(*per1).name = "heap_NGPONG!!!";
	(*per1).age = 22;

	struct Person *per2 = malloc(sizeof(struct Person));
	(*per2).name = "heap_Hello,World!";
	(*per2).age = 10;

	*pers = per1;
	*(pers + 1) = per2;

	printf("name = %s\n", (**pers).name);
	printf("age = %d\n", (**pers).age);
	printf("name = %s\n", (**(pers + 1)).name);
	printf("age = %d\n", (**(pers + 1)).age);

	free(per1);
	free(per2);
}

void func_04(void) {

	struct Person (*pers_ptr)[2];

	struct Person *pers = malloc(sizeof(struct Person [2]));
	(*pers).name = "Hello,World!";
	(*pers).age = 99;

	(*(pers + 1)).name = "NGPONG!!";
	(*(pers + 1)).age = 22;

	pers_ptr = pers;

	printf("name = %s\n", (**pers_ptr).name);
	printf("age = %d\n", (**pers_ptr).age);
	printf("name = %s\n", (*(*(pers_ptr)+1)).name);
	printf("age = %d\n", (*(*(pers_ptr)+ 1)).age);

	free(pers);
}

int main(void) {


	func_04();

	system("pause");
	return EXIT_SUCCESS;
}
