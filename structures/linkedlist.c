/*
	Demo of a LIFO (last-in-first-out) queue (stack)
	with a simple linked list.
	TODO: CHECK AND FIX, DEMO NOT FINISHED
*/

#include <stdio.h>
#include <stdlib.h>

struct Node {
	int value;
	struct Node *next;
};

/* A shorthand type definition, to avoid typing "struct Node" each time.
	Now instead of "struct Node" we just type "Stack". */
typedef struct Node Stack;

/*
 * Pushes a new node on top of the stack.
 */
Stack *push(Stack *latest_node, int n)
{
	Stack *tmp_node;

	// TODO: casting to (Stack *) probably not needed??
	tmp_node = (Stack *)malloc(sizeof(Stack));

	if (tmp_node == NULL) {
		printf("Error: malloc in Stack push\n");
		exit(EXIT_FAILURE);
	}

	tmp_node->value = n;
	tmp_node->next = latest_node;

	return tmp_node;
}

void print_stack(Stack *first)
{
	Stack *tmp_node = first;

	if (first == NULL) {
		puts("First node is NULL, nothing to print\n");
		return;
	}

	printf("Printing stack now:\n");
	
	do {
		printf("%d ", tmp_node->value);
		tmp_node = tmp_node->next;
	} while (tmp_node != NULL);

	puts("\n");
}

void free_list(Stack *first)
{
	Stack *tmp_node;
	int i = 0;

	if (first == NULL) {
		puts("First node is NULL, nothing to free\n");
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
	struct Node *first_node = NULL;
	struct Node *tmp_node;
	int n;

	/* Let's create a linked list and insert 3 nodes at the beginning, which
	   will result in reversed order of the list. */

	/* allocating memory of size of the type/structure, not of pointer size */
	tmp_node = (struct Node *) malloc(sizeof(struct Node));

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

	tmp_node = (struct Node *)malloc(sizeof(struct Node));
	tmp_node->value = 20;
	tmp_node->next = first_node;
	first_node = tmp_node;

	tmp_node = (struct Node *)malloc(sizeof(struct Node));
	tmp_node->value = 30;
	tmp_node->next = first_node;
	first_node = tmp_node;

	print_stack(first_node);
	puts("------\n");

	/* inserting more nodes via user input */
	printf("Enter a series of integers, 0 to terminate\n? ");

	for (;;) {
		scanf("%d", &n);
		if (n == 0) break;
		first_node = push(first_node, n);
	}

	puts("\n\n");

	print_stack(first_node);

	puts("------\nFreeing memory...\n");
	free_list(first_node);
	puts("------\n");

	print_stack(first_node);
	// FIXME: Why are 2 numbers printed? For example: "0 6"

	return 0;
}
