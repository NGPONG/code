#pragma warning(disable:6031)
#pragma warning(disable:4996)			

#include <iostream>

using namespace std;

namespace {

	void fun_test_01(void) {

		int arrary[10] = { 0 };
		int (&arrary_ref)[10] = arrary;

		for (size_t i = 0; i < sizeof(arrary_ref) / sizeof(*arrary_ref); i++) {

			*(arrary_ref + i) = 10 + i;
		}

		for (size_t i = 0; i < sizeof(arrary) / sizeof(*arrary); i++) {

			cout << *(arrary + i) << endl;
		}
	}

	void fun_test_02(int &num_ref_1, int &num_ref_2) {

		num_ref_1 = num_ref_1 ^ num_ref_2;
		num_ref_2 = num_ref_1 ^ num_ref_2;
		num_ref_1 = num_ref_1 ^ num_ref_2;

		cout << "Address num_ref_1 = " << &num_ref_1 << " ,Address num_ref_2 = " << &num_ref_2 << endl;
	}

	int &fun_test_03(void) {
	
		static int a = 10;
		cout << a << endl;
		return a;
	}

	void fun_test_04(void) {
	
		int a = 10;
		const int &a_ref = a;
	}

	void fun_test_05(void) {
	
		/*
		 * int temp = 1024;
		 * const int &a_ref = temp;
		 */
		const int &a_ref = 1024;

		int *p = (int *)&a_ref;
		*p = 256;

		cout << *p << endl;
		cout << a_ref << endl;
	}
}

int main(void) {

	::fun_test_05();

	system("pause");
	return EXIT_SUCCESS;
}
