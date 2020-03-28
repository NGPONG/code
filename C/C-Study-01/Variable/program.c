#include <stdio.h>
#include <Windows.h>

int value = 20;

int main(void) {

  int value_Signed_Int = -1;
  printf("Signed_Int:%d\n", value_Signed_Int);

  short value_Signed_Short = -2;
  printf("Signed_Short:%hd\n", value_Signed_Short);

  long value_Signed_Long = -3;
  printf("Signed_Long:%ld\n", value_Signed_Long);

  long long value_Signed_Long_Long = -4;
  printf("Signed_Long_Long:%lld\n", value_Signed_Long_Long);

  printf("\n");
  printf("---------------------------------------------------------------------\n");
  printf("\n");

  unsigned int value_Unsigned_Int = 1;
  printf("Unsigned_Int:%u\n", value_Unsigned_Int);

  unsigned short value_Unsigned_Short = 2;
  printf("Unsigned_Short:%hu\n", value_Unsigned_Short);

  unsigned long value_Unsigned_Long = 3;
  printf("Unsigned_Long:%lu\n", value_Unsigned_Long);

  unsigned long long value_Unsigned_Long_Long = 4;
  printf("Unsigned_Long_Long:%llu\n", value_Unsigned_Long_Long);

  system("pause");
  return 0;
}