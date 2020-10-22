#include <memory.h>
#include <stdbool.h>
#include <stdlib.h>

#include "graph.h"

/**
 * @brief 遍历边表，找到符合下标 idx 的元素，如果未找到，就证明该对组属于第一次录入
*/
bool verify_repeat(int idx, vertext_node *head) {
  bool flg = true;

  edge_node *nod = head->first_edge;
  while (true) {
    if (nod == NULL) break;

    if (nod->adj_vex_idx == idx) {
      flg = false;
      break;
    }

    nod = nod->next;
  }

  return flg;
}
void create_edge_node_by_pait(int i, int j, edge_type weight, vertext_node *adj_list) {
  if(adj_list == NULL) return;

  if (!verify_repeat(j, &adj_list[i])) {
    return;
  }

  edge_node *e_i = (edge_node *)malloc(sizeof(edge_node));
  e_i->adj_vex_idx = i;
  e_i->next = adj_list[j].first_edge;
  adj_list[j].first_edge = e_i;

  edge_node *e_j = (edge_node *)malloc(sizeof(edge_node));
  e_j->adj_vex_idx = j;
  e_j->next = adj_list[i].first_edge;
  adj_list[i].first_edge = e_j;
}

/* Form pic-7-4-7 */
void init_adjgraph(graph_adj *G) {
  memset(G, 0x0, sizeof(graph_adj));

  G->vertexs_num = 5;
  G->edges_num   = 6;
  
  G->adj_list[0].data = '0';
  G->adj_list[0].first_edge = NULL;
  G->adj_list[1].data = '1';
  G->adj_list[1].first_edge = NULL;
  G->adj_list[2].data = '2';  
  G->adj_list[2].first_edge = NULL;
  G->adj_list[3].data = '3';
  G->adj_list[3].first_edge = NULL;

  create_edge_node_by_pait(0, 1, 0, G->adj_list);
  create_edge_node_by_pait(0, 2, 0, G->adj_list);
  create_edge_node_by_pait(0, 3, 0, G->adj_list);
  create_edge_node_by_pait(1, 0, 0, G->adj_list);
  create_edge_node_by_pait(1, 2, 0, G->adj_list);
  create_edge_node_by_pait(2, 0, 0, G->adj_list);
  create_edge_node_by_pait(2, 1, 0, G->adj_list);
  create_edge_node_by_pait(2, 3, 0, G->adj_list);
  create_edge_node_by_pait(3, 0, 0, G->adj_list);
  create_edge_node_by_pait(3, 2, 0, G->adj_list);
}

void destory_adjgraph(graph_adj *G) {
  
}

