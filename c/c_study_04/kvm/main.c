#include <math.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>


/**
 * @brief 获取串 [T] 的 [next]
 */
void get_next_base(const char *T, int *next) {
  int i = 1;
  int j = 0;
  int len = (int)T[0];

  next[1] = 0;
  while (i < len) {
    if (j == 0 || T[i] == T[j]) {
      ++i;
      ++j;
      next[i] = j;
    } else {
      j = next[j];
    }
  }
}
void foo_base(void) {
  
}

int main(int argc, char *argv[]) {
  char str[] = {10, 'a', 'b', 'a', 'b', 'a', 'a', 'a', 'b', 'a'};
  int next[sizeof(str)] = { 0 };

  get_next_base(str, next);

  return EXIT_SUCCESS;
}
