#include "stack.h"

struct Stack *
Init_Stack() {

	struct Stack *stack = malloc(sizeof(struct Stack));
	if (stack == NULL) {

		return NULL;
	}

	stack->s_data = malloc(sizeof(StackElement *) * MAX_LENGTH);
	if (stack->s_data == NULL) {

		return NULL;
	}
	printf("[+] Init Stack£ºStack Address = %p, Stack Data Address = %p\n", stack, stack->s_data);

	stack->s_size = 0;
	memset(stack->s_data, 0x0, sizeof(StackElement *) * MAX_LENGTH);

	return stack;
}

int 
Push(struct Stack *stack, StackElement *data) {

	if (stack == NULL || stack->s_size == MAX_LENGTH) {

		return -1;
	}

	*(stack->s_data + stack->s_size) = data;
	printf("[+] Push Binary-tree into stack£ºAddress = %p ~ %p, Data Address = %p\n",
		stack->s_data + stack->s_size,
		(char *)(stack->s_data + stack->s_size + 0x1) - 0x1,
		data);
	stack->s_size++;

	return 0;
}

StackElement *
Pop(struct Stack *stack) {

	if (stack == NULL || stack->s_size == 0) {

		return -1;
	}

	StackElement *value = *(stack->s_data + (stack->s_size - 1));
	memset(stack->s_data + (stack->s_size - 1), 0x0, sizeof(StackElement *));
	stack->s_size--;

	return value;
}

int
Destory(struct Stack *stack) {

	if (stack == NULL || stack->s_data == NULL) {

		return -1;
	}

	free(stack->s_data);
	printf("[-] Destory Stack Data£ºAddress = %p\n", stack->s_data);
	free(stack);
	printf("[-] Destory Stack£ºAddress = %p\n", stack);

	return 0;
}