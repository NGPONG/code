#ifndef __TEST_H__
#define __TEST_H__

#include <iostream>

using namespace std;

/* Global namespace
 *
 * BEGIN */
extern int a_g;

static int a_g_static;

void fun_test_g(void);

static void fun_test_g_static(void);
void fun_test_g_static(void) {

	cout << "fun_test_g_static" << endl;
}
/* Global namespace
 *
 * END */



/* Anonymous namespace - global
 * 
 * BEGIN */
namespace {

	extern int a_g_anonymous;
	static int a_g_static_anonymous;
	void fun_test_g_anonymous(void);
	static void fun_test_g_static_anonymous(void);
}

int ::a_g_anonymous = 256;

void ::fun_test_g_anonymous(void) {

	cout << "fun_test_g_anonymous" << endl;
}

void ::fun_test_g_static_anonymous(void) {

	cout << "fun_test_g_static_anonymous" << endl;
}
/* Anonymous namespace - global
 *
 * END */



namespace TEST {
   /* TEST namespace
    *
    * BEGIN */
    extern int a_g_TEST;

    static int a_g_static_TEST;

    void fun_test_g_TEST(void);

    static void fun_test_g_static_TEST(void);
    void fun_test_g_static_TEST(void) {

        cout << "fun_test_g_static_TEST" << endl;
    }
   /* TEST namespace - global
    *
    * END */


    /* CLASS namespace
     *
     * BEGIN */
    class Person {

    public:
        Person(int value) :a_g_Person(value){ }
        int a_g_Person;
        static int a_g_static_Person;
        void fun_test_g_Person(void);
        static void fun_test_g_static_Person(void);
    };
    /* CLASS namespace
     *
     * END */
}


#endif // !__TEST_H__