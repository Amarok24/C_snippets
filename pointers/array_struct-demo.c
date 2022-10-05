#include <stdio.h>		/* printf */
#include <stdlib.h>		/* malloc */
#include <math.h>

#include "array_struct.h"

int main(void)
{
	IntArray arr;
	FloatArray square_roots;
	size_t i;
	/*
	 size_t is commonly used for index access, it's the return type of `sizeof`.
	 In <stddef.h> it's simply one of these definitions:
		 typedef unsigned int size_t;  (32-bit systems)
		 typedef unsigned long size_t; (64-bit systems)
	*/

	arr.size = 6;
	arr.data = malloc(arr.size * sizeof(*arr.data));

	square_roots.size = 10;
	square_roots.data = malloc(square_roots.size * sizeof(*square_roots.data));

	for (i = 0; i < arr.size; i++)
		arr.data[i] = i * 10;

	for (i = 0; i < arr.size; i++)
		printf("%d ", arr.data[i]);

	printf("\n");

	for (i = 0; i < square_roots.size; i++)
		square_roots.data[i] = sqrt(i);

	for (i = 0; i < square_roots.size; i++)
		printf("%f ", square_roots.data[i]);

	printf("\n");

	free(arr.data);
	free(square_roots.data);

	return 0;
}

/*
OUTPUT:

0 10 20 30 40 50
0.000000 1.000000 1.414214 1.732051 2.000000 2.236068 2.449490 2.645751 2.828427 3.000000

*/
