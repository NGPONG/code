#pragma warning(disable:6031)
#pragma warning(disable:4996)			

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <Windows.h>

int main(void) {
	
	int nums[3] = { 1,2,3 };

	int p = &nums[2] - &nums[0];

	system("pause");
	return EXIT_SUCCESS;
}
