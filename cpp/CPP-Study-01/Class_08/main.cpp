#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

using namespace std;

class Person {

private:
	int m_id;
	mutable int m_age;

public:
	Person(int id, int age) :m_id(id), m_age(age) {}

	void fun_test_01(void) const {
	
		cout << "age = " << this->m_age << endl;
		this->m_age = 1024;
		cout << "age = " << this->m_age << endl;

		cout << "id = " << this->m_id << endl;
		int &p_m_id = (int &)this->m_id;
		p_m_id = 64;
		cout << "id = " << this->m_id << endl;
	}

	void fun_test_02(void) {
	
	
	}

	int m_gender;
};

int main(void) {

	const Person per = Person(1, 24);
	per.fun_test_01();

	system("pause");
	return EXIT_SUCCESS;
}
