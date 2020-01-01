#pragma warning(disable:6031)
#pragma warning(disable:4996)			

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <Windows.h>

int main(void) {

	int nums[8] = { 1,2,3,4,5,6,7,8 };

	int *p = nums;
	
	int length = sizeof(nums) / sizeof(nums[0]);
	for (size_t i = 0; i < length; i++) {

		if (i < 7)
			p++;

		printf("%d\t", *p);
	}
	//p = NULL;
	
	system("pause");
	return EXIT_SUCCESS;
}