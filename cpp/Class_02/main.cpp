#include <iostream>

using namespace std;

class TEST_01 {

public:
	char ch;				// 0 ~ 3
	int a;					// 4 ~ 7 
};

class TEST_02 {

public:
	void Print(void) {
	
		printf("%p\n", &((TEST_02 *)NULL)->ch);
		printf("%p\n", &((TEST_02 *)NULL)->a);
		printf("%p\n", &((TEST_02 *)NULL)->test_01.ch);
		printf("%p\n", &((TEST_02 *)NULL)->test_01.a);
	}

private:
	char ch;				// 0 ~ 3
	int a;					// 4 ~ 7 
	TEST_01 test_01;		// 8 ~ 15
};

int main() {

	system("pause");
	return EXIT_SUCCESS;
}