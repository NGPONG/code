#pragma warning(disable:6031)
#pragma warning(disable:4996)			

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <Windows.h>

#define MAX_LENGTH 1024 * 5

int copy(void) {

	char buffer[MAX_LENGTH];

	FILE *reader = fopen("c:/Users/NGPONG/Desktop/毒液.mp4", "rb");
	FILE *writer = fopen("c:/Users/NGPONG/Desktop/111.mp4", "wb");
	if (reader == NULL || writer == NULL) {

		perror("file error");
		return -1;
	}

	while (1) {

		int ret = fread(buffer, 1, MAX_LENGTH, reader);

		if (!fwrite(buffer, ret, 1, writer)) {
			
			perror("fwrite error");
			return -1;
		}

		if (feof(reader)) {
			
			break;
		}
	}

	fclose(reader);
	fclose(writer);
}

int main(void) {

	copy();

	system("pause");
	return EXIT_SUCCESS;
}
