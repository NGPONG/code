#include <stdio.h>
#include <Windows.h>

int main(void) {

	int arrary[5];

	printf("%d\n", arrary[0]);

	printf("%p\n", &arrary);

	arrary[0] = 1;
	printf("%p\n", &arrary);
	printf("%p\n", &arrary[0]);

	arrary[1] = 2;
	arrary[2] = 3;
	arrary[3] = 4;
	arrary[4] = 5;

	printf("%x\n", &arrary[1]);
	printf("%x\n", &arrary[2]);
	printf("%x\n", &arrary[3]);
	printf("%x\n", &arrary[4]);

	return 0;
}