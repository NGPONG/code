#pragma warning(disable:6031)
#pragma warning(disable:4996)			

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <Windows.h>

#include "binary_tree.h"


int CreateAnNewRow(int printLine) {

	putchar('\n');

	if (printLine)
		printf("-------------------------------------------------------\n");
	else {

		putchar('\n');putchar('\n');putchar('\n');
	}

	putchar('\n');
}

int main(void) {

	Binary_Tree *binaryTree = NULL;
	Preorder_Create_BinaryTree(&binaryTree, NULL);
	CreateAnNewRow(1);
	Preorder_Traverse_BinaryTree(binaryTree);
	CreateAnNewRow(1);
	printf("Deepth of Pre_binaryTree is %d\n", BinaryTree_Deep(binaryTree));
	CreateAnNewRow(1);
	Preorder_Traverse_BinaryTree_WithoutRecursion(binaryTree);
	CreateAnNewRow(1);
	Postorder_Free_BinaryTree(&binaryTree);

	CreateAnNewRow(0);

	Binary_Tree *binaryTree_Post = Postorder_Create_BinaryTree(NULL);
	CreateAnNewRow(1);
	Postorder_Traverse_BinaryTree(binaryTree_Post);
	CreateAnNewRow(1);
	printf("Deepth of Post_binaryTree is %d\n", BinaryTree_Deep(binaryTree_Post));
	CreateAnNewRow(1);
	Postorder_Free_BinaryTree(&binaryTree_Post);

	system("pause");
	return EXIT_SUCCESS;
}