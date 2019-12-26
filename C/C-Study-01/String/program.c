#include <stdio.h>

int main(void) {

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