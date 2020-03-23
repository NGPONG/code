#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

using namespace std;

class Person {

public:
	Person(int age) 
		:_age(age) { }

	void fun_test_normal(void) {
	
		cout << "Person Age = " << this->_age << endl;
	}

	static void fun_test_static(void) {

		cout << "static function" << endl;
	}

private:
	int _age;
};

 
int main(void) {

	Person per = Person(23);

	per.fun_test_normal();
	per.fun_test_static();

	Person::fun_test_static();

	system("pause");
	return EXIT_SUCCESS;

}
