#pragma warning(disable:6031)
#pragma warning(disable:4996)			

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <Windows.h>

#include "singly_list.h"

void printer_int(node_t *current) {

	printf("node address = %p, data address = %p, Data value = %d\n", current, current->data, *(int *)current->data);
}

int main(void) {

	list_t *list = Create();
	for (int i = 0; i < 1000000; i++) {

		int *a = malloc(sizeof(int));
		if (a == NULL) {
			
			perror("heap error");
			return -1;
		}
		*a = i + 1;
		AddNode(list, a);
	}

	ForeachAllNode(list,printer_int);

	Reverse_List(list);

	ForeachAllNode(list, printer_int);

	Free(list);
	system("pause");
	return EXIT_SUCCESS;
}
