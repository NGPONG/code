#pragma warning(disable:6031)
#pragma warning(disable:4996)			

#include <iostream>
using namespace std;

#include "test.h"

int main(void) {

	/* globale namespace */
	cout << ::a_g << endl;
	cout << ::a_g_static << endl;
	fun_test_g();
	fun_test_g_static();

	/* Anonymouse namespace - globale */
	cout << ::a_g_anonymous << endl;
	cout << ::a_g_static_anonymous << endl;
	::fun_test_g_anonymous();
	::fun_test_g_static_anonymous();


	/* TEST namespace */
	cout << TEST::a_g_TEST << endl;
	cout << TEST::a_g_static_TEST << endl;
	TEST::fun_test_g_TEST();
	TEST::fun_test_g_static_TEST();	


	/* CLASS namespace */
	TEST::Person per = TEST::Person(256);
	cout << per.a_g_Person << endl;
	cout << TEST::Person::a_g_static_Person << endl;
	per.fun_test_g_Person();
	TEST::Person::fun_test_g_static_Person();

	system("pause");
	return EXIT_SUCCESS;
}