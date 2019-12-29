#pragma warning(disable:6031)
#pragma warning(disable:4996)			

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <Windows.h>


int main(void) {

	char str[] = "Hello world\n  ";

	int value = strlen(str);

	system("pause");
	return EXIT_SUCCESS;
}

int main_Temp5(void) {

	puts("Hello,World!");

	fputs("My Name is WUPENG\n", stdout);

	system("pause");
	return EXIT_SUCCESS;
}


int main_Temp4(void) {

	char strs[8] = {0};
	gets(strs);

	char testCh;
	scanf("%c", &testCh);


	char testCh1;
	scanf("%c", &testCh1);

	char strs2[8] = { 0 };
	gets(strs2);

	printf("%s",strs);

	system("pause");
	return EXIT_SUCCESS;
}


int main_Temp1(void) {

	char chars[8] = { 'H','e','l' ,'l' ,'o','\n' };
	printf("chars = %s", chars);

	putchar('a');putchar('a');putchar('a');putchar('a');putchar('a');putchar('a');putchar('\n');

	if ("Hello" == chars) {

		printf("OK\n");
	}
	else {

		printf("NO\n");
	}

	char str[8] = "World!";

	printf("%s", str);

	return 0;
}

int main_Temp2(void) {

	char hello[5];

	scanf("%s", hello);

	printf("%s", hello);

	return 0;
}

int main_Temp3(void) {

	 char var = 'A';

	printf("%p", &var);

	getchar();
	return 0;
}