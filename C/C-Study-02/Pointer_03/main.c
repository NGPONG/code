#pragma warning(disable:6031)
#pragma warning(disable:4996)			

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <Windows.h>

int main(void) {

	/*typedef int (*ARRAY)[3];

	ARRAY A;

	int a = 10;
	int b = 20;
	int c = 30;

	*/

	char str[3][10] = { "Hello,wo","NGPONG","abcdefghi" };

	char (*p)[3] = str;


	int num[3][2] = 
	{
		{1,2},
		{3,4},
		{5,6} 
	};

	int *ppp = num;

	int (*pp)[2] = &num;

	int num2[3][2] = { {10,20},{30,40 }, { 50,60 } };

	typedef int (arrary)[3];

	arrary a = { 1,2,3 };

	int arrarys[3] = { 1,2,3 };

	int num3[4][3][2] = 
	{
		{
			{ 1,2 }, { 3,4 }, { 5,6 }
		},

		{
			{ 7,8 }, { 9,10 }, { 11,12 }
		},

		{ 
			{ 13,14 }, { 15,16 }, { 17,18 }
		},

		{
			{ 19,20 }, { 21,22 }, { 23,24 }
		} 
	};


	typedef int *num4[3];
	
	int n = 10;
	int n1 = 20;
	int n2 = 30;

	num4 num4_t = { &n,&n1,&n2 };

 	system("pause");
	return EXIT_SUCCESS;
}
