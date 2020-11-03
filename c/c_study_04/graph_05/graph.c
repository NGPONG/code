#include "graph.h"

void create_edge_node_by_pait(int i, int j, vertext_node *adj_list) {
  edge_node *e = (edge_node *)malloc(sizeof(edge_node));
  e->adj_vex_idx = j;
  e->next = adj_list[i].first_edge;
  adj_list[i].first_edge = e;

  ++adj_list[j].in;
}

void init_adjgraph(graph_adj *G, int _vertexs_num) {
  memset(G, 0x0, sizeof(graph_adj));

  G->vertexs_num = _vertexs_num;

  char val = '0';
  for (size_t i = 0; i < _vertexs_num; ++i) {
    G->adj_list[i].data = val;
    G->adj_list[i].in = 0;
    G->adj_list[i].first_edge = NULL;

    ++val;
  }
}

void print_adjgraph(graph_adj *grap) {
  for (size_t i = 0; i < grap->vertexs_num; ++i) {
    printf("|%d|V%c|", grap->adj_list[i].in, grap->adj_list[i].data);
    edge_node *node = grap->adj_list[i].first_edge;
    while (node) {
      printf(" -> |%d|", node->adj_vex_idx);
      node = node->next;
    }
    printf("\n");
  }
  
}

bool topo_logic_sort(graph_adj *grap) {
  bool status = true;
  
  int count = 0; /* 统计纳为拓补序列的顶点个数，当该值小于图中
                    顶点个数的和时，则证明无法生成拓补序列 */
  struct Stack *stack = Init_Stack();

  /* 寻找是否存在入度为0的节点，如果存在，则入栈 */
  for (size_t i = 0; i < grap->vertexs_num; ++i) {
    if (grap->adj_list[i].in == 0) {
      Push(stack, (char)i);
    }
  }

  while (stack->s_size) {
    int vex = Pop(stack);

    printf("%d ", vex);
    ++count;

    for (edge_node *node = grap->adj_list[vex].first_edge; node; node = node->next) {
      int k = node->adj_vex_idx;
      if ((--grap->adj_list[k].in) == 0) {
        Push(stack, (char)k);
      }
    }
  }

  if (count < grap->vertexs_num) { /* 存在环 */
    status = false;
  }

  Destory(stack);
  return status;
}

void destory_adjgraph(graph_adj *G) {
  for (size_t i = 0; i < G->vertexs_num; ++i) {
    edge_node *cur = G->adj_list[i].first_edge;
    edge_node *tmp;
    while (true) {
      if (cur == NULL) break;

      tmp = cur->next;
      free(cur);
      cur = tmp;
    }
  } 
}
