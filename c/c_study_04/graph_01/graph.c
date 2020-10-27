#include "graph.h"
#include "queue.h"

#include <stdbool.h>
#include <string.h>

void create_edge_node_by_pait(int i, int j, edge_type weight, edge_type (*arc)[9]) {
	arc[i][j] = weight;
}

void init_graph(n_graph *G, int _vertexs_num, int _edges_num) {
  memset(G, 0x0, sizeof(n_graph));

  G->vertexs_num = _vertexs_num;
  G->edges_num   = _edges_num;

  /* 初始化顶点表 */
  char ascii_start = '0';
  for (size_t i = 0; i < G->vertexs_num; ++i) {
    G->vexs[i] = ascii_start;
    ++ascii_start;
  }

  /* 初始化邻接矩阵中所有元的默认值，默认为正无穷 */
  for (int i = 0; i < G->vertexs_num; ++i) {
    for (int j = 0; j < G->vertexs_num; ++j) {
      if (i != j) 
        G->arc[i][j] = G_INFINITY;
      else
        G->arc[i][j] = 0;
    }
  }
}

static bool visted[5];

void DES(int _i, n_graph *_G) {
  visted[_i] = true;
  printf("[info] search: %c\n", _G->vexs[_i]);

  for (size_t j = 0; j < _G->vertexs_num; ++j) {
    if(!visted[j] &&
       _G->arc[_i][j] != 0 &&
       _G->arc[_i][j] != G_INFINITY) {
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
      if(!visted[j] &&
         _G->arc[_i][j] != 0 &&
         _G->arc[_i][j] != G_INFINITY) {
        visted[j] = true;
        printf("[info] search :%d\n", j);
        AddQ(_queue, j);
        PrintQueue(_queue);
      }
    }
  }
}

void BFS_traverse(n_graph *G) { 
  memset(visted, false, sizeof(visted));

  /* 初始化队列 */
  Queue *queue = CreateQueue();

  for (size_t i = 0; i < G->vertexs_num; ++i) {
    if (visted[i]) continue;
    BFS(i, G, queue);
  }
}

void min_span_tree_prim(n_graph *G) {
  int adj_vexs[G->vertexs_num]; /* 保存顶点的下标 */
  int low_cast[G->vertexs_num]; /* 保存权值，它的下标所对应的值和 adj_vexs 所相呼应
                                    并且该数组所对应的下标为0的时候，也意味着该下标的顶
                                    点已经被纳入至最小生成树当中 */

  low_cast[0] = 0; /* 设最小生成树从0顶点开始，也就是说在最开始的时候，顶点0就被纳入到最小生成树当中去了 */
  adj_vexs[0] = 0;

  /* 依照第一个顶点(0)的那一行中的所有的值都初始化 */
  for (size_t i = 1; i < G->vertexs_num; ++i) {
    adj_vexs[i] = 0;
    low_cast[i] = G->arc[0][i];
  }

  /**
   * 以下的循环至始至终都要过滤掉顶点为 0 的，因为它在最
   * 开始的时候已经被纳入到最小生成树了，故需要跳过进行判断
 */
  for (size_t i = 1; i < G->vertexs_num; ++i) {
    int k = 0;
    int min = G_INFINITY;
    /* 从 low_cast 专门用于保存权值的数组中筛选出一个最小值 */
    for (size_t j = 1; j < G->vertexs_num; ++j) {
      if(low_cast[j] != 0 && low_cast[j] < min) {
        min = low_cast[j];
        k = j;
      }
    }

    /* 最小值的顶点纳入到最小生成树当中 */
    printf("(%d, %d)\n", adj_vexs[k], k);
    low_cast[k] = 0;

    /* 初始化 low_cast，从第 k 行初始化 */
    for (size_t j = 1; j < G->vertexs_num; ++j) {
      if(low_cast[j] != 0 && G->arc[k][j] < low_cast[j]) { /* 这一步: G->arc[k][j] < low_cast[j]，意味着可能会覆
                                                              盖掉，但是仔细想想看，该算法是查找最小的权，故覆盖掉是合理的 */
        low_cast[j] = G->arc[k][j];
        adj_vexs[j] = k;
      }
    }
  }
}



typedef struct
{
	int begin;
	int end;
	int weight;
} Edge;

void swapn(Edge *edges, int i, int j) {
  int temp;
  temp = edges[i].begin;
  edges[i].begin = edges[j].begin;
  edges[j].begin = temp;
  temp = edges[i].end;
  edges[i].end = edges[j].end;
  edges[j].end = temp;
  temp = edges[i].weight;
  edges[i].weight = edges[j].weight;
  edges[j].weight = temp;
}

void sort(Edge edges[], n_graph *G) {
  for (int i = 0; i < G->vertexs_num; i++) {
    for (int j = i + 1; j < G->vertexs_num; j++) {
      if (edges[i].weight > edges[j].weight) {
        swapn(edges, i, j);
      }
    }
  }
}

int find(int *parent, int f) {
  while (parent[f] > 0) 
    f = parent[f];

  return f;
}

void min_span_tree_kruskal(n_graph *G) {
  Edge edges[G->edges_num];
  int parent[G->vertexs_num];

  /* 用来构建边集数组并排序********************* */
  int k = 0;
  for (int i = 0; i < G->vertexs_num - 1; i++) {
    for (int j = i + 1; j < G->vertexs_num; j++) {
      if (G->arc[i][j] < G_INFINITY) {
        edges[k].begin = i;
        edges[k].end = j;
        edges[k].weight = G->arc[i][j];
        k++;
      }
    }
  }
  sort(edges, G);
  /* ******************************************* */

  for (size_t i = 0; i < G->vertexs_num; ++i) {
    parent[i] = 0;
  }

  for (size_t i = 0; i < G->vertexs_num; ++i) {
    int n = find(parent, edges[i].begin);
    int m = find(parent, edges[i].end);

    if(n != m) {
      parent[n] = m;
      printf("(%d, %d)\n", edges[i].begin, edges[i].end);
    }
  }
}