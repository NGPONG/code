#ifndef __HEAD_H__FILE
#define __HEAD_H__FILE

#include <stdbool.h>
#include "stack.h"

typedef char vertext_type;
typedef int edge_type;

typedef struct edge_node {
  int adj_vex_idx;        /* 邻接点域，存储该顶点所对应的下标 */
  struct edge_node *next; /* 指向下一个邻接点 */
} edge_node;


typedef struct {
  vertext_type data;
  int in;
  edge_node *first_edge;
} vertext_node;


typedef struct {
  vertext_node adj_list[14];
  int vertexs_num;
  int edges_num;
} graph_adj;


void create_edge_node_by_pait(int i, int j, vertext_node *adj_list);
void init_adjgraph(graph_adj *G, int _vertexs_num);
void destory_adjgraph(graph_adj *G);
void print_adjgraph(graph_adj *G);
bool topo_logic_sort(graph_adj *grap);

#endif /* end of include guard: __HEAD_H__FILE */
