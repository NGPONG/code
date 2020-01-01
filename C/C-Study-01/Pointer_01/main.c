#pragma warning(disable : 6031)
#pragma warning(disable : 4996)

#include <Windows.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main(void) {

	int a = 65;

	int *p = &a;

	void *p_Void = (void *)p;


	printf("%p\n", &a);
	printf("%p\n", p);
	printf("%p\n", p_Void);
	printf("%p\n", &p);
	printf("%p\n", &p_Void);


	system("pause");
	return EXIT_SUCCESS;
}
