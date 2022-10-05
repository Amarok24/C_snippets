#include <stdio.h>
#include <stdbool.h>

int main()
{
	float pi = 3.14;
	float *ptr;

	puts("Variables of built-in types and corresponding sizes:");

	/*
	   `sizeof` is a built-in keyword, not a function, however when
	   checking size of a built-in data type, we need to write it as sizeof(type)
	 */

	printf("bool: %d byte\n", sizeof(bool));	/* 1, == unsigned char */
	printf("char: %d byte\n", sizeof(char));	/* 1 */
	printf("int: %d bytes\n", sizeof(int));	/* 4 */
	printf("long: %d bytes\n", sizeof(long));	/* 8 */
	printf("float: %d bytes\n", sizeof(float));	/* 4 */
	printf("double: %d bytes\n", sizeof(double));	/* 8 */

	printf("float variable: %d bytes\n", sizeof pi);	/* 4 */
	printf("float ptr variable: %d bytes\n", sizeof *ptr);	/* 4 */

	return 0;
}
