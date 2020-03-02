#pragma warning(disable:6031)
#pragma warning(disable:4996)			

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>
#include <time.h>
#include <conio.h>
#include <Windows.h>

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define STACK_INIT_SIZE 2	 // 栈初始容量
#define STACK_INCREMENT 2   //栈满后，每次扩充的容量
#define EXPRESS_MAX 1024 //后缀表达式 长度不能超过1024
typedef int Status;
typedef char EleType;

typedef struct SeqStack {
	EleType *top;//栈顶指针
	EleType *base;//栈底指针
	int stackSize;//栈容量
}SeqStack;
//初始化栈
Status InitStack(SeqStack *stack) {
	//开辟空间
	stack->base = stack->top = (EleType *)malloc(STACK_INIT_SIZE * sizeof(EleType));
	if (!stack->base) {
		exit(0);
	}

	memset(stack->base, 0x0, STACK_INIT_SIZE * sizeof(EleType));

	stack->stackSize = STACK_INIT_SIZE;
	return OK;
}
//压栈
Status push(SeqStack *stack, EleType e) {
	if (stack == NULL) {
		return ERROR;
	}
	//压栈之前检测容量是否足够
	if (stack->top - stack->base == stack->stackSize) {
		//超出容量 进行扩容，使用realloc函数，会拷贝原内存内容
		stack->base = (EleType *)realloc(stack->base, stack->stackSize + STACK_INCREMENT);
		if (!stack->base) {
			exit(0);
		}
		stack->top = stack->base + stack->stackSize;
		memset(stack->top, 0x0, STACK_INCREMENT);
		stack->stackSize += STACK_INCREMENT;
	}
	*stack->top = e;
	stack->top++;
	return OK;
}
//弹栈
Status pop(SeqStack *stack, EleType *e) {
	if (stack == NULL || e == NULL) {
		return ERROR;
	}
	//空栈
	if (stack->top == stack->base) {
		return ERROR;
	}
	*stack->top--;
	*e = *stack->top;
	return OK;
}
/*
获取栈顶元素
*/
Status GetTop(SeqStack *stack, EleType *e) {
	if (NULL == stack) {
		return ERROR;
	}
	*e = *(stack->top - 1);
	return OK;
}
/*
判断栈是否为空
*/
int IsEmptyStack(SeqStack *stack) {
	if (NULL == stack) {
		return ERROR;
	}
	if (stack->top == stack->base) {
		return TRUE;
	}
	return FALSE;
}
/*
销毁栈
*/
Status DestroyStack(SeqStack *stack) {
	if (NULL == stack) {
		return ERROR;
	}
	//销毁栈 是释放栈在内存中占用的空间资源
	if (!stack->base) {
		free(stack->base);
	}
	stack->top = stack->base = NULL;
	stack->stackSize = 0;
	return OK;
}

int main(void) {

	SeqStack stack;// + - * / ( ）符号栈
	InitStack(&stack);

	push(&stack, 'A');
	push(&stack, 'B');
	push(&stack, 'C');
	push(&stack, 'D');
	push(&stack, 'E');

	return EXIT_SUCCESS;
}
