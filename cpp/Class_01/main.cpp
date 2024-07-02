#pragma warning(disable:6031)
#pragma warning(disable:4996)			

#include <iostream>

using namespace std;

class Student {
public:
	void Init(int age, char *name,char gender,double id) {
	
		this->_age = age;
		this->_name = name;
		this->_gender = gender;
		this->_id = id;
	}

	int PrintField(void) {
	
		cout << "Student Age = "  << this->_age  << endl
			 << "Student Name = " << this->_name << endl;

		return 0;
	}

	void PrintFieldAddress(void) {
	
		printf("Size  :%d\n", sizeof(*this));
		printf("Gender:%p\n", &this->_gender);
		printf("Age   :%p\n", &this->_age);
		printf("ID    :%p\n", &this->_id);
		printf("Name  :%p\n", &this->_name);
	}

	void fun_test_04(int *p) {

		cout << *p << endl;
	}

private:
	double _id;
	char _gender;
	int _age;
	char *_name;
};

namespace {

	void fun_test_01(void) {
	
		Student stu;
		stu.Init(22, (char *)"NGPONG", '1', 256);

		printf("%s\n", *(char **)((char *)&stu + 16));
	}

	void fun_test_02(void) {
	
		Student stu;
		stu.Init(22, (char *)"NGPONG", '1', 256);
		stu.PrintFieldAddress();
	}

	void Exponentiation(int &a, int b = 2) {

		for (size_t i = 0; i < b; i++) {

			a *= a;
		}
	}

	void fun_test_03(void) {
	
		int a = 8;
        ::Exponentiation(a);

        cout << a << endl;
	}

	void fun_test_04(void) {

		cout << 1 << endl;
	}

	void fun_test_05(int &a) {
	
		cout << 1 << endl;
	}

	void fun_test_05(const int &a) {
	
		cout << 2 << endl;
	}
}

int main(void) {

	int a = 1024;

	const int &a_ref = a;

	cout << a_ref << endl;

	int *p = (int *)&a_ref;
	*p = 256;

	cout << a << endl;
	cout << a_ref << endl;

	system("pause");
	return EXIT_SUCCESS;
}
