#include <stdio.h> /* printf */

int main()
{
	unsigned char uc = 230;
	float f = 7.6;
	void *vp = NULL; /* void (untyped) pointer, initialised to NULL */

	float *fp = &f;
	float *fpCopy = fp; /* a copy of a pointer assignment, without `&` */

	vp = &uc;

	/* !!!
		The data pointed to by a void pointer canNOT be directly dereferenced,
		because we have no type to dereference to. We always have to cast the
		address in the void pointer to some other pointer type, that points to
		a concrete data type before dereferencing it.

		printf("%d", *vp); // WRONG, ERROR
	 */

	/* Casting the address in the void pointer to some other pointer type and
	then dereferencing it: */
	printf("voidpointer -> signed char (byte) = %d\n", *((char *)vp));
	printf("voidpointer -> unsigned char (byte) = %d\n", *((unsigned char *)vp));

	vp = &f;

	printf("voidpointer -> float = %f\n\n", *((float *)vp));

	printf("fp (simple float pointer) = %f\n", *fp);
	printf("fpCopy = %f\n", *fpCopy);

	return 0;
}
/*
voidpointer -> signed char (byte) = -26
voidpointer -> unsigned char (byte) = 230
voidpointer -> float = 7.600000

fp (simple float pointer) = 7.600000
fpCopy = 7.600000
*/
