#ifndef __GRAPH_H__
#define __GRAPH_H__

#define MAXVEX 100          /* Max count of vertex */
#define G_INFINITY 65535    /* Max value of weight */

typedef char vertex_type;   /* Type of vertex, it's might should be defined by users */
typedef int edge_type;      /* Type of weight, it's might should be defined by users */

typedef struct {
  vertex_type vexs[9]; /* Table of vertex */
  edge_type arc[9][9]; /* Adjacency Matrix, can be seen as table of edge */
  int vertexs_num, edges_num;
} n_graph;

void init_graph(n_graph *G, int _vertexs_num, int _edges_num);
void create_edge_node_by_pait(int i, int j, edge_type weight, edge_type (*arc)[9]);
void DES_traverse(n_graph *G);
void BFS_traverse(n_graph *G);
void min_span_tree_prim(n_graph *_G);

#endif /* end of include guard: __GRAPH_H__ */
