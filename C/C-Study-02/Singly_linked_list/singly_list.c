#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdio.h>

#include "singly_list.h"

list_t *Create() {

	list_t *list = malloc(sizeof(list_t));
	if (list == NULL) {
	
		perror("heap out");
		return NULL;
	}
	memset(list, 0, sizeof(list_t));

	return list;
}

void AddNode(list_t *list, void *data) {

	if (list == NULL) {
	
		return;
	}

	// create a new node
	node_t *node = malloc(sizeof(node_t));
	if (node == NULL) {
	
		perror("heap error");
		return;
	}
	node->data = data;
	node->next = NULL;

	if (list->head == NULL) {
	
		list->head = list->tail = node;
	}
	else {
	
		list->tail->next = node;
		list->tail = node;
	}

	list->size++;
}

void ForeachAllNode(list_t *list,void (*invoker)(node_t *)) {

	if (list == NULL || list->head == NULL) {

		return;
	}

	node_t *current = list->head;
	while (1) {

		invoker(current);

		if ((current = current->next) == NULL) {
			
			printf("foreach ended******************************************\n");
			printf("head address = %p\n", list->head);
			printf("tail address = %p\n", list->tail);
			printf("list address = %p\n", list);
			printf("list size = %d\n\n", list->size);
			break;
		}
	}
}

void Insert(list_t *list, int index, void *data) {

	if (list == NULL) {
	
		return;
	}

	node_t *node = malloc(sizeof(node_t));
	if (node == NULL) {
	
		return;
	}

	node->data = data;
	node->next = NULL;

	if (index < 0) {
	
		return;
	}
	else if (index == 0) {

		node->next = list->head;
		list->head = node;
	}
	else if (index > list->size - 1) {
	
		list->tail->next = node;
		list->tail = node;
	}
	else {
	
		node_t *node_bef = list->head;
		for (size_t i = 0; i < index - 1; i++) {

			node_bef = node_bef->next;
		}

		node_t *node_aft = node_bef->next;
		node_bef->next = node;
		node->next = node_aft;
	}

	list->size++;
}

void Delete(list_t *list, int index) {

	if (list == NULL || list->head == NULL || list->tail == NULL) {

		return;
	}

	if (index < 0) {

		return;
	}
	else if (index == 0) {
	
		node_t *head = list->head;
		printf("delete and free %p\n", head);

		list->head = list->head->next;
		if (list->size == 1) {

			list->tail = list->head;
		}
		free(head);
	}
	else if (index >= list->size - 1) {
	
		node_t *node_current = list->head;
		if (node_current->next == NULL) {
		
			printf("delete and free %p\n", node_current);
			free(node_current);
			list->head = NULL;
			list->tail = NULL;
			list->size--;
			return;
		}


		while (1) {

			if (node_current->next == list->tail) {
				
				break;
			}

			node_current = node_current->next;
		}

		node_t *tail = list->tail;
		printf("delete and free %p\n", tail);
		list->tail = node_current;
		list->tail->next = NULL;
		free(tail);
	}
	else {
	
		node_t *node_aft = list->head;
		for (size_t i = 0; i < index - 1; i++) {

			node_aft = node_aft->next;
		}

		node_t *node_prev = node_aft->next->next;
		
		printf("delete and free %p\n", node_aft->next);
		free(node_aft->next);

		node_aft->next = node_prev;
	}


	list->size--;
}

void Reverse_List(list_t *list) {

	if (list == NULL) {
	
		return;
	}

	node_t *prev = NULL;
	node_t *next = NULL;
	node_t *current = list->head;
	for (size_t i = 0; i < list->size; i++) {

		next = current->next;

		current->next = prev;

		// move
		prev = current;
		current = next;
	}

	node_t *temp = list->head;
	list->head = list->tail;
	list->tail = temp;
}

void Free(list_t *list) {

	node_t *current = list->head;
	node_t *next_temp;
	while (1) {

		if ((next_temp = current->next) == NULL) {

			printf("free node address = %p, Data address = %p\n", list->tail, list->tail->data);
			free(list->tail->data);
			free(list->tail);
			break;
		}

		printf("free node address = %p, Data address = %p\n", current, current->data);
		free(current->data);
		free(current);

		current = next_temp;
	}

	printf("free list address = %p\n", list);
	free(list);
}