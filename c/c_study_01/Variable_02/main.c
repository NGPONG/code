#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <Windows.h>

int fun_Test() {

	static int a;
	a++;
	printf("%d\n", a);

	return 0;
}

int main(void) {


	for (size_t i = 0; i < 5; i++) {

		fun_Test();
	}

	system("pause");	
	return EXIT_SUCCESS;
}