#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>

int main(void) {

	int arrary[] = { 8,1,6,3,9,4,7,2,5 };

	int length = sizeof(arrary) / sizeof(arrary[0]);

	// Source arrary.
	for (size_t i = 0; i < length; i++) {
		
		printf("%d\n", arrary[i]);
		if (i + 1 == length) {
		
			printf("\n\n----------------------------------------------------------------------------\n\n");
		}
	}

	for (size_t i = 0; i < length; i++) {

		for (size_t j = 0; j < length - 1 - i; j++) {
			
			/*

			8,1,6,3,9,4,7,2,5
			1,6,3,9,4,7,2,5      (8)
			1,6,3,4,7,2,5        (8,9)
			1,6,3,4,2,5		     (7,8,9)
			1,3,4,2,5		     (6,7,8,9)
			1,3,4,2		         (5,6,7,8,9)
			1,3,2		         (4,5,6,7,8,9)
			1,2		             (3,4,5,6,7,8,9)
			1		             (2,3,4,5,6,7,8,9)
					             (1,2,3,4,5,6,7,8,9)

			*/

			if (arrary[j] > arrary[j + 1]) {
			
				int num_Temp = arrary[j + 1];
				arrary[j + 1] = arrary[j];
				arrary[j] = num_Temp;
			}
		}
	}

	// Sort process result
	for (size_t i = 0; i < length; i++) {

		printf("%d\n", arrary[i]);
	}

	system("pause");
	return 0;
}