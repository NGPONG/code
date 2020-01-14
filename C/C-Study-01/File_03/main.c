#pragma warning(disable:6031)
#pragma warning(disable:4996)			

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <Windows.h>

typedef struct person {

	int age;
	char name[10];
	int gender;
} person_t;

int write(void) {

	person_t per[3] = {
		22,"NGPONG",1,
		11,"wupeng",0,
		100,"NICK",1
	};

	FILE *fp = fopen("c:/Users/NGPONG/Desktop/test.txt", "w");
	if (fp == NULL) {

		perror("fp error");
		return EXIT_FAILURE;
	}

	int ret = fwrite(per, sizeof(person_t),5, fp);

	printf("ret = %d\n", ret);

	fclose(fp);
}

int read(void) {

	person_t per[10];

	FILE *fp = fopen("c:/Users/NGPONG/Desktop/test.txt", "r");
	if (fp == NULL) {

		perror("fp error");
		return EXIT_FAILURE;
	}

	int ret = fread(per, 1, sizeof(person_t) * 3, fp);

	printf("ret = %d\n", ret);

	fclose(fp);
}

int main(void) {

	//write();
	read();
	
	system("pause");
	return EXIT_SUCCESS;
}
