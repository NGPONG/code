#include "graph.h"

#include <stdbool.h>
#include <string.h>

void create_edge_node_by_pait(int i, int j, edge_type (*arc)[5]) {
	arc[i][j] = 1;
}

void init_graph(n_graph *G) {
  memset(G, 0x0, sizeof(n_graph));

  G->vertexs_num = 5;
  G->edges_num   = 6;

  /* 初始化顶点表 */
  char ascii_start = '0';
  for (size_t i = 0; i < G->vertexs_num; ++i) {
    G->vexs[i] = ascii_start;
    ++ascii_start;
  }

  /* 初始化邻接矩阵中所有元的默认值，默认为正无穷 */
  for (int i = 0; i < G->vertexs_num; ++i) {
    for (int j = 0; j < G->vertexs_num; ++j) {
      int val = 0;
      if (i != j) val = 0;

      G->arc[i][j] = val;
    }
  }
}

bool visted[5] = { false };

void DES(int i, n_graph *G) {
  visted[i] = true;
  printf("[info] search: %c\n", G->vexs[i]);

  for (size_t j = 0; j < G->vertexs_num; ++j) {
    if (G->arc[i][j] && !visted[j]) {
      DES(j, G);
    }
  }
}

void DES_traverse(n_graph *G) {
  for (size_t i = 0; i < G->vertexs_num; ++i) {
    if (visted[i]) continue;

    DES(i, G);
  }
}