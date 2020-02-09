#pragma warning(disable:6031)
#pragma warning(disable:4996)			

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <Windows.h>

int main(void) {

	int arrary[4][3][2] =
	{
		{
			{ 11,12 }, { 13,14 }, { 15,16 }
		},

		{
			{ 17,18 }, { 19,20 }, { 21,22 }
		},

		{
			{ 23,14 }, { 25,26 }, { 27,28 }
		},

		{
			{ 29,30 }, { 31,32 }, { 33,34 }
		}
	};

	for (size_t i = 0; i < sizeof(arrary) / sizeof(*arrary); i++) {

		for (size_t j = 0; j < sizeof(*arrary) / sizeof(**arrary); j++) {

			for (size_t z = 0; z < sizeof(**arrary) / sizeof(***arrary); z++) {

				printf("%d ", *(*(*(arrary + i) + j) + z));

				if (z + 1 != sizeof(**arrary) / sizeof(***arrary))
					putchar(',');
			}

			putchar('\t');
		}

		putchar('\n');
	}

	putchar('\n');
	putchar('\n');
	putchar('\n');
	putchar('\n');


	int (*arrary_ptr)[3][2] = &arrary;
	
	for (size_t i = 0; i < 4; i++) {

		for (size_t j = 0; j < 3; j++) {

			for (size_t z = 0; z < 2; z++) {

				printf("%d ", *(*(*(arrary_ptr + i) + j) + z));

				if (z + 1 != sizeof(**arrary_ptr) / sizeof(***arrary_ptr))
					putchar(',');
			}

			putchar('\t');
		}

		putchar('\n');
	}


	int nums[4] = { 1,2,3,4 };
	int *p = nums;

	int (*pp)[4] = &nums;

	system("pause");
	return EXIT_SUCCESS;
}
