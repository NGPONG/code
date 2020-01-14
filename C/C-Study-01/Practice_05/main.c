#pragma warning(disable:6031)
#pragma warning(disable:4996)			

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <Windows.h>

int addition(int a, int b,char operator) {

	int result = 0;
	switch (operator) {
	case'+':
		result = a + b;
		break;
	case'-':
		result = a - b;
		break;
	case'*':
		result = a * b;
		break;
	case'/':
		result = a / b;
		break;
	default:
		return EXIT_FAILURE;
		break;
	}

	return result;
}

int main(void) {

	FILE *fp_Read = fopen("c:/Users/NGPONG/Desktop/test.txt", "r+");
	if (fp_Read == NULL) {

		perror("fopen error");
		system("pause");
		return EXIT_FAILURE;
	}

	FILE *fp_Write = fopen("c:/Users/NGPONG/Desktop/test2.txt", "w+");
	if (fp_Read == NULL) {

		perror("fopen error");
		system("pause");
		return EXIT_FAILURE;
	}

	char str[128] = { 0 };
	int a = 0;
	int b = 0;
	char operator = 0;
	while (1) {

		fgets(str, sizeof(str), fp_Read);

		sscanf(str, "%d%c%d=", &a, &operator,&b);
		int result = addition(a, b, operator);

		char str_Write[32] = { 0 };
		sprintf(str_Write, "%d%c%d=%d\n", a, operator,b, result);

		fputs(str_Write, fp_Write);

		if (feof(fp_Read)) {

			break;
		}
	}
	
	printf("OK!!");

	fclose(fp_Read);
	fclose(fp_Write);
	system("pause");
	return EXIT_SUCCESS;
}
