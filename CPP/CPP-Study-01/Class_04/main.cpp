#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <Windows.h>

using namespace std;

class Person {

public:
	Person(char *personName)
		: Name(personName) {

		cout << "Person constructor" << endl;
	}
	Person() {

		cout << "Empty content constructor" << endl;
	}
	~Person() {

		cout << "Person destructor" << endl;
	}
	Person(const Person &per) {

		this->Name = per.Name;
	}

	char *Name;
};

int main(void) {

	Person *pers = (Person *)new char[sizeof(Person) * 10];

	for (int i = 0; i < 10; i++) {

		Person *pp = new (&pers[i]) Person((char *)"test1");
		pers[i] = Person((char *)"test2");
	}

	Person per = Person((char *)"test_01");

	per = Person((char *)"test_02");
	per = Person((char *)"test_03");

	system("pause");
	return EXIT_SUCCESS;
}
