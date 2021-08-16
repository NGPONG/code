#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define ZBX_UNUSED(var) (void)(var)

void foo(int i, int b) {
  (void)(i);
  (void)(b);
}

int main(int argc, char *argv[]) {

  return EXIT_SUCCESS;
}
