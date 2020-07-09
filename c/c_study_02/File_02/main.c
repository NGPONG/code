#pragma warning(disable:6031)
#pragma warning(disable:4996)			

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <Windows.h>

#include "code.h"
#include "config.h"


int main(void) {

	char **encode_text = decode();

	init(encode_text);

	Sleep(5000);

	freeConfig();

	int index = 0;
	while (1) {

		if (encode_text[index] == NULL) {

			break;
		}

		free(encode_text[index++]);
	}

	free(encode_text);

	system("pause");
	return EXIT_SUCCESS;
}
