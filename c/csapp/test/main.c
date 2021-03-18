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
  /* 假设 node list 已初始化完毕 */
  t_node *list = 0x6032d0;
  /* 模拟 0x20(%rsp,%rsi,2) 所分配的栈帧空间 */
  t_node *nodes[6] = { 0 };

  t_node *rdx = list;
  for (int rsi = 0; rsi < 6; ++rsi) {
    int rcx = arr[rsi];
    if (rcx > 1) {
      int rax = 1;
      while (rax != rcx) {
        rdx = rdx->next;
        ++rax;
      }
    }

    nodes[rsi] = rdx->next;
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
  /* 0x4011d2 */
  
  t_node *rbx = nodes[0];
  
  

  return EXIT_SUCCESS;
}
