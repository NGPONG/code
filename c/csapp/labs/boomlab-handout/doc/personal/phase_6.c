#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  long data;
  struct node *next;
} t_node;

int main(int argc, char *argv[]) {
  int arr[6] = { 1, 2, 3, 4, 5 ,6 };
  
  /**
   * 1. 校验所输入的六个数字是否不大于 6
   * 2. 所输入的六个数字不能存在相同的任意一个
  */
  /* 0x401114 */
  int *r13 = arr;
  for (int r12 = 0; r12 < 6; ++r12) {
    /* 0x401117 ~ 0x401123 */
    if ((*r13 - 1) > 5) {
      return EXIT_FAILURE;
    }

    int rbx = r12 + 1;
    while (rbx <= 5) {
      if (arr[rbx] == *r13) {
        return EXIT_FAILURE;
      }

      ++rbx;
    }
    r13 += 1;
  }
  /* 0x401151 */
  
  /* 将所输入的六个数字都和 7 相减并将结果写回到各自所存在的存储空间当中 */
  /* 0x401153 */
  int *rsi = arr + sizeof(arr); /* end pointer */
  int *rax = arr;
  while (rax == rsi) {
    *arr = 7 - *arr;
  }
  /* 0x40116d */


  /* 0x40116f */

  /**
   * 假设 node list 已初始化完毕.
   *  see: x/12xg 0x6032d0
  */
  t_node *list = 0x6032d0;

  /**
   * 所分配的用于存储 list 节点内存地址的栈帧空间.
   *  see: x/6xg rsp + 0x20
  */
  t_node *nodes[6] = { 0 };

  for (int rsi = 0; rsi < 6; ++rsi) {
    t_node *rdx = list;

    int rcx = arr[rsi];
    if (rcx > 1) {
      int rax = 1;
      while (rax != rcx) {
        rdx = rdx->next;
        ++rax;
      }
    }

    4 3 2 1 6 5

    nodes[rsi] = rdx;
  }
  /* 0x4011a9 */
  
  /* 0x4011ab */ 
  /**
   * 该段循环遍历上一段代码段中所构造的存储 6 个节点的栈空间，其
   * 中，每一个栈空间中所存储的节点指针改变其 next 的指向，指向为
   * 当前栈段空间的下一块空间中所存储的节点指针，最后一块栈空间会
   * 所存储的节点其指向直接初始化为 NULL
  */
  t_node *end = nodes + 7;

  t_node *rcx = nodes[0];
  t_node **rax = &nodes[1];
  while (true) {
    t_node *rdx = *rax;
    rcx->next = rdx;

    rax += 1;
    if (rax == end) {
      break;
    }

    rcx = rdx;
  }
  nodes[6]->next = NULL;
  /* 0x4011d9 */
  
  
  /* 0x4011da */
  /**
   * 最后一段代码，就是对比 list 空间中的每一个节点，要求当前遍
   * 历到的节点其数据域要大于 next 指向节点的 数据域.
  */
  t_node *rbx = nodes[0];
  /* 0x4011f5 */
  

  return EXIT_SUCCESS;
}
