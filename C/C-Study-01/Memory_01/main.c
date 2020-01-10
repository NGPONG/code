#pragma warning(disable:6031)
#pragma warning(disable:4996)			

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <Windows.h>

void enter(void) {

	putchar('\n');
	printf("-----------------------------------\n");
	putchar('\n');
}

void fun_Test(int n,int m) {

	printf("stack frame:n		= %p\n", &n);
	printf("stack frame:m		= %p\n", &m);
}

static int static_g_a = 10;
int g_a = 10;

static int static_g_b;
int g_b;

int main(void) {

	enter();

	fun_Test(100, 200);

	enter();

	int a = 10;
	int b;

	printf("stack frame:a		= %p\n", &a);
	printf("stack frame:b		= %p\n", &b);

	enter();

	static int static_a = 10;
	printf(".data:static_a		= %p\n", &static_a);
	printf(".data:static_g_a	= %p\n", &static_g_a);
	printf(".data:g_a		= %p\n", &g_a);

	enter();

	static int static_b;
	printf(".bss:static_b		= %p\n", &static_b);
	printf(".bss:static_g_b		= %p\n", &static_g_b);
	printf(".bss:g_b		= %p\n", &g_b);

	enter();

	const int a_const = 10;
	printf(".rodata:a_const		= %p\n", &a_const);

	enter();

	int *p = malloc(sizeof(int));
	printf("heap:p_heap		= %p\n", p);

	enter();

	system("pause");

	free(p);

	return EXIT_SUCCESS;
}
