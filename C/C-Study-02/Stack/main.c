#pragma warning(disable:6031)
#pragma warning(disable:4996)			

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <Windows.h>

#include "stack.h"
#include "symbol.h"

int compare(char ch_compare, char ch_top) {

	if (IS_LEFT(ch_compare) || IS_LEFT(ch_top))
		return 1;

	else if (IS_PLUS_OR_MINUS(ch_compare)) 
		if (IS_ASTERISK_OR_DIVISION(ch_top)) 
			return 0; 
		else 
			return 1;

	else if (IS_ASTERISK_OR_DIVISION(ch_compare))
		if (IS_PLUS_OR_MINUS(ch_top))
			return 1;
		else
			return 0;
}

int main(void) {

	/*

	8 + ( 3 �C 1 ) * 5 ==>  8 3 1 �C 5 * +

	1. ���֣�ֱ�����
	2. ���ţ�
		2.1 �����ţ���ջ
		2.2 ������ţ���ջ�����Ž������ȼ��Ƚ�
			2.2.1 ��ջ���������ȼ��ͣ��˷��Ž�ջ��Ĭ��ջ�����������ţ����������ȼ���ͣ�
			2.2.2 ��ջ���������ȼ����ͣ���ջ�����ŵ�����������˷��Ž�ջ
	3. �����ţ���ջ�����ŵ����������ֱ��ƥ�������ţ��������ź�������ͬʱ����
	4. ������������ջ�е����з��ŵ��������

	*/
	char *str_Infix = "a+b*c+(d*e+f)*g";
	char str_postfix[64] = { 0 };

	struct Stack *stack = Init_Stack();
	if (stack == NULL) {

		perror("stack error");
		return EXIT_FAILURE;
	}

	int postfixIndex = 0;
	for (size_t i = 0; i < strlen(str_Infix); i++) {

		char ch = *(str_Infix + i);
		if (IS_SYMBOL(ch) || IS_LEFT(ch)) {

			char ch_top = Pop(stack);
			if (ch_top == -1) {
			
				Push(stack, ch);
			}
			else if (compare(ch, ch_top)) {

				Push(stack, ch_top);
				Push(stack, ch);
			}
			else {

				*(str_postfix + postfixIndex) = ch; postfixIndex++;
				Push(stack, ch);
			}
		}
		else if (IS_RIGHT(ch)) {

			while (1) {

				char ch_temp = Pop(stack);
				if (ch_temp == -1) {
				
					/*
					In infix notation, no left parenthesis matches right parenthesis
					*/
					perror("the infix notation error");
					return EXIT_FAILURE;
				}
				else if (IS_LEFT(ch_temp)) {
				
					break;
				}
				else if (IS_SYMBOL(ch_temp)) {
				
					*(str_postfix + postfixIndex) = ch_temp; postfixIndex++;
				}
			}
		}
		else if (IS_LEFT(ch)) {
		
			Push(stack, ch);
		}
		else if (ch == 32) {
		
			continue;
		}
		else {
		
			*(str_postfix + postfixIndex) = ch; postfixIndex++;
		}
	}

	/*It have something else symbol wasn't output*/
	if (stack->s_size != 0) {
	
		char ch;
		while (1) {

			if ((ch = Pop(stack)) == -1) break;

			*(str_postfix + postfixIndex) = ch; postfixIndex++;
		}
	}

	printf("postfix notation = %s\n", str_postfix);

	Destory(stack);

	system("pause");
	return EXIT_SUCCESS;
}
