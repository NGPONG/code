#pragma warning(disable:6031)
#pragma warning(disable:4996)			

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <Windows.h>

#pragma pack(4)

/*
size : 6byte
Valid: 1
*/
struct student {

	char a;					// 0x00000000
	char b;					// 0x00000001
	char c;					// 0x00000002
	char d;					// 0x00000003
	char e;					// 0x00000004
	char f;					// 0x00000005
};

union object {

	char var;
	short int_16;
	int int_32;
};

/*
size : 16
Valid: 4
*/
struct person {

	char g;					// 0x00000000 ~ 0x00000003	 4
	int i;					// 0x00000004 ~ 0x00000007	 4
	struct student stu;		// 0x00000008 ~ 0x0000000E	 8

};

int main(void) {

	struct person per;
	struct student stu;

	union object obj;
	printf("%d\n", sizeof(obj));


	//printf("%p\n", &stu.a);
	//printf("%p\n", &stu.b);
	//printf("%p\n", &stu.c);
	//printf("%p\n", &stu.d);
	//printf("%p\n", &stu.e);
	//printf("%p\n", &stu.f);



	printf("%p\n", &per.g);
	printf("%p\n", &per.i);
	printf("%p\n", &per.stu);

	printf("size = %d\n", sizeof(per));
	printf("size = %d\n", sizeof(stu));

	system("pause");
	return EXIT_SUCCESS;
}