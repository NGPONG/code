#ifndef __STACK_H__
#define __STACK_H__

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 0x400

struct Stack {

	char *s_data;
	int s_size;
};

struct Stack *Init_Stack();
int Push(struct Stack *stack, char data);
int Pop(struct Stack *stack);
int Destory(struct Stack *stack);

#endif // __STACK_H__