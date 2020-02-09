#pragma warning(disable:6031)
#pragma warning(disable:4996)			

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <Windows.h>

struct Person {

	char name[64];
	int age;
};

void write(void) {

	FILE *f_write = fopen("./test.txt", "wb");
	if (f_write == NULL) {

		perror("file open error");
		return EXIT_FAILURE;
	}

	struct Person pers[3] = {

		{"NGPONG",23},
		{"Hello,World!",99},
		{"c lang",120}
	};

	fwrite(pers, sizeof(struct Person), 3, f_write);

	fclose(f_write);
	printf("OK!\n");
}

void read(void) {

	FILE *f_read = fopen("./test.txt", "rb");
	if (f_read == NULL) {

		perror("file open error");
		return EXIT_FAILURE;
	}

	fseek(f_read, ((int)sizeof(struct Person) * 3) * -1, SEEK_END);

	struct Person per[3];
	fread(&per, sizeof(struct Person), 3, f_read);

	for (size_t i = 0; i < sizeof(per) / sizeof(struct Person); i++) {

		printf("name = %s age = %d\n", (*(per + i)).name, (*(per + i)).age);
	}

	fclose(f_read);
}

void write_read(void) {

	FILE *f_read_write = fopen("./test.txt", "ab+");
	if (f_read_write == NULL) {

		perror("file open error");
		return EXIT_FAILURE;
	}

	struct Person per = { "New!!!!",256 };
	fwrite(&per, sizeof(struct Person), 1, f_read_write);

	rewind(f_read_write);

	struct Person pers[5];
	fread(pers, sizeof(struct Person), 5, f_read_write);

	for (size_t i = 0; i < sizeof(pers) / sizeof(struct Person); i++) {

		printf("name = %s age = %d\n", (*(pers + i)).name, (*(pers + i)).age);
	}


	fclose(f_read_write);
}

void fun_test(void) {

	FILE *f_test = fopen("./test2.txt", "r+");
	if (f_test == NULL) {
	
		perror("file open error");
		return EXIT_FAILURE;
	}

	char str[6] = { 0 };
	fgets(str, 6, f_test);

	printf("file pointer index = %d\n", ftell(f_test));
	fseek(f_test, 0, SEEK_CUR);

	int result = fputs("11111", f_test);
	if (result == 0) {
	
		printf("is ok!!\n");
	}

	fclose(f_test);
}

int main(void) {

	//write();

	//read();

	//write_read();

	fun_test();

	system("pause");
	return EXIT_SUCCESS;
}
