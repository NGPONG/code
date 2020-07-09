#pragma warning(disable:6031)
#pragma warning(disable:4996)			

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <Windows.h>

//�����ڴ�
void allocate_memory(char ***p, int n) {

	if (n < 0) {
		return;
	}

	char **temp = (char **)malloc(sizeof(char *) * n);
	if (temp == NULL) {
		return;
	}

	//�ֱ��ÿһ��ָ��malloc�����ڴ�
	for (int i = 0; i < n; i++) {
		temp[i] = malloc(sizeof(char) * 30);
		sprintf(temp[i], "%2d_hello world!", i + 1);
	}

	*p = temp;
}

//��ӡ����
void array_print(char **arr, int len) {
	for (int i = 0; i < len; i++) {
		printf("%s\n", arr[i]);
	}
	printf("----------------------\n");
}

//�ͷ��ڴ�
void free_memory(char ***buf, int len) {
	if (buf == NULL) {
		return;
	}

	char **temp = *buf;

	for (int i = 0; i < len; i++) {
		free(temp[i]);
		temp[i] = NULL;
	}

	free(temp);
}

void test() {

	int n = 10;
	char **p = NULL;
	allocate_memory(&p, n);
	//��ӡ����
	array_print(p, n);
	//�ͷ��ڴ�
	free_memory(&p, n);
}

int main() {

	test();

	char ***p = malloc(sizeof(char *) * 3);

	p[0] = "Hello,World!";
	p[1] = "Hello,World!";
	**(p + 2) = "lonly!";

	system("pause");
	return EXIT_SUCCESS;
}


