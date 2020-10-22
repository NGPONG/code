#include "graph.h"

#include <string.h>

/** 
 * @brief Init a new graph, it's created with reference to Figure 7-4-4 in the book
*/
void init_graph(n_graph *G) {
  memset(G, 0x0, sizeof(n_graph));

  G->vertexs_num = 5;
  G->edges_num   = 6;

  /* 初始化顶点表 */
  G->vexs[0] = '0';
  G->vexs[1] = '1';
  G->vexs[2] = '2';
  G->vexs[3] = '3';
  G->vexs[4] = '4';
  G->vexs[5] = '5';

  /* 初始化邻接矩阵中所有元的默认值，默认为正无穷 */
  for (int i = 0; i < G->vertexs_num; ++i) {
    for (int j = 0; j < G->vertexs_num; ++j) {
      int val = 0;
      if (i != j) val = G_INFINITY;

      G->arc[i][j] = val;
    }
  }
    
  /* 初始化网的权 */
  G->arc[0][4] = 6;
  G->arc[1][0] = 9;
  G->arc[1][2] = 3;
  G->arc[2][0] = 2;
  G->arc[2][3] = 5;
  G->arc[3][4] = 1;
}