#include <memory.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>

#include "graph.h"

void create_edge_node_by_pait(int i, int j, vertext_node *ort_list) {
  if(ort_list == NULL) return;

  /* 初始化入边表的信息 */
  edge_node *e = (edge_node *)malloc(sizeof(edge_node));
  printf("[INFO] create %p\n", e);
  e->head_idx = j;
  e->next_head = ort_list[i].first_in;
  ort_list[i].first_in = e;

  /* 初始化出边表信息 */
  e->tail_idx = i;
  e->next_tail = ort_list[j].first_out;
  ort_list[j].first_out = e;
}

void init_ort_graph(graph_ort *G) {
  memset(G, 0x0, sizeof(graph_ort)); /* 初始化 */

  /* 以书中的图 7-4-10 的存储结构进行初始化 */
  G->vertexs_num = 4;
  G->edges_num   = 5;

  char ascii_start = '0';
  for (size_t i = 0; i < G->vertexs_num; ++i) {
    G->ort_list[i].data = ascii_start;
    ++ascii_start;
  }

  create_edge_node_by_pait(2, 1, G->ort_list);
  create_edge_node_by_pait(2, 0, G->ort_list);
  create_edge_node_by_pait(1, 2, G->ort_list);
  create_edge_node_by_pait(1, 0, G->ort_list);
  create_edge_node_by_pait(0, 3, G->ort_list);
}
