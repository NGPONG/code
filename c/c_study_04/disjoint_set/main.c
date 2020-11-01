#include <math.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "set.h"

int main(int argc, char *argv[]) {
  int edges[VERTICES][2] = {
    { 0, 1 }, { 1, 2 }, { 1, 3 }, 
    { 2, 4 }, { 3, 4 }, { 2, 5 }
  };

  initialise_disjoint_set();

  for (size_t i = 0; i < VERTICES; ++i) {
    int x = edges[i][0];
    int y = edges[i][1];

    union_set_rank(x, y);
  }

  return EXIT_SUCCESS;
}
