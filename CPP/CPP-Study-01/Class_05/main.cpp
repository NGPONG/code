#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

#include <Windows.h>

using namespace std;

class Test {

public:
	Test() {}

	Test(int id) {
	
		this->id = id;
	}

	int id;
};

int main(void) {

	int a = 10;
	int *p = (int *)malloc(sizeof(int));
	*p = a;
	delete p;

	system("pause");
	return EXIT_SUCCESS;
}
