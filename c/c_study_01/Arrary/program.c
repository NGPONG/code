#include <stdio.h>
#include <Windows.h>

int main_Temp1(void) {

  char arrary[] = {'1', '2', '\0'};

  printf("%s\n", arrary);

  // for (size_t i = 0; i < sizeof(arrary) / sizeof(arrary[0]); i++)
  //{
  //	printf("%d\n", arrary[i]);
  //}

  system("paurse");
  return 0;
}

int main(void) {

  char str[] = "Hello";

  int length = sizeof(str) / sizeof(str[0]);

  char *p = str;

  system("pause");
  return EXIT_SUCCESS;
}
