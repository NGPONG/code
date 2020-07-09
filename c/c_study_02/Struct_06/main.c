#pragma warning(disable:6031)
#pragma warning(disable:4996)	
#pragma warning(disable:6273)
#pragma warning(disable:6011)

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <Windows.h>

#pragma pack (4)
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

/*
size : 12
Valid: 4
*/
struct person {

	int i;					// 0x00000000 ~ 0x00000003	
	char g;					// 0x00000004
	struct student stu;		// 0x00000005 ~ 0x0000000C
};

int main(void) {

	printf("size of student struct = %d\n", sizeof(struct student));
	printf("size of person struct = %d\n", sizeof(struct person));

	struct person *per = NULL;
	printf("person struct i address = %x\n", &(per->i));
	printf("person struct g address = %x\n", &(per->g));
	printf("person struct stu address = %x\n", &(per->stu));

	system("pause");
	return EXIT_SUCCESS;
}
