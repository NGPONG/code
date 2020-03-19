#pragma warning(disable:6031)
#pragma warning(disable:4996)			

#include <iostream>

using namespace std;

extern "C" void fun_test(char *);

int main(void) {

	fun_test((char *)"NGPONG");

	system("pause");
	return EXIT_SUCCESS;
}