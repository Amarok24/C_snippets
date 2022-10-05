#include <stdio.h>
#include <stdlib.h> // "exit" codes for return

/*
 * Both macros are the same
 */
#define ARRAY_LENGTH(x) ((sizeof x) / (sizeof *x))
#define ARRAY_LENGTH2(x) (sizeof(x) / sizeof((x)[0]))

enum DataTypeList {
	t_char,
	t_int,
	t_float_pointer,
	t_int_array
};

void processData(void *userData, size_t length, enum DataTypeList type)
{
	size_t i;

	printf("\n---------\nprocessData here. Given length is %ld\n\n", length);

	switch (type) {
	case t_char:
		puts("processing t_char");
		/*
		 * passed argument is really a pointer to char, here is the proof:
		 */
		printf("First character: %c\n", *((char *)userData));

		/*
		 * and we can make use of C's special treatment of strings,
		 * casting to a char, but not dereferencing it, but using as a
		 * string
		 */
		printf("Whole string: %s\n", ((char *)userData));
		break;

	case t_int:
		puts("processing t_int");

		printf("Integer value: %d\n", *((int *)userData));
		break;

	case t_float_pointer:
		puts("processing t_float_pointer");
		printf("Float value: %f\n", *((float *)userData));
		break;

	case t_int_array:
		puts("processing t_int_array");
		printf("First array index: %d\n", *((int *)userData));
		printf("array length is %ld\n", length);
		puts("Now looping through:");

		for (i = 0; i < length; i++) {
			printf("%d ", *((int *)userData));
			userData += sizeof(int); // incrementing RAM address by 1 integer
			/* FIXME:
				gcc gives a warning: pointer of type `void *` used in arithmetic
			*/
		}

		printf("\n");

		break;

	default:
		puts("invalid DataTypeList");
		break;
	}
}

int main(void)
{
	int year;

	// When defining a fixed-length array, C knows its size using `sizeof`.
	int year_list[] = {1956, 1970, 2012};
	
	float temperature, *fp;

	enum DataTypeList custom_type = t_char;

	/*
	 * The name of an array[] actually specifies a pointer to the first
	 * element in the array, so `message` is a char pointer because [] is
	 * used!!!
	 */

	/* When defining a fixed-length array, C knows its size using `sizeof`.
		That's also true for `char` type.
	*/
	char message[] = "User message.";
	/* 1 char is 1 byte, so length is 13 + 1 (null character)
	 *
	 * Passing a pointer `message` as the first argument. `sizeof message`
	 * works, because we have defined it with fixed values and `char` is 1 byte.
	 * Then such a string is a "char pointer array" in C. See also year_list.
	 * Notice that we don't pass it as a variable, we pass it as a pointer.
	 */
	processData(message, sizeof message, custom_type);
	// Absolutely the same result here:
	processData(message, ARRAY_LENGTH(message), custom_type);


	year = 2022;
	custom_type = t_int;
	/*
	 * Because `year` is not a pointer, we have to pass it as a pointer
	 * (as an address). `sizeof year` will be the size of integer type (4).
	 */
	processData(&year, sizeof year, custom_type);


	temperature = 24.5f;
	fp = &temperature;
	/*
	 * An `enum` value can also be used directly as an argument.
	 */
	processData(fp, sizeof(*fp), t_float_pointer);

	/*
	 * `sizeof year_list` is 12 (3 * 4 bytes), which is currently
	 * not of much help here, so we better use the macro ARRAY_LENGTH.
	 */
	printf("sizeof year_list is %lu\n", sizeof year_list);
	
	processData(year_list, ARRAY_LENGTH(year_list), t_int_array);

#ifdef DEBUG
	puts("DEBUG defined in source code");
#endif

	return EXIT_SUCCESS;
}

/*

---------
processData here. Given length is 14

processing t_char
First character: U
Whole string: User message.

---------
processData here. Given length is 14

processing t_char
First character: U
Whole string: User message.

---------
processData here. Given length is 4

processing t_int
Integer value: 2022

---------
processData here. Given length is 4

processing t_float_pointer
Float value: 24.500000
sizeof year_list is 12

---------
processData here. Given length is 3

processing t_int_array
First array index: 1956
array length is 3
Now looping through:
1956 1970 2012 
DEBUG defined in source code

*/
