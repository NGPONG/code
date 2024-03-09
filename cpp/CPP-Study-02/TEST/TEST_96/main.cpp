#include <stdio.h>
extern int global_variable;
extern int XOR(int);

void bar() {
  // int aaa = global_variable;
  global_variable += 1000;
  printf("%d\n", global_variable);
} 

int main() {
        bar();
        global_variable = 3;
        printf("%d\n", XOR(0x10));
}
