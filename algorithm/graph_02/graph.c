#include <memory.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>

#include "graph.h"
#include "queue.h"

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

/** 
 * @brief 该函数仅考虑无向图的创建，每一次依据所录入
 * 的 i 和 j 去构建两个节点的边表，故有可能会出现重复
 * 录入的情况，例如起始录入了 (1,0) 然后又录入了 (0,1)
 * ，这是允许出现的，因为对于无向图来说，它的边都是无向边
 * ，故都可以使用相反的表示方式，故该函数还要判断重复的处理
 * 问题
*/
void create_edge_node_by_pait(int i, int j, edge_type weight, vertext_node *adj_list) {
  if(adj_list == NULL) return;

  if (!verify_repeat(j, &adj_list[i])) {
    return;
  }

  edge_node *e_i = (edge_node *)malloc(sizeof(edge_node));
  printf("[INFO] create %p\n", e_i);
  e_i->adj_vex_idx = i;
  e_i->next = adj_list[j].first_edge;
  adj_list[j].first_edge = e_i;

  edge_node *e_j = (edge_node *)malloc(sizeof(edge_node));
  printf("[INFO] create %p\n", e_j);
  e_j->adj_vex_idx = j;
  e_j->next = adj_list[i].first_edge;
  adj_list[i].first_edge = e_j;
}

/* Form pic-7-4-7 */
void init_adjgraph(graph_adj *G) {
  memset(G, 0x0, sizeof(graph_adj));

  G->vertexs_num = 4;
  G->edges_num   = 5;
  
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

static bool visted[5];

void DES(int i, vertext_node *adj_list) {
  visted[i] = true;
  printf("[info] search: %c\n", adj_list[i].data);

  edge_node *cur = adj_list[i].first_edge;
  while (cur) {
    if (!visted[cur->adj_vex_idx]) 
      DES(cur->adj_vex_idx, adj_list);

    cur = cur->next;
  }
}

void DES_traverse(graph_adj *G) {
  memset(visted, false, sizeof(visted));

  for (size_t i = 0; i < G->vertexs_num; ++i) {
    if (visted[i]) continue;
    DES(i, G->adj_list);
  }
}

void BFS(int _i, graph_adj *_G, Queue *_queue) {
  visted[_i] = true;
  printf("[info] search :%d\n", _i);

  AddQ(_queue, _i);
  PrintQueue(_queue);

  while (!IsEmptyQ(_queue)) {
    _i = DeleteQ(_queue);
    edge_node *cur = _G->adj_list[_i].first_edge;

    while (cur) {
      if(!visted[cur->adj_vex_idx]) {
        visted[cur->adj_vex_idx] = true;
        printf("[info] search :%d\n", cur->adj_vex_idx);
        AddQ(_queue, cur->adj_vex_idx);
        PrintQueue(_queue);
      }
      cur = cur->next;
    }
  }
}

void BFS_traverse(graph_adj *_G) { 
  memset(visted, false, sizeof(visted));

  /* 初始化队列 */
  Queue *queue = CreateQueue();

  for (size_t i = 0; i < _G->vertexs_num; ++i) {
    if (visted[i]) continue;
    BFS(i, _G, queue);
  }
}

void destory_adjgraph(graph_adj *G) {
  for (size_t i = 0; i < G->vertexs_num; ++i) {
    edge_node *cur = G->adj_list[i].first_edge;
    edge_node *tmp;
    while (true) {
      if (cur == NULL) break;

      tmp = cur->next;
      free(cur);
      printf("[INFO] delete %p\n", cur);
      cur = tmp;
    }
  } 
}
