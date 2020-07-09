#pragma warning(disable:6031)
#pragma warning(disable:4996)			

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <Windows.h>

char str5[] = "Hello";

extern int aa = 5;

void test_fun1(char *str) {

	int a = 10;
}

void test_fun2(char str[]) {

	int a = 10;
}

void test_fun3(char *str) {

	int a = 10;
}

void fun_test(char **p_str) {

	*p_str = malloc(100);
	strcpy(*p_str, "hello,world");
}

int main(void) {
	extern int cc = 5;
	char *str = NULL;
	fun_test(&str);

	printf("%s\n", str);


	system("pause");
	return EXIT_SUCCESS;
}
