#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define VERTICES 6

int parent[6] = { 0 }; 

int find_root(int f) {
  if (parent[f] == f) { 
    return f;
  }

  return find_root(parent[f]);
}

bool union_set(int x, int y) {
  int x_root = find_root(x);
  int y_root = find_root(y);

  if (x_root == y_root) {
    return false;
  }

  parent[x_root] = y_root;
  return true;
}

void initialise_disjoint_set() {
  /* parent_set */
  for (size_t i = 0; i < VERTICES; ++i) {
    parent[i] = i;
  }
}

int main(int argc, char *argv[]) {
  int edges[VERTICES][2] = {
    { 0, 1 }, { 1, 2 }, { 1, 3 }, 
    { 2, 4 }, { 3, 4 }, { 2, 5 }
  };

  initialise_disjoint_set();

  for (size_t i = 0; i < VERTICES; ++i) {
    int x = edges[i][0];
    int y = edges[i][1];

    union_set(x, y);
  }

  int count = 0;
  for (int i = 0; i < VERTICES; ++i) {
    if (parent[i] == i)
      ++count;
  }
  printf("%d\n", count);
  
  return EXIT_SUCCESS;
}
