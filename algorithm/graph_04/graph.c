#include "graph.h"

#include <stdbool.h>
#include <string.h>

void create_edge_node_by_pait(int i, int j, edge_type weight, edge_type (*arc)[9]) {
	arc[i][j] = weight;
}

void init_graph(n_graph *G, int _vertexs_num, int _edges_num) {
  memset(G, 0x0, sizeof(n_graph));

  G->vertexs_num = _vertexs_num;
  G->edges_num   = _edges_num;

  /* 初始化顶点表 */
  char ascii_start = '0';
  for (size_t i = 0; i < G->vertexs_num; ++i) {
    G->vexs[i] = ascii_start;
    ++ascii_start;
  }

  /* 初始化邻接矩阵中所有元的默认值，默认为正无穷 */
  for (int i = 0; i < G->vertexs_num; ++i) {
    for (int j = 0; j < G->vertexs_num; ++j) {
      if (i != j) 
        G->arc[i][j] = G_INFINITY;
      else
        G->arc[i][j] = 0;
    }
  }
}

void shortest_path_floyd(n_graph *G) {
  int P[G->vertexs_num][G->vertexs_num];
  int D[G->vertexs_num][G->vertexs_num];
  for (size_t v = 0; v < G->vertexs_num; ++v) {
    for (size_t w = 0; w < G->vertexs_num; ++w) {
      P[v][w] = w;
      D[v][w] = G->arc[v][w];
    }
  }
  
  for (size_t i = 0; i < G->vertexs_num; ++i) {
    for (size_t v = 0; v < G->vertexs_num; ++v) {
      for (size_t w = 0; w < G->vertexs_num; ++w) {
        if (D[v][w] > D[v][i] + D[i][w]) {
          D[v][w] = D[v][i] + D[i][w];
          P[v][w] = P[v][i];
        }
      }
    }
  }

  for (int v = 0; v < G->vertexs_num; ++v) {
    for (int w = v + 1; w < G->vertexs_num; ++w) {
      printf("v%d - v%d weight: %d\n", v, w, D[v][w]);
      int k = P[v][w];
      printf(" path: %d", v);
      while (w != k) {
        printf(" -> %d", k);
        k = P[k][w];
      }
      printf(" -> %d\n", w);
    }
    printf("\n");
  }
}
