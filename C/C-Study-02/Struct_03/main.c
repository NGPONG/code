#pragma warning(disable:6031)
#pragma warning(disable:4996)			

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <Windows.h>

#define MAX_LENGTH 10000

typedef struct person {

	char *name;
	int age;
} Person;

int main(void) {

	Person **pers = malloc(sizeof(Person *) * MAX_LENGTH);

	for (size_t i = 0; i < MAX_LENGTH; i++) {

		Person *per = malloc(sizeof(Person));
		if (per == NULL)
			continue;

		(*per).name = malloc(sizeof(char) * MAX_LENGTH);
		if ((*per).name == NULL)
			continue;

		sprintf((*per).name, "name_%d", i + 1);
		(*per).age = 100 + (i + 1);

		*(pers + i) = per;
	}

	for (size_t i = 0; i < MAX_LENGTH; i++) {

		printf("name = %s  age = %d\n", (**(pers + i)).name, (**(pers + i)).age);
	}


	for (size_t i = 0; i < MAX_LENGTH; i++) {

		free((**(pers + i)).name);
		free(*(pers + i));
	}

	free(pers);

	system("pause");
	return EXIT_SUCCESS;
}
