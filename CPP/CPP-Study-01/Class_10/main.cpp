#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

using namespace std;

class Person {

public:
	int age;

	Person()
		:age(1024), name((char *)"NGPONG") {

	}

	Person(int age)
		:age(age), name((char *)"Hello,World!") {

	};

	void Print() {

		Person per = Person();

		cout << this->age << endl;
	}

	~Person() {

		cout << "Person destructor" << endl;
	}


private:
	char *name;
};

int main(void) {

	Person *per = new Person();
	cout << per->age << endl;

	*per = Person(64);
	cout << per->age << endl;

	system("pause");
	return EXIT_SUCCESS;
}
