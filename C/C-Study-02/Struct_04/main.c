#pragma warning(disable:6031)
#pragma warning(disable:4996)		
#pragma warning(disable:6011)	
#pragma warning(disable:6387)	

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <Windows.h>

typedef struct student {

	char *name;
	int age;
	int id;
} Student;

typedef struct teacher {

	char *name;
	int age;
	Student **students;
} Teacher;

void test_fun(void) {

	Teacher **teachers = malloc(sizeof(Teacher *) * 3);

	Teacher *teacher_han = malloc(sizeof(Teacher));
	(*teacher_han).name = malloc(sizeof(char) * 64);
	strcpy((*teacher_han).name, "HAN AI GUO");
	(*teacher_han).age = 30;
	(*teacher_han).students = malloc(sizeof(Student *) * 30);
	for (size_t i = 0; i < 30; i++) {

		Student *student = malloc(sizeof(Student));
		(*student).age = (i + 10);
		(*student).id = i + 1;
		(*student).name = malloc(sizeof(char) * 64);
		sprintf((*student).name, "Mr.Han - Student - %d", i + 1);

		*((*teacher_han).students + i) = student;
	}

	Teacher *teacher_zhang = malloc(sizeof(Teacher));
	(*teacher_zhang).name = malloc(sizeof(char) * 64);
	strcpy((*teacher_zhang).name, "ZHANG SAN");
	(*teacher_zhang).age = 24;
	(*teacher_zhang).students = malloc(sizeof(Student *) * 15);
	for (size_t i = 0; i < 15; i++) {

		Student *student = malloc(sizeof(Student));
		(*student).age = (i + 10);
		(*student).id = i + 1;
		(*student).name = malloc(sizeof(char) * 64);
		sprintf((*student).name, "Mr.Zhang - Student - %d", i + 1);

		*((*teacher_zhang).students + i) = student;
	}

	Teacher *teacher_wu = malloc(sizeof(Teacher));
	(*teacher_wu).name = malloc(sizeof(char) * 64);
	strcpy((*teacher_wu).name, "WU PENG");
	(*teacher_wu).age = 49;
	(*teacher_wu).students = malloc(sizeof(Student *) * 20);
	for (size_t i = 0; i < 20; i++) {

		Student *student = malloc(sizeof(Student));
		(*student).age = (i + 10);
		(*student).id = i + 1;
		(*student).name = malloc(sizeof(char) * 64);
		sprintf((*student).name, "Mr.Wu - Student - %d", i + 1);

		*((*teacher_wu).students + i) = student;
	}

	*(teachers + 0) = teacher_han;
	*(teachers + 1) = teacher_zhang;
	*(teachers + 2) = teacher_wu;


	printf("My Name is %s, I'm %d years old\n", (**(teachers + 0)).name, (**(teachers + 0)).age);
	for (size_t i = 0; i < 30; i++) {

		printf("\tStudent: name = %s,age = %d,id = %d\n", (*(*((**(teachers + 0)).students + i))).name, (*(*((**(teachers + 0)).students + i))).age, (*(*((**(teachers + 0)).students + i))).id);
	}

	putchar('\n');

	printf("My Name is %s, I'm %d years old\n", (**(teachers + 1)).name, (**(teachers + 1)).age);
	for (size_t i = 0; i < 15; i++) {

		printf("\tStudent: name = %s,age = %d,id = %d\n", (*(*((**(teachers + 1)).students + i))).name, (*(*((**(teachers + 1)).students + i))).age, (*(*((**(teachers + 1)).students + i))).id);
	}

	putchar('\n');

	printf("My Name is %s, I'm %d years old\n", (**(teachers + 2)).name, (**(teachers + 2)).age);
	for (size_t i = 0; i < 20; i++) {

		printf("\tStudent: name = %s,age = %d,id = %d\n", (*(*((**(teachers + 2)).students + i))).name, (*(*((**(teachers + 2)).students + i))).age, (*(*((**(teachers + 2)).students + i))).id);
	}

	putchar('\n');


	/*
	TODO: free all heap memory
	*/
	for (size_t i = 0; i < 30; i++) {

		free((*(*((**(teachers + 0)).students + i))).name);
		(*(*((**(teachers + 0)).students + i))).name = NULL;

		free(*((**(teachers + 0)).students + i));
		*((**(teachers + 0)).students + i) = NULL;
	}
	free((**(teachers + 0)).students);
	(**(teachers + 0)).students = NULL;
	free((**(teachers + 0)).name);
	(**(teachers + 0)).name = NULL;
	free(*(teachers + 0));
	*(teachers + 0) = NULL;

	for (size_t i = 0; i < 15; i++) {

		free((*(*((**(teachers + 1)).students + i))).name);
		(*(*((**(teachers + 1)).students + i))).name = NULL;

		free(*((**(teachers + 1)).students + i));
		*((**(teachers + 1)).students + i) = NULL;
	}
	free((**(teachers + 1)).students);
	(**(teachers + 1)).students = NULL;
	free((**(teachers + 1)).name);
	(**(teachers + 1)).name = NULL;
	free(*(teachers + 1));
	*(teachers + 1) = NULL;

	for (size_t i = 0; i < 20; i++) {

		free((*(*((**(teachers + 2)).students + i))).name);
		(*(*((**(teachers + 2)).students + i))).name = NULL;

		free(*((**(teachers + 2)).students + i));
		*((**(teachers + 2)).students + i) = NULL;
	}
	free((**(teachers + 2)).students);
	(**(teachers + 2)).students = NULL;
	free((**(teachers + 2)).name);
	(**(teachers + 2)).name = NULL;
	free(*(teachers + 2));
	*(teachers + 2) = NULL;

	free(teachers);
}

int main(void) {

	test_fun();

	printf("OK!!!!");

	Sleep(20000);

	system("pause");
	return EXIT_SUCCESS;
}
