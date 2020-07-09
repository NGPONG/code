#pragma warning(disable:6031)
#pragma warning(disable:4996)			

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <Windows.h>

int main_memset(void) {

	char *p = malloc(sizeof(char) * 10);

	if(p!= NULL)
		memset(p, 65, sizeof(char) * 10);

	int num[3] = { 0 };

	memset(num, 0, sizeof(num));

	system("pause");
	return EXIT_SUCCESS;
}

int main_memcpy(void) {
		
	char str_Cpy[124] = { 0 };
	char *str_Source = "Hello,World!";

	memcpy(str_Cpy, str_Source, strlen(str_Source) + 1);

	system("pause");
	return EXIT_SUCCESS;
}

int fun_Test(int **arg) {

	*arg = malloc(16);
	return;
}


int main(void) {

	int a = 10;
	int *p = &a;
	fun_Test(&p);

	p[0] = 0;
	p[1] = 1;
	p[2] = 2;
	p[3] = 3;

	free(p);

	system("pause");
	return EXIT_SUCCESS;
}

