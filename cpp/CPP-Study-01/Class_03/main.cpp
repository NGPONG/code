#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

using namespace std;

class Person {

public:
	Person(void) {


	}

	Person(char *name, int age) {

		this->_name = (char *)malloc(strlen(name) + 1);
		if (this->_name == 0x0) {

			exit(EXIT_FAILURE);
		}
		strcpy(this->_name, name);
		this->_age = age;
	}

	Person(int age) {

		this->_age = age;
	}

	Person(const Person &per) {

		this->_name = (char *)malloc(strlen(per._name) + 1);
		if (this->_name == 0x0) {
		
			exit(EXIT_FAILURE);
		}
		strcpy(this->_name, per._name);

		this->_age = per._age;
	}

	~Person() {

		if (this->_name != 0x0) {

			free(this->_name);
		}
	}

	int _age;
	char *_name;
};

void fun_test_01(Person per) {

}

Person fun_test_02(void) {

	Person per = Person((char *)"Hello,World", 1024);
	return per;
}

int main(void) {

	Person per = Person((char *)"NGPONG", 64);

	Person per_01 = per;
	fun_test_01(per_01);
	Person per_03 = fun_test_02();

	system("pause");
	return EXIT_SUCCESS;
}
