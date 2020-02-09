#pragma warning(disable:6031)
#pragma warning(disable:4996)	

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <Windows.h>


void encode(void) {

	FILE *f_Read = fopen("./test.txt","r");
	FILE *f_Write = fopen("./test_encode.bin", "wb");
	if (f_Read == NULL || f_Write == NULL) {
	
		perror("encode file open error");
		return;
	}

	// Reset random number seed 
	srand(time(NULL));

	char symbol;
	BOOLEAN isFirstTime = TRUE;
	while ((symbol = fgetc(f_Read)) != EOF) {

		/*

		char to short -> 0000 0000 0000 0000
		# 0000 0000 0010 0011

		step 1: 0000 0000 0010 0011 << 4					-> 0000 0010 0011 0000
		step 2: 0000 0010 0011 0000 | 1000 0000 0000 0000	-> 1000 0010 0011 0000
		step 3: 0000 0010 0011 0000 + rand() % 16			-> 1000 0010 0011 xxxx
		step 4: If the first character is read, it need to be converted to a negative number.

		exp:
		0000 0000 0010 0011
		0000 0010 0011 0000
		1000 0010 0011 0000‬
		1000 0010 0011 0111‬

		*/

		short mark = (short)symbol;
		mark <<= 4;					// step 1
		mark |= 0x00008000;			// step 2
		mark += rand() % 16;		// step 3
		if (isFirstTime) {			// step 4
			
			isFirstTime = FALSE;
			mark *= -1;
		}

		fwrite(&mark, sizeof(short), 1, f_Write);
	}

	fclose(f_Read);
	fclose(f_Write);
}

void *decode(void) {

	FILE *f_Read = fopen("./test_encode.bin", "rb");
	if (f_Read == NULL) {

		perror("decode file open error");
		return;
	}

	char **configs = malloc(sizeof(char *) * 1024);
	memset(configs, 0, 1024);

	char buffer[128] = { 0 };
	short mark;
	int index_Buffer = 0, index_Configs = 0;
	BOOLEAN isFirstTime = TRUE;
	while (fread(&mark,sizeof(short),1,f_Read)) {

		/*

		srep 1: If the first character is read, you need to turn it into a positive integer.
		step 2: 1000 0010 0011 0111‬ << 1		-> 0000 0100 0110 111‬0
		step 3: 0000 0100 0110 111‬0 >> 5 		-> 0000 0000 0010 0011

		exp:
		1000 0010 0011 0111‬
		0000 0100 0110 111‬0
		0000 0000 0010 0011

		*/
		if (isFirstTime) {
		
			isFirstTime = FALSE;
			mark *= -1;
		}

		mark <<= 1;
		mark >>= 5;
		char symbol = (char)mark;

		/*

		if symbol == '\n': this means that the current row has been readed,
		So we need to open up a new space in the heap

		*/
		if (symbol == '\n') {
		
			configs[index_Configs] = malloc(sizeof(char) * 64);
			strcpy(configs[index_Configs], buffer);
			memset(buffer, 0, 64);

			index_Configs++;
			index_Buffer = 0; 

			continue;
		}
		else {
		
			buffer[index_Buffer] = symbol;
		}

		index_Buffer++;
	}

	fclose(f_Read);

	return configs;
}