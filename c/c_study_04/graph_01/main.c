#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <Windows.h>

#include "graph.h"

int main(void) {
  n_graph *G = (n_graph *)malloc(sizeof(n_graph));
  init_graph(G);

  printf("hello,world");

  system("pause");
  return EXIT_SUCCESS;
}