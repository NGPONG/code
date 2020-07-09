#pragma warning(disable:6031)
#pragma warning(disable:4996)			

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <Windows.h>

void fun_Test(int nums[5]) {

	
}

int main(void) {
	
	int a = 10;

	int b = 20;

	int *p[] = { &a,&b };

	int *p_Test = &p;

	printf("%d\n", **p + 1);

	system("pause");
	return EXIT_SUCCESS;
}
