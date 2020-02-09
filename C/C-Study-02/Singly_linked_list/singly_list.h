#ifndef __SINGLY_LIST_H__
#define __SINGLY_LIST_H__

typedef struct node {

	int data;
	struct node *next;
} node_t;

typedef struct list {

	node_t *head;
	node_t *tail;
	int size;
} list_t;



list_t *Create();
void AddNode(list_t *list, int data);
void ForeachAllNode(list_t *list);
void Free(list_t *list);
void Insert(list_t *list, int index, int data);
void Delete(list_t *list, int index);
void Reverse_List(list_t *list);

#endif // !__SINGLY_LIST_H__
