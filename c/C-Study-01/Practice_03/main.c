#pragma warning(disable:6031)
#pragma warning(disable:4996)			

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <Windows.h>

int compareStr(char *str1, char *str2) {

	bool isCompare = false;
	
}

int main(void) {

	char str1[128];
	char str2[128];

	printf("�������һ���ַ���\n");
	gets(str1);

	printf("������ڶ����ַ���\n");
	gets(str2);

	int result = compareStr(str1, str2);

	switch (result) {
	case 0:
		printf("���");
		break;
	case 1:
		printf("str1 > str2");
		break;
	case -1:
		printf("str1 < str2");
		break;
	default:
		break;
	}

	system("pause");
	return EXIT_SUCCESS;
}