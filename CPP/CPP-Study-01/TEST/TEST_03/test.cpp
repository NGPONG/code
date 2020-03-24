#include "test.h"

/* Global namespace */
int ::a_g = 256;
void ::fun_test_g(void) {

	cout << "fun_test_g" << endl;
}


/* TEST namespace */
int TEST::a_g_TEST = 256;
void TEST::fun_test_g_TEST(void) {

	cout << "fun_test_g_TEST" << endl;
}


/* CLASS namespace */
int TEST::Person::a_g_static_Person = 1024;
void TEST::Person::fun_test_g_Person(void) {

	cout << "fun_test_g_Person" << endl;
}
void TEST::Person::fun_test_g_static_Person(void) {

	cout << "fun_test_g_static_Person" << endl;
}