#ifndef __SET_H__
#define __SET_H__

#include <string.h>
#include <stdbool.h>
#include <stdio.h>

#define VERTICES 6

static int parent[6] = { 0 }; /* The idx of arrary is each of vertexs, and value is parent idx of current vertex */ 
static int rank[6] = { 0 };   /* Record the rank of edges */

int find_root_normal(int f);
bool union_set_rank(int x, int y);
void initialise_disjoint_set();
void find_cycle_in_graph(void);

#endif /* end of include guard: __SET_H__ */
