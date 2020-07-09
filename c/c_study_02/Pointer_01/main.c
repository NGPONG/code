#pragma warning(disable:6031)
#pragma warning(disable:4996)			

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <Windows.h>

struct person {

	char name;		// 0 ~ 3		
	int ok;
	char age;
};

int main(void) {

	//char chars[1024] = { 0 };
	//int a = 1000;

	//memcpy(chars + 1, &a, sizeof(int));

	//int b = *((int *)(chars + 1));

	//int i = 1000;
	//char s[100];

	//itoa(i, s, 2);   //转换成字符串，进制基数为2
	//printf("%s", s);  //输出

	//int a = 10;

	//int *p = &a;

	//int *p2 = (int *)0;

	struct person per = { 1,2,3 };

	int a = (int)&per;

	system("pause");
	return EXIT_SUCCESS;
}
