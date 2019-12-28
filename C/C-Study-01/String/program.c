#include <stdio.h>

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

int main(void) {

	 char var = 'A';

	printf("%p", &var);

	getchar();
	return 0;
}