#include <stdio.h>	// printf, puts ...

int main(void)
{
	int *ptr = NULL;	// assigning NULL manually to a pointer variable
	// int *ptr; // when no value is assigned, the compiler also assigns NULL

	// Print the memory address of `ptr`
	printf("%p\n", (void*)&ptr); // 0x7fffe49e7c88

	printf("%p\n", (void*)ptr);  // (nil)
	

	// dereferencing invalid pointer (if it's NULL) would
	// throw a "segmentation fault" error:
	
	// printf("%d\n", *ptr); // ERROR, segmentation fault
	

	if (ptr == NULL) {
		// true, so the following string will be printed
		printf("ptr is NULL\n");
	}

	if (ptr) {
		// a NULL value is `false`, so this will not be printed
		printf("ptr is not NULL\n");
	}

	if (!ptr) {
		// true, because ptr is NULL
		printf("ptr is NULL\n");
	}

	return 0;
}

/*

0x7fffe49e7c88
(nil)
ptr is NULL
ptr is NULL

*/
