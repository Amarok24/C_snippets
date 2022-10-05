#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "array_struct.h"

int main(void)
{
	IntArray arr;
	FloatArray squareRoots;
	unsigned int i;

	arr.size = 6;
	arr.data = malloc(arr.size * sizeof(*arr.data));

	squareRoots.size = 10;
	squareRoots.data = malloc(squareRoots.size * sizeof(*squareRoots.data));

	for (i = 0; i < arr.size; i++)
		arr.data[i] = i * 10;

	for (i = 0; i < arr.size; i++)
		printf("%d ", arr.data[i]);

	// 0 10 20 30 40 50

	printf("\n");

	for (i = 0; i < squareRoots.size; i++)
		squareRoots.data[i] = sqrt(i);

	for (i = 0; i < squareRoots.size; i++)
		printf("%f ", squareRoots.data[i]);

	// 0.000000 1.000000 1.414214 1.732051 2.000000 2.236068 2.449490 2.645751 2.828427 3.000000

	printf("\n");

	free(arr.data);
	free(squareRoots.data);

	return 0;
}
