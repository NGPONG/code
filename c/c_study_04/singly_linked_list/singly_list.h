#ifndef __SINGLY_LIST_H__
#define __SINGLY_LIST_H__

typedef struct node {

	void *data;
	struct node *next;
} node_t;

typedef struct list {

	node_t *head;
	node_t *tail;
	int size;
} list_t;



list_t *create();
void add_node(list_t *list, void *data);
void foreach_all_node(list_t *list, void (*invoker)(node_t *));
void free_list(list_t *list);
void insert(list_t *list, int index, void *data);
void delete(list_t *list, int index);
void reverse_list(list_t *list);

#endif // !__SINGLY_LIST_H__
