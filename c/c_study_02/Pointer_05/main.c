#pragma warning(disable:6031)
#pragma warning(disable:4996)		
#pragma warning(disable:6011)	

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <Windows.h>

struct Person {

	int age;
	char *name;
};

int NumSort_DESC(void *data1, void *data2) {

	return *(int *)data1 < *(int *)data2;
}

int StringSort_DESC(void *data1, void *data2) {

	return strcmp(*(char **)data1, *(char **)data2) == -1 ? 1 : 0;
}

int PersonSort_DESC(void *data1, void *data2) {

	struct Person **per1 = (struct Person **)data1;
	struct Person **per2 = (struct Person **)data2;

	if ((*per1)->age < (*per2)->age && strcmp((*per1)->name, (*per2)->name) == -1) {
	
		return TRUE;
	}
	else {
	
		return FALSE;
	}
}

void ArrarySort(BYTE *arrary, int element_Size, int arrary_length,int (*invoker)(void *,void *)) {

	BYTE *temp = malloc(sizeof(element_Size));
	if (temp == NULL) {
	
		return;
	}
	memset(temp, 0, element_Size);

	for (size_t i = 0; i < arrary_length; i++) {

		int min_index = i;
		for (size_t j = i + 1; j < arrary_length; j++) {

			if (invoker(arrary + element_Size * j, arrary + element_Size * min_index)) {
			
				min_index = j;
			}
		}

		if (min_index != i) {
		
			memcpy(temp, arrary + element_Size * min_index, element_Size);
			memcpy(arrary + element_Size * min_index, arrary + element_Size * i, element_Size);
			memcpy(arrary + element_Size * i, temp, element_Size);

			memset(temp, 0, element_Size);
		}
	}
  
  free(temp);
}



int main(void) {

	int arrary_num[7] = { 3,6,4,1,5,2,7 };
	ArrarySort(arrary_num, sizeof(int), sizeof(arrary_num) / sizeof(arrary_num[0]), NumSort_DESC);

	char *arrarys_str[5] = { "bbb","ddd","aaa","eee","ccc" };
	ArrarySort(arrarys_str, sizeof(char *), sizeof(arrarys_str) / sizeof(arrarys_str[0]), StringSort_DESC);

	struct Person **arrary_pers = malloc(sizeof(struct Person *) * 4);
	arrary_pers[0] = malloc(sizeof(struct Person));
	arrary_pers[1] = malloc(sizeof(struct Person));
	arrary_pers[2] = malloc(sizeof(struct Person));
	arrary_pers[3] = malloc(sizeof(struct Person));
	arrary_pers[0]->age = 3;
	arrary_pers[0]->name = "ccc";
	arrary_pers[1]->age = 4;
	arrary_pers[1]->name = "ddd";
	arrary_pers[2]->age = 2;
	arrary_pers[2]->name = "bbb";
	arrary_pers[3]->age = 1;
	arrary_pers[3]->name = "aaa";

	ArrarySort(arrary_pers, sizeof(struct Person *), 4, PersonSort_DESC);

	free(arrary_pers[0]);
	free(arrary_pers[1]);
	free(arrary_pers[2]);
	free(arrary_pers[3]);

	free(arrary_pers);

	system("pause");
	return EXIT_SUCCESS;
}
