#ifndef __HEAD_H__FILE
#define __HEAD_H__FILE

typedef char vertext_type;
typedef int edge_type;

/* 边表节点 */
typedef struct edge_node {
  int tail_idx;                /* 出边表的邻接节点域 */
  struct edge_node *next_tail; /* 指向出边表的下一个邻接点 */
  
  int head_idx;                /* 入边表的邻接节点域 */
  struct edge_node *next_head; /* 指向入边表的下一个邻接点 */
} edge_node;


/* 顶点表节点 */
typedef struct {
  vertext_type data;
  edge_node *first_out; /* 对应着出边表 */
  edge_node *first_in;  /* 对应着入边表 */
} vertext_node;


/* 图结构 */
typedef struct {
  vertext_node ort_list[4];
  int vertexs_num;
  int edges_num;
} graph_ort;


void init_ort_graph(graph_ort *G);

#endif /* end of include guard: __HEAD_H__FILE */
