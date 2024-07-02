#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

#include <Windows.h>

using namespace std;

class Test {

public:
	Test() {}

	Test(int id) {
	
		this->id = id;
	}

	~Test() {
	
		//cout << "destructor" << endl;
	}

	int id;
};

struct Test_stu {

	Test_stu() {}

	Test_stu(int id) {
	
		this->id = id;
	}

	~Test_stu() {
	
		cout << "destructor" << endl;
	}

	int id;
};

int main(void) {
	
	/*
	 * 首先是在栈中开辟了一块内存空间并调用对象的构造函数对这块内存空间完成初始化操作
	 * 紧接着在第二次对于已经创建好的对象进行实例化操作时，并不是在原有内存空间的基础上进行，而是在栈上又开辟了一块内存空间，
	 * 然后调用对象的构造函数完成对这块新开辟的内存空间的初始化操作，然后编译器会把这块内存空间的数据逐字节拷贝到赋值对象所指向的内存空间当中去，
	 * 最后再释放掉这块在栈中开辟的内存空间
	 */
	Test te = Test(1);
	te = 2;


	/*
	 * 首先先在堆中开辟了一块连续的内存空间并调用对象的默认构造函数来完成对这块内存空间中所有的对象成员的初始化操作
	 * 紧接着我们在循环中，尝试对刚刚在堆中所开辟的对象数组进行逐元素的初始化操作
	 * 我们通过对当前地址的偏移和解引用能够找到每一个成员在堆中具体存储的内容已完成对它的重新实例化操作 ( 即重新写入新的内存数据 )
	 * 首先编译器会根据我们所指定的 Test(i) 去在栈中开辟一块新的内存空间，然后调用该对象的构造函数以完成对这块内存空间的初始化操作，
	 * 紧接着再把刚刚所初始化的内存数据逐字节拷贝到数组中具体某个下标的成员所代表的内存段中去，最后在释放掉这块在栈中新开辟的内存空间
	 */
	Test *test_arrary = new Test[1024]();
	for (size_t i = 0; i < 1024; i++) {

		test_arrary[i] = Test(i);
	}


	Test_stu te_stu = Test_stu(1);
	te_stu = 2;

	system("pause");
	return EXIT_SUCCESS;
}
