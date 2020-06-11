#include <stdio.h>
#include <sys/wait.h>
#include "source.h"

void foo() {
  int _val = 0;
  while(1) {
    sleep(1);
    printf("%d\n",++_val);
  }
  return;
}
