#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

#include "graph.h"

/* @breif 依照书中的 图7-6-3 进行初始化 */
int main(void) {
  n_graph *G = (n_graph *)malloc(sizeof(n_graph));
  init_graph(G, 6, 8);

  create_edge_node_by_pait(0, 1, 5, G->arc);
  create_edge_node_by_pait(1, 0, 5, G->arc);
  create_edge_node_by_pait(0, 2, 1, G->arc);
  create_edge_node_by_pait(2, 0, 1, G->arc);
  create_edge_node_by_pait(1, 2, 2, G->arc);
  create_edge_node_by_pait(2, 1, 2, G->arc);
  create_edge_node_by_pait(1, 3, 1, G->arc);
  create_edge_node_by_pait(3, 1, 1, G->arc);
  create_edge_node_by_pait(2, 3, 4, G->arc);
  create_edge_node_by_pait(3, 2, 4, G->arc);
  create_edge_node_by_pait(2, 4, 8, G->arc);
  create_edge_node_by_pait(4, 2, 8, G->arc);
  create_edge_node_by_pait(3, 4, 3, G->arc);
  create_edge_node_by_pait(4, 3, 3, G->arc);
  create_edge_node_by_pait(3, 5, 6, G->arc);
  create_edge_node_by_pait(5, 3, 6, G->arc);

  shortest_path_floyd(G);  

  system("pause");
  return EXIT_SUCCESS;
}
