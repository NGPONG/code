#include <math.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "graph.h"

int main(int argc, char *argv[]) {
  graph_adj grap;
  init_adjgraph(&grap, 14);

  create_edge_node_by_pait(0, 4, grap.adj_list);
  create_edge_node_by_pait(0, 5, grap.adj_list);
  create_edge_node_by_pait(0, 11, grap.adj_list);

  create_edge_node_by_pait(1, 2, grap.adj_list);
  create_edge_node_by_pait(1, 4, grap.adj_list);
  create_edge_node_by_pait(1, 8, grap.adj_list);

  create_edge_node_by_pait(2, 5, grap.adj_list);
  create_edge_node_by_pait(2, 6, grap.adj_list);
  create_edge_node_by_pait(2, 9, grap.adj_list);

  create_edge_node_by_pait(3, 2, grap.adj_list);
  create_edge_node_by_pait(3, 13, grap.adj_list);

  create_edge_node_by_pait(4, 7, grap.adj_list);

  create_edge_node_by_pait(5, 8, grap.adj_list);
  create_edge_node_by_pait(5, 12, grap.adj_list);

  create_edge_node_by_pait(6, 5, grap.adj_list);

  create_edge_node_by_pait(8, 7, grap.adj_list);

  create_edge_node_by_pait(9, 10, grap.adj_list);
  create_edge_node_by_pait(9, 11, grap.adj_list);

  create_edge_node_by_pait(10, 13, grap.adj_list);

  create_edge_node_by_pait(12, 9, grap.adj_list);

  print_adjgraph(&grap);

  if (topo_logic_sort(&grap) == true) {
    printf("NONE CYCLED DETECTED\n");
  } else {
    printf("CYCLED DETECTED");
  }

  destory_adjgraph(&grap);
  return EXIT_SUCCESS;
}
