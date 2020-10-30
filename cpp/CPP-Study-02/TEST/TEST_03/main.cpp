/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2012-2018. All rights reserved.
 * Description: 项目 City Road 的源文件
 * Author: c00518290
 * Create: 2019-08-05
 */
#include <stdio.h>
#include <iostream>

using namespace std;

int parent[1002];

int main() {
  int n, m, a, b;
  int count = 0;
  scanf("%d %d", &n, &m);

  int list[n + 1];
  for (int i = 1; i <= n; i++) {
    list[i] = i;
  }

  for (int i = 0; i < m; i++) {
    scanf("%d %d", &a, &b);

    /* 寻找根节点 */
    while (list[a] != a) {
      a = list[a];
    }
    while (list[b] != b) {
      b = list[b];
    }
    
    /* 合并，如果不属于两个集合内 */
    if (list[b] != list[a]) {
      list[b] = list[a];
    }
  }

  for (int i = 1; i <= n; i++) {
    if (list[i] == i)
      count++;
  }
  printf("%d\n", count - 1);
}


/**
5 2
1 2
3 5
**/
