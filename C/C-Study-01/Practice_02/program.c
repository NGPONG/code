#pragma warning(disable:6031)
#pragma warning(disable:4996)

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <Windows.h>

int main (void) {

	printf ("请输入你需要录入的字符串\n");
	
	int effective_Count = 0;

	char str_Read[256] = { 0 };
	for (size_t i = 0; i < 256; i++) {

		scanf("%c", &str_Read[i]);

		if (str_Read[i] == '\n') {
		
			effective_Count = i;
			break;
		}
	}

	int count[26] = { 0 };
	for (size_t i = 0; i < effective_Count; i++) {

		int index = str_Read[i] - 'a';
		count[index]++;
	}

	// Print
	for (size_t i = 0; i < sizeof(count) / sizeof(count[0]); i++) {

		if(count[i] != 0)
			printf("字母 [ %c ] 一共出现了 %d 次\n", i + 'a', count[i]);
	}


	system ("pause");
	return EXIT_SUCCESS;
}
