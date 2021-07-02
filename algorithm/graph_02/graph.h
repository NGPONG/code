#ifndef __HEAD_H__FILE
#define __HEAD_H__FILE

typedef char vertext_type;
typedef int edge_type;

/* 边表节点 */
typedef struct edge_node {
  int adj_vex_idx;        /* 邻接点域，存储该顶点所对应的下标 */
  edge_type weight;       /* 权值 */
  struct edge_node *next; /* 指向下一个邻接点 */
} edge_node;

/* 顶点表节点 */
typedef struct {
  vertext_type data;
  edge_node *first_edge;
} vertext_node;


/* 图结构 */
typedef struct {
  vertext_node adj_list[4];
  int vertexs_num;
  int edges_num;
} graph_adj;


void init_adjgraph(graph_adj *G);
void destory_adjgraph(graph_adj *G);
void DES_traverse(graph_adj *G);
void BFS_traverse(graph_adj *_G);

#endif /* end of include guard: __HEAD_H__FILE */
