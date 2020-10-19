#include <math.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

void get_next(const char *T, int *next) {
  int i = 1;
  int j = 0;
  int len = (int)*T;

  /** 
   * @ a b a b a a a b a
   * 
   * 0 1 2 3 4 5 6 7 8 9
   * 
   *   j i
   * 
   * @ = length of string
  */

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

int main(int argc, char *argv[]) {
  char str[] = { 9, 'a', 'b', 'a', 'b', 'a', 'a', 'a', 'b', 'a' };
  int next[sizeof(str)] = { 0 };

  get_next(str, next);

  return EXIT_SUCCESS;
}
