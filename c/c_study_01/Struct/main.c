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

	struct Person per = { 15,1,"NGPONG" };

	struct Person *p_per = &per;

	struct Person **p_p_per = &p_per;

	printf("Age: %d\n", p_per->Age);
	printf("Gender: %d\n", p_per->Gender);
	printf("Name: %s\n", p_per->Name);

	
	system("pause");
	return EXIT_SUCCESS;
}

