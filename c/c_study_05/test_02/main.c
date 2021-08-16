#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
  char cmd_buf[16] = "ls";
  printf("%s\n", getcwd(cmd_buf, strlen(cmd_buf)));
  
  return EXIT_SUCCESS;
}
