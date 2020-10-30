#include <math.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define VERTICES 6

int parent[6] = { 0 }; /* The idx of arrary is each of vertexs, and value is parent idx of current vertex */ 
int rank[6] = { 0 };   /* Record the rank of edges */


/* @breif 找到当前顶点的最上级根节点 */
int find_root(int f) {
  if (parent[f] == f) { /* 在初始情况下，我们初始化 parent 每个下标所对应的值为顶点本身 */
    return f;
  }

  /**
   * 如果顶点的父节点并不是顶点本身(初始化情况下)，
   * 那么就继续沿着其所对应的父结点继续向上递归搜索，直至找到根
  */
  return find_root(parent[f]);
}

/* @breif 合并两个顶点至一个集合内，有可能会合并失败，这种情况则为两个顶点本身就属于一个集合内 */
bool union_set(int x, int y) {
  int x_root = find_root(x);
  int y_root = find_root(y);

  if (x_root == y_root) {
    return false;
  }

  /** 
   * 为了保证树的生成并不会退化成单向长链表而导致 parent 查找过程的复杂度会线性提升的情景，这
   * 里引入了 Rank 的概念
   * 
   * - 当两颗树(已经合并了的两个暂时不相交的集合)的深度不同时，如果将较深的树合并至较浅的树中
   *   时，整颗树的深度都会比原有较深的树 +1，反之则不变
   * - 当两颗树的深度是相同的时候，这里想象出唯有一个顶点的情景，这时候进行合并，不管是由谁作
   *   为父结点都无所谓，但是要保证作为父结点的那颗树其对应根的深度要 +1
  */
  if (rank[x_root] > rank[y_root]) {
    parent[y_root] = x_root;
  } else if (rank[y_root] < rank[x_root]) {
    parent[x_root] = y_root;
  } else {
    parent[x_root] = y_root;
    ++rank[y_root];
  }

  return true;
}

void initialise_disjoint_set() {
  /* rank */
  memset(rank, 0x0, sizeof(rank));

  /* parent_set */
  for (size_t i = 0; i < VERTICES; ++i) {
    parent[i] = i;
  }
}

int main(int argc, char *argv[]) {
  /**
   * 这里本应该拥有一个创建图且初始化图的过程，但是
   * 这里省略掉了，仅模拟出已经查找出图中所有的边
  */
  int edges[VERTICES][2] = {
    { 0, 1 }, { 1, 2 }, { 1, 3 }, 
    { 2, 4 }, { 3, 4 }, { 2, 5 }
  };

  initialise_disjoint_set();

  /**
   * 逐个合并图中的所有的边，也就是两个顶点之间不断进行合并 
   * 对于存在环的图来说(不考虑相同边的情况)，如果合并时存在
   * 两个不同的顶点属于同一个集合内(union_set返回false)，那
   * 么这个集合所构成的图中，任意两点的连线都可以构成一个环
  */
  for (size_t i = 0; i < VERTICES; ++i) {
    int x = edges[i][0];
    int y = edges[i][1];

    if (!union_set(x, y)) {
      printf("Cycle detected\n");
      return EXIT_SUCCESS;
    }
  }
  printf("None cycle\n");

  return EXIT_SUCCESS;
}
