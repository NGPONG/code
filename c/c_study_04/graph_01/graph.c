#include "graph.h"
#include "queue.h"

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

static bool visted[5];

void DES(int _i, n_graph *_G) {
  visted[_i] = true;
  printf("[info] search: %c\n", _G->vexs[_i]);

  for (size_t j = 0; j < _G->vertexs_num; ++j) {
    if (_G->arc[_i][j] && !visted[j]) {
      DES(j, _G);
    }
  }
}

void DES_traverse(n_graph *_G) {
  memset(visted, false, sizeof(visted));

  for (size_t i = 0; i < _G->vertexs_num; ++i) {
    if (visted[i]) continue;
    DES(i, _G);
  }
}

void BFS(int _i, n_graph *_G, Queue *_queue) {
  visted[_i] = true;
  printf("[info] search :%d\n", _i);

  AddQ(_queue, _i);
  PrintQueue(_queue);

  while (!IsEmptyQ(_queue)) {
    _i = DeleteQ(_queue);
    for (int j = 0; j < _G->vertexs_num; ++j) {
      if(_G->arc[_i][j] == 1 && !visted[j]) {
        visted[j] = true;
        printf("[info] search :%d\n", j);
        AddQ(_queue, j);
        PrintQueue(_queue);
      }
    }
  }
}

void BFS_traverse(n_graph *_G) { 
  memset(visted, false, sizeof(visted));

  /* 初始化队列 */
  Queue *queue = CreateQueue();

  for (size_t i = 0; i < _G->vertexs_num; ++i) {
    if (visted[i]) continue;
    BFS(i, _G, queue);
  }
}