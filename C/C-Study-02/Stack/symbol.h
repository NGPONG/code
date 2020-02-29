#ifndef __SYMBOL_H__
#define __SYMBOL_H__

#define IS_SYMBOL(ch) (ch == '+' || ch == '-' || ch == '*' || ch == '/')
#define IS_RIGHT(ch) (ch == ')')
#define IS_LEFT(ch) (ch == '(')
#define IS_PLUS_OR_MINUS(ch) (ch == '+' || ch == '-')
#define IS_ASTERISK_OR_DIVISION(ch) (ch == '*' || ch == '/')

#endif // !__SYMBOL_H__
