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

	FILE *fp = fopen("c:/Users/NGPONG/Desktop/1.txt", "r+");
	if (fp == NULL) {

		perror("fp errpr");
	}

	while (1) {

		char ch = fgetc(fp);
		if (ch == EOF) {
			
			break;
		}
		printf("%d ", ch);
	}

	fclose(fp);

	putchar('\n');

	system("pause");
	return EXIT_SUCCESS;
}
