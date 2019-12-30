#include "myInclude.h"

void main_Fun_Test() {

	printf("Hell! I'm main.c file!\n");
}

int main(void) {

	a_Fun_Test();
	b_Fun_Test();
	main_Fun_Test();

	system("pause");
	return EXIT_SUCCESS;
}