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

int main(void) {

	list_t *list = Create();
	AddNode(list, 1);
	AddNode(list, 2);
	AddNode(list, 3);
	AddNode(list, 4);
	AddNode(list, 5);
	AddNode(list, 6);
	ForeachAllNode(list);

	Reverse_List(list);

	ForeachAllNode(list);

	//for (size_t i = 0; i < 1000000; i++) {

	//	AddNode(list, i + 1);
	//}
	
	Free(list);
	system("pause");
	return EXIT_SUCCESS;
}
