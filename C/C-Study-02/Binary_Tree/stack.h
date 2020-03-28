#ifndef __STACK_H__
#define __STACK_H__

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "binary_tree.h"

#define MAX_LENGTH 0x400

typedef struct binary_node StackElement;

struct Stack {

  StackElement **s_data;
  int s_size;
};

struct Stack *Init_Stack();
int Push(struct Stack *stack, StackElement *data);
StackElement *Pop(struct Stack *stack);
int Destory(struct Stack *stack);

#endif // __STACK_H__