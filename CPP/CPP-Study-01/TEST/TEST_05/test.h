#ifndef __TEST_H__
#define __TEST_H__

#include <iostream>
using namespace std;

static void fun_test_g_static(void);
void fun_test_g_static(void) { cout << "fun_test_g_static" << endl; }

namespace {

void fun_test_01(void);
void fun_test_01(void) { cout << "fun_test_anonymous" << endl; }
}

#endif /* end of include guard: __TEST_H__ */
