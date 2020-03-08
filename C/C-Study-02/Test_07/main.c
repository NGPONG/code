#include <stdio.h>
#include <stdlib.h>
//函数状态结果代码
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2
//Status是函数的类型，其值是函数结果状态代码
typedef int Status;
typedef char TElemType;

typedef enum { Link, Thread } PointerTag;

typedef struct BiThrNode {
    TElemType data;
    struct BiThrNode *lchild, *rchild;
    PointerTag LTag;
    PointerTag RTag;
}BiThrNode, *BiThrTree;

static size_t index_Preorder = 0;
static TElemType Binary_Tree_Data[] = {
    'A','B','D','H','#','K','#','#','#','E','#','#',
    'C','F','I','#','#','#','G','#','J','#','#' };

//线索二叉树初始化
Status CreateBiThrNode(BiThrTree *B) {

    TElemType ch = Binary_Tree_Data[index_Preorder++];
    if (ch == '#') {

        *B = NULL;
    }
    else {
        if (!((*B) = (BiThrNode *)malloc(sizeof(BiThrNode)))) exit(OVERFLOW);
        (*B)->data = ch;
        (*B)->LTag = Link;
        (*B)->RTag = Link;
        CreateBiThrNode(&(*B)->lchild);
        CreateBiThrNode(&(*B)->rchild);
    }
    return OK;
}

//线索二叉树线索化
void InThreading(BiThrTree B, BiThrTree *pre) {
    if (!B) return;

    InThreading(B->lchild, pre);

    if (!B->lchild) {
        B->LTag = Thread;
        B->lchild = *pre;
    }

    if (!(*pre)->rchild) {
        (*pre)->RTag = Thread;
        (*pre)->rchild = B;
    }

    *pre = B;
    InThreading(B->rchild, pre);
}

//为线索二叉树添加头结点，使之可以双向操作
Status InOrderThreading(BiThrTree *Thrt, BiThrTree T) {
    if (!(*Thrt = (BiThrTree)malloc(sizeof(BiThrNode)))) exit(OVERFLOW);
    (*Thrt)->LTag = Link;
    (*Thrt)->RTag = Thread;
    (*Thrt)->rchild = (*Thrt);
    if (!T) {
        (*Thrt)->lchild = (*Thrt);
        return OK;       //若根结点不存在,则该二叉树为空,让该头结点指向自身.
    }
    BiThrTree pre;
    //令头结点的左指针指向根结点
    pre = NULL;
    (*Thrt)->lchild = T;
    //开始递归输入线索化
    InThreading(T, &pre);
    //此时结束了最后一个结点的线索化了,下面的代码把头结点的后继指向了最后一个结点.
    //并把最后一个结点的后继也指向头结点,此时树成为了一个类似双向链表的循环.
    pre->rchild = *Thrt;
    pre->RTag = Thread;
    (*Thrt)->rchild = pre;
    return OK;
}

//非递归遍历线索二叉树
Status InOrderTraverse(BiThrTree T) {
    BiThrNode *p = T->lchild;
    while (p != T) {
        while (p->LTag == Link) p = p->lchild;    //走向左子树的尽头
        printf("%c", p->data);
        while (p->RTag == Thread && p->rchild != T) {  //访问该结点的后续结点
            p = p->rchild;
            printf("%c", p->data);
        }
        p = p->rchild;
    }
    return OK;
}

int main() {
    BiThrTree B, T;
    CreateBiThrNode(&B);
    InOrderThreading(&T, B);
    printf("中序遍历二叉树的结果为：");
    InOrderTraverse(T);
    printf("\n");
}
