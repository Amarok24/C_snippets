#include <stdio.h>	/* printf, puts ... */
#include <stdlib.h> /* malloc, exit */

int main()
{
	int arrSize = 10;
	/* allocating memory for 10 integers (which becomes an array) */
	int *intPointer = malloc(arrSize * sizeof *intPointer);
	int i;
	size_t sizeInBytes;

	for (i = 0; i < arrSize; i++)
	{
		intPointer[i] = i;
	}

	/* this is probably useless, because it gives the size of pointer implementation, which is 64 bits (8 bytes) */
	sizeInBytes = sizeof intPointer;

	printf("intPointer sizeInBytes = %d\n", sizeInBytes); /* 8 */

	/* dereferencing pointer, sizeof now returns the size of integer (32 bits) */
	sizeInBytes = sizeof *intPointer;
	/* the following is exactly the same, but NOT a preferred way to write it */
	sizeInBytes = sizeof(*intPointer);

	printf("sizeInBytes = %d\n", sizeInBytes); /* 4 */

	for (i = 0; i < arrSize; i++)
	{
		printf("%d ", intPointer[i]);
		/* prints  0 1 2 3 4 5 6 7 8 9 */
	}

	/* intPointer is still just one integer pointer, not a true array */
	*intPointer = 555;
	/* the following is exactly the same as previous assignment! */
	intPointer[0] = 555;

	/* dereferencing intPointer */
	i = *intPointer;

	printf("\n\nfirst element of intPointer is now = %d\n", i); /* 555 */

	for (i = 0; i < arrSize; i++)
	{
		printf("%d ", intPointer[i]);
		/* prints  555 1 2 3 4 5 6 7 8 9  */
	}

	printf("\n-----\n");
	free(intPointer);
	return 0;
}

/*
intPointer sizeInBytes = 8
sizeInBytes = 4
0 1 2 3 4 5 6 7 8 9 

first element of intPointer is now = 555
555 1 2 3 4 5 6 7 8 9
-----
*/
