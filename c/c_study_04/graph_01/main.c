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

  create_edge_node_by_pait(0, 4, G->arc);
  create_edge_node_by_pait(1, 0, G->arc);
  create_edge_node_by_pait(1, 2, G->arc);
  create_edge_node_by_pait(1, 0, G->arc);
  create_edge_node_by_pait(2, 0, G->arc);
  create_edge_node_by_pait(2, 3, G->arc);
  create_edge_node_by_pait(3, 4, G->arc);

  DES_traverse(G);

  system("pause");
  return EXIT_SUCCESS;
}