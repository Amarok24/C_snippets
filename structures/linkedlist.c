/*
	Demo of a LIFO (last-in-first-out) queue (stack)
	with a simple linked list.
	TODO: CHECK AND FIX, DEMO NOT FINISHED
*/

#include <stdio.h>
#include <stdlib.h>

struct Stack {
	int value;
	struct Stack *next;
};

/*
 * Pushes a new node on top of the stack.
 */
struct Stack *push(struct Stack *node_ptr, int n)
{
	struct Stack *tmp_node;

	tmp_node = malloc(sizeof(struct Stack));

	if (tmp_node == NULL) {
		printf("Error: malloc in Stack push\n");
		exit(EXIT_FAILURE);
	}

	tmp_node->value = n;
	tmp_node->next = node_ptr;

	return tmp_node;
}

void print_stack(struct Stack *first)
{
	struct Stack *tmp_node = first;

	if (first == NULL) {
		puts("First node is NULL, nothing to print\n");
		return;
	}

	do {
		printf("%d ", tmp_node->value);
		tmp_node = tmp_node->next;
	} while (tmp_node != NULL);

	puts("\n");
}

void free_list(struct Stack *first)
{
	struct Stack *tmp_node;
	int i = 0;

	if (first == NULL) {
		puts("first node is NULL, nothing to free\n");
		return;
	}

	do {
		tmp_node = first;
		first = first->next;
		free(tmp_node);
		i++;
	} while (first != NULL);

	printf("%d nodes freed from memory\n", i);
}

int main(void)
{
	struct Stack *first_node = NULL;
	struct Stack *tmp_node;
	int n;

	/* Let's create a linked list and insert 3 nodes at the beginning, which
	   will result in reversed order of the list. */

	/* allocating memory of size of the type/structure, not of pointer size */
	tmp_node = malloc(sizeof(struct Stack));

	(*tmp_node).value = 10;

	/*
	   The following is the same, using the -> operator ("right arrow selection").
	   The -> operator is a combination of "*" and ".", which means it must not be
	   explicitly dereferenced, that's done by the compiler!

	   tmp_node->value = 10;

	   The "right arrow selection" syntax could be used in scanf like this:

	   scanf("%d", &tmp_node->value);
	 */

	(*tmp_node).next = NULL;	/* This could also be ... = first_node (it's NULL) */
	first_node = tmp_node;

	tmp_node = malloc(sizeof(struct Stack));
	tmp_node->value = 20;
	tmp_node->next = first_node;
	first_node = tmp_node;

	tmp_node = malloc(sizeof(struct Stack));
	tmp_node->value = 30;
	tmp_node->next = first_node;
	first_node = tmp_node;

	print_stack(first_node);
	puts("------\n");

	/* inserting more nodes via user input */
	printf("Enter a series of integers, 0 to terminate\n? ");

	for (;;) {
		scanf("%d", &n);

		if (n == 0)
			break;

		first_node = push(first_node, n);
	}

	puts("\n\n");

	print_stack(first_node);
	puts("------\n");

	free_list(first_node);
	puts("------\n");

	print_stack(first_node);

	return 0;
}
