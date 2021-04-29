#include "stack.h"

struct Stack *Init_Stack() {
  struct Stack *stack = malloc(sizeof(struct Stack));
  if (stack == NULL) {
    return NULL;
  }

  stack->s_data = malloc(sizeof(char) * MAX_LENGTH);
  if (stack->s_data == NULL) {

    return NULL;
  }

  stack->s_size = 0;
  memset(stack->s_data, 0x0, sizeof(struct Stack));

  return stack;
}

int Push(struct Stack *stack, char data) {
  if (stack == NULL || stack->s_size == MAX_LENGTH) {
    return -1;
  }

  *(stack->s_data + stack->s_size) = data;
  stack->s_size++;

  return 0;
}

int Pop(struct Stack *stack) {
  if (stack == NULL || stack->s_size == 0) {
    return -1;
  }

  char value = *(stack->s_data + (stack->s_size - 1));
  *(stack->s_data + (stack->s_size - 1)) = 0;
  stack->s_size--;
  return value;
}

int Destory(struct Stack *stack) {
  if (stack == NULL || stack->s_data == NULL) {
    return -1;
  }

  free(stack->s_data);
  free(stack);

  return 0;
}
