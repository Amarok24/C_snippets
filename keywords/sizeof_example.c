/* C99 */
#include <stdio.h>
#include <stdbool.h>

int main(void)
{
	float pi = 3.14;
	float *ptr;

	puts("Different sizeof tests:");

	/*
	   `sizeof` is a built-in keyword, not a function, however when
	   checking size of a built-in data type, we need to write it as sizeof(type)
	 */

	printf("bool: %lu byte\n", sizeof(bool));	/* 1, == unsigned char */

	printf("char: %lu byte\n", sizeof(char));	/* 1 */
	/* In C, character literals such as 'a' have type int,
	   and thus sizeof('a') is equal to sizeof(int). */
	printf("'a': %lu byte\n", sizeof 'a');	/* 4 */

	printf("int: %lu bytes\n", sizeof(int));	/* 4 */
	printf("long: %lu bytes\n", sizeof(long));	/* 8 */
	printf("float: %lu bytes\n", sizeof(float));	/* 4 */
	printf("double: %lu bytes\n", sizeof(double));	/* 8 */

	printf("float variable: %lu bytes\n", sizeof pi);	/* 4 */
	printf("float ptr variable: %lu bytes\n", sizeof * ptr);	/* 4 */

	return 0;
}
