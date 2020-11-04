#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <Windows.h>

int binary_search(int *arrary, int key, int size) {
  int low = 0;
  int hig = size - 1;

  while (low <= hig) {
    int mid = (low + hig) / 2;  
    if(key < arrary[mid])       /* 若 key 值比预估的数小，则最大指针下标需要从 mid 处 -1(跳过重复的判断) */
      hig = mid - 1;
    else if (key > arrary[mid]) /* 若 key 值比预估的数大，则最小指针下标需要从 mid 处 +1(跳过重复的判断) */
      low = mid + 1;
    else                        /* 若最大和最小相等，则意味着 low 和 high 指针指向同一个下标，即找到了位置 */
      return mid;
  }

  return -1;                    /* 匹配失败则返回 -1 */
}

int main(void) {
  int arrary[] = { 0, 1, 16, 24, 35, 47, 59, 62, 73, 88, 99 };
  binary_search(arrary, 62, sizeof(arrary) / sizeof(int));

  system("pause");
  return EXIT_SUCCESS;
}