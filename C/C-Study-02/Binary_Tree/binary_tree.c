#include "binary_tree.h"
#include "stack.h"

/*
 * Inorder create binary-tree can complete the
 * construction of the tree under the model that
 * does not know the tree
 *
 * We use scanf function to complete the data field entry.
 * When the received character is '#', it proves that the current
 * node belongs to an NULL state
 */
static size_t index_Preorder = 0;
static ElementType_t Binary_Tree_Data[] = {
	'A','B','D','H','#','K','#','#','#','E','#','#',
	'C','F','I','#','#','#','G','#','J','#','#' };
int Preorder_Create_BinaryTree(Binary_Tree **tree, Binary_Tree *parent) {

	ElementType_t ch = Binary_Tree_Data[index_Preorder++];
	if (ch == '#') {

		return -1;
	}
	else {

		*tree = (Binary_Tree *)malloc(sizeof(Binary_Tree));
		if (*tree == 0x0) {

			return -1;
		}
		memset(*tree, 0x0, sizeof(Binary_Tree));

		(*tree)->data = ch;
		(*tree)->parent = parent;
		printf("[+] Create Binary-node: Node-Value = %c, Node-Address = %p, Parent-value = %c, Parent-Address = %p\n",
			(*tree)->data,
			*tree,
			(*tree)->parent == NULL ? '-' : (*tree)->parent->data,
			(*tree)->parent);

		Preorder_Create_BinaryTree(&(*tree)->left, *tree);
		Preorder_Create_BinaryTree(&(*tree)->right, *tree);
	}

	return 0;
}

/* Perfect Binary Tree
 *                                (A)
 *                                 |
 *                 o---------------+---------------o
 *                 |                               |
 *                (B)                             (C)
 *                 |                               |
 *          o------+-----o                  o------+-----o
 *          |            |                  |            |
 *         (D)          (E)                (F)          (G)
 *          |            |                  |            |
 *      o---+---o    o---+---o          o---+---o    o---+---o
 *      |       |    |       |          |       |    |       |
 *     (H)     (I)  (J)     (K)        (L)     (M)  (N)     (O)
 *
 *
 *   Don't direct Postorder create binary-tree, but we can find the last
 *   node is root, and previous node is right-child for root, and pre-previous
 *   node is left-child for root..... So, we can create binary tree like this.
 */
static size_t index_Postorder = 0;
static ElementType_t Perfect_BinaryTree_data[] = { 'A',																		 /* ROOT */
											'B', 'D', 'H', '#', '#', 'I', '#', '#', 'E', 'J', '#', '#', 'K', '#', '#',		 /* LEFT */
											'C', 'F', 'L', '#', '#', 'M', '#', '#', 'G', 'N', '#', '#', 'O', '#', '#' };	 /* RIGHT */
Binary_Tree *Postorder_Create_BinaryTree(Binary_Tree *parent) {

	ElementType_t ch = Perfect_BinaryTree_data[index_Postorder++];
	if (ch == '#') {

		return NULL;
	}
	else {

		Binary_Tree *tree = (Binary_Tree *)malloc(sizeof(struct binary_node));
		if (tree == 0x0) {

			return -1;
		}
		memset(tree, 0, sizeof(struct binary_node));

		tree->left = Postorder_Create_BinaryTree(tree);
		tree->right = Postorder_Create_BinaryTree(tree);

		tree->data = ch;
		tree->parent = parent;
		printf("[+] Create Binary-node: Node-Value = %c, Node-Address = %p, Parent-Address = %p\n",
			tree->data,
			tree,
			tree->parent);

		return tree;
	}
}

int Preorder_Traverse_BinaryTree_WithoutRecursion(Binary_Tree *tree) {

	if (tree == 0x0)
		return -1;

	struct Stack *stack = Init_Stack();

	/* 1st Step: Push the root element into stack */
	Push(stack, tree);

	/* Start traverse - Preorder */
	while (1) {

		/* End of traverse means all tree node was accessed */
		if (stack->s_size == 0) {
		
			break;
		}

		/*
		 * We need to pop the top element in stack at first time,
		 * When the member flag is 1, it means that this element needs to be output
		 */
		StackElement *element = Pop(stack);
		if (element->tag == 1) {
		
			printf("\n[*] Traverse Binary-tree: Value = %c, Address = %p\n\n", element->data, element);
			element->tag = 0;

			continue;
		}
		else {
		
			element->tag = 1;
			if (element->right != NULL) {
			
				Push(stack, element->right);
			}
			if (element->left != NULL) {

				Push(stack, element->left);
			}
			/* Put the element that just popped on the top of the stack again */
			Push(stack, element);

			continue;
		}
	}

	Destory(stack);
}

int Preorder_Traverse_BinaryTree(Binary_Tree *tree) {

	if (tree == 0x0)
		return -1;

	printf("[*] Traverse Binary-tree: Value = %c, Address = %p\n", tree->data, tree);
	Preorder_Traverse_BinaryTree(tree->left);
	Preorder_Traverse_BinaryTree(tree->right);

	return 0;
}

int Postorder_Traverse_BinaryTree(Binary_Tree *tree) {

	if (tree == 0x0)
		return -1;

	Postorder_Traverse_BinaryTree(tree->left);
	Postorder_Traverse_BinaryTree(tree->right);
	printf("[*] Traverse Binary-tree: Value = %c, Address = %p\n", tree->data, tree);

	return 0;
}

int Middorder_Traverse_BinaryTree(Binary_Tree *tree) {

	if (tree == 0x0)
		return -1;

	Middorder_Traverse_BinaryTree(tree->left);
	printf("[*] Traverse Binary-tree: Value = %c, Address = %p\n", tree->data, tree);
	Middorder_Traverse_BinaryTree(tree->right);

	return 0;
}

int Postorder_Free_BinaryTree(Binary_Tree **tree) {

	if (*tree == 0x0)
		return -1;

	Postorder_Free_BinaryTree(&(*tree)->left);
	Postorder_Free_BinaryTree(&(*tree)->right);

	printf("[-] Free Binary-node: Data = %c, Address = %p\n", (*tree)->data, *tree);
	free(*tree);
	*tree = NULL;

	return 0;
}

/* The deep for Binary-Tree */
int BinaryTree_Deep(struct binary_node *node) {

	int deep = 0;

	if (node != NULL) {

		int leftdeep = BinaryTree_Deep(node->left);
		int rightdeep = BinaryTree_Deep(node->right);

		/*
		 * Get a deeper value of the left or right subtrees,
		 * plus one to add the depth of the current node
		 */
		deep = leftdeep >= rightdeep ? leftdeep + 1 : rightdeep + 1;
	}

	return deep;
}

