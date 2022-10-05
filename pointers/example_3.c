#include <stdio.h>

int main(void)
{
	int number;	// gets initialised to 0
	int *ptr;	// gets initialised to a random mem address (0x7ffffffee160)
	int **pptr;	// pointer to pointer

	number = 300;

	ptr = &number;
	pptr = &ptr;

	printf("Value of number = %d\n", number);	// 300
	printf("Value available at *ptr = %d\n", *ptr);	// 300
	printf("Value available at **pptr = %d\n", **pptr);	// 300

	// It's OK to ignore the warning:
	// format `%p` expects argument of type `void *`,
	// but argument 2 has type `int *`
	printf("number is at address %p\n", &number);	// 0x7ffffffee06c

	// argument 2 has type `int *`
	printf("ptr points to %p\n", ptr);	// 0x7ffffffee06c

	// argument 2 has type `int **`
	printf("pptr points to %p\n", pptr);	// 0x7ffffffee060

	// argument 2 has type `int **` (POINTER TO POINTER)
	printf("ptr itself is at address %p\n", &ptr);	// 0x7ffffffee060

	// argument 2 has type `int ***` (POINTER TO POINTER TO POINTER)
	printf("pptr itself is at address %p\n", &pptr);	// 0x7ffffffee058

	printf("Everything makes sense!\n\n");
	
	return 0;
}

/*
OUTPUT:

Hello World
Value of number = 300
Value available at *ptr = 300
Value available at **pptr = 300
number is at address 0x7ffffffee06c
ptr points to 0x7ffffffee06c
pptr points to 0x7ffffffee060
ptr itself is at address 0x7ffffffee060
pptr itself is at address 0x7ffffffee058
Everything makes sense!

---------------------
From DEBUG watch at the end of the main function:

number: 300   address: 0x7ffffffee06c

ptr: 0x7ffffffee06c
 *ptr: 300

pptr: 0x7ffffffee060
 *pptr: 0x7ffffffee06c
  **pptr: 300

*/
