#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

#include "graph.h"

/* @breif 依照书中的 图7-6-3 进行初始化 */
int main(void) {
  n_graph *G = (n_graph *)malloc(sizeof(n_graph));
  init_graph(G, 9, 15);

  // create_edge_node_by_pait(0, 1, 10, G->arc);
  // create_edge_node_by_pait(0, 5, 11, G->arc);

  // create_edge_node_by_pait(1, 0, 10, G->arc);
  // create_edge_node_by_pait(1, 2, 18, G->arc);
  // create_edge_node_by_pait(1, 6, 16, G->arc);
  // create_edge_node_by_pait(1, 8, 12, G->arc);

  // create_edge_node_by_pait(2, 3, 22, G->arc);
  // create_edge_node_by_pait(2, 8, 8, G->arc);

  // create_edge_node_by_pait(3, 2, 22, G->arc);
  // create_edge_node_by_pait(3, 4, 20, G->arc);
  // create_edge_node_by_pait(3, 7, 16, G->arc);
  // create_edge_node_by_pait(3, 8, 21, G->arc);

  // create_edge_node_by_pait(4, 3, 20, G->arc);
  // create_edge_node_by_pait(4, 5, 26, G->arc);
  // create_edge_node_by_pait(4, 7, 7, G->arc);

  // create_edge_node_by_pait(5, 0, 11, G->arc);
  // create_edge_node_by_pait(5, 4, 26, G->arc);
  // create_edge_node_by_pait(5, 6, 17, G->arc);

  // create_edge_node_by_pait(6, 1, 16, G->arc);
  // create_edge_node_by_pait(6, 5, 17, G->arc);
  // create_edge_node_by_pait(6, 7, 19, G->arc);

  // create_edge_node_by_pait(7, 3, 16, G->arc);
  // create_edge_node_by_pait(7, 4, 7, G->arc);
  // create_edge_node_by_pait(7, 6, 19, G->arc);
  
  // create_edge_node_by_pait(8, 1, 12, G->arc);
  // create_edge_node_by_pait(8, 2, 8, G->arc);
  // create_edge_node_by_pait(8, 3, 21, G->arc);

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


  /* min_span_tree_prim(G); */

  /* DES_traverse(G);
  BFS_traverse(G); */

  dijkstra(G);

  system("pause");
  return EXIT_SUCCESS;
}
