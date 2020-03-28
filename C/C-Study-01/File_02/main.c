#pragma warning(disable : 6031)
#pragma warning(disable : 4996)

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <Windows.h>

int main(void) {

  FILE *fp = fopen("c:/Users/NGPONG/Desktop/test.txt", "r");
  if (fp == NULL) {
    perror("fp error");
    return EXIT_FAILURE;
  }

  char str[32] = {0};
  int a = 0;
  int b = 0;
  char operator= 0;
  while (1) {
    // fscanf(fp, "%d%c%d=", &a, &operator,&b);
    fscanf(fp, "%s", str);
    // fgets(str, sizeof(str), fp);

    memset(str, 0, sizeof(str));
    a = 0;
    b = 0;
    operator= 0;

    if (feof(fp)) break; 

    // printf("%d%c%d=", a, operator,b);
  }

  fclose(fp);
  system("pause");
  return EXIT_SUCCESS;
}
