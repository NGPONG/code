#ifndef __GRAPH_H__
#define __GRAPH_H__

#define MAXVEX 100          /* Max count of vertex */
#define G_INFINITY 65535    /* Max value of weight */

typedef char vertex_type;   /* Type of vertex, it's might should be defined by users */
typedef int edge_type;      /* Type of weight, it's might should be defined by users */

typedef struct {
  vertex_type vexs[5]; /* Table of vertex */
  edge_type arc[5][5]; /* Adjacency Matrix, can be seen as table of edge */
  int vertexs_num, edges_num;
} n_graph;

void init_graph(n_graph *G);

#endif /* end of include guard: __GRAPH_H__ */
