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

	FILE *fp = fopen("c:/Users/NGPONG/Desktop/test.txt", "w+");
	if (fp == NULL) {

		perror("fp errpr");
		return EXIT_FAILURE;
	}

	char str[64] = { 0 };
	char *str_Temp;
	while (1) {

		fgets(str, sizeof(str), stdin);

		str_Temp = strstr(str, ":wq");
		if (str_Temp) {
		
			int mem_Seek = str_Temp - str;
			char str_Temp_Arrary[64] = { 0 };
			memcpy(str_Temp_Arrary, str, mem_Seek);
			fputs(str_Temp_Arrary, fp);
			break;
		}

		fputs(str, fp);
	}

	fclose(fp);
	system("pause");
	return EXIT_SUCCESS;
}
