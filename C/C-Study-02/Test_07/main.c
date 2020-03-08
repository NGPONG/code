#include <stdio.h>
#include <stdlib.h>
//����״̬�������
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2
//Status�Ǻ��������ͣ���ֵ�Ǻ������״̬����
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

//������������ʼ��
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

//����������������
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

//Ϊ�������������ͷ��㣬ʹ֮����˫�����
Status InOrderThreading(BiThrTree *Thrt, BiThrTree T) {
    if (!(*Thrt = (BiThrTree)malloc(sizeof(BiThrNode)))) exit(OVERFLOW);
    (*Thrt)->LTag = Link;
    (*Thrt)->RTag = Thread;
    (*Thrt)->rchild = (*Thrt);
    if (!T) {
        (*Thrt)->lchild = (*Thrt);
        return OK;       //������㲻����,��ö�����Ϊ��,�ø�ͷ���ָ������.
    }
    BiThrTree pre;
    //��ͷ������ָ��ָ������
    pre = NULL;
    (*Thrt)->lchild = T;
    //��ʼ�ݹ�����������
    InThreading(T, &pre);
    //��ʱ���������һ��������������,����Ĵ����ͷ���ĺ��ָ�������һ�����.
    //�������һ�����ĺ��Ҳָ��ͷ���,��ʱ����Ϊ��һ������˫�������ѭ��.
    pre->rchild = *Thrt;
    pre->RTag = Thread;
    (*Thrt)->rchild = pre;
    return OK;
}

//�ǵݹ��������������
Status InOrderTraverse(BiThrTree T) {
    BiThrNode *p = T->lchild;
    while (p != T) {
        while (p->LTag == Link) p = p->lchild;    //�����������ľ�ͷ
        printf("%c", p->data);
        while (p->RTag == Thread && p->rchild != T) {  //���ʸý��ĺ������
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
    printf("��������������Ľ��Ϊ��");
    InOrderTraverse(T);
    printf("\n");
}
