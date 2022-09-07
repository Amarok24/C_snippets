#include <stdio.h> // printf, puts ...

int main()
{
	unsigned char uc = 230;
	float f = 7.6;
	void *p; // void (untyped) pointer

	float *fp = &f;
	float *fpCopy = fp; // a copy of a pointer assignment, without `&`

	p = &uc;

	// type casting of a void pointer:
	printf("voidpointer -> signed char (byte) = %d\n", *( (char *)p ));
	printf("voidpointer -> unsigned char (byte) = %d\n", *( (unsigned char *)p ));

	p = &f;

	printf("voidpointer -> float = %f\n\n", *( (float *)p ));

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
