#pragma warning(disable:6031)
#pragma warning(disable:4996)			

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <Windows.h>

int main(void) {

	char *str = "hellossllodd";
	char *str_Sub = "llo";

	int i = 0;

	while (1) {

		str = strstr(str, str_Sub);
		if (str != NULL) {
		
			i++;
			str += strlen(str_Sub);
			continue;
		}

		break;
	}

	system("pause");
	return EXIT_SUCCESS;
}
