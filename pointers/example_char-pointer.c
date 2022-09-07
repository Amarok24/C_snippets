#include <stdio.h>
#include <string.h>

char *strtest(char *a, char *b);

int main()
{
	char a[256], b[256], c[256];
	char *cptr;

	strcpy(a, "STRING A");
	strcpy(b, "STRING B");
	strcpy(c, "STRING C");

	printf("Initial values of strings:\n");
	printf("\n");
	printf("   a = %s\n", a); // STRING A
	printf("   b = %s\n", b); // STRING B
	printf("   c = %s\n", c); // STRING C
	printf("\n");

	// strcpy returns a char pointer
	cptr = strcpy(c, strtest(a, b));

	printf("   cptr = %s\n\n", cptr); // NEWSTRING C, 12345

	printf("Final values of strings:\n");
	printf("\n");
	printf("   a = %s\n", a); // STRING A
	printf("   b = %s\n", b); // NEWSTRING B, 112233
	printf("   c = %s\n", c); // NEWSTRING C, 12345
	printf("\n");

	return 0;
}

char *strtest(char *x, char *y)
{
	printf("Values passed to function:\n");
	printf("\n");
	printf("   x = %s\n", x); // STRING A
	printf("   y = %s\n", y); // STRING B
	printf("\n");

	strcpy(y, "NEWSTRING B, 112233"); // writes directly into passed char *y
	return "NEWSTRING C, 12345";
}

/*
OUTPUT:

Initial values of strings:

	 a = STRING A
	 b = STRING B
	 c = STRING C

Values passed to function:

	 x = STRING A
	 y = STRING B

	 cptr = NEWSTRING C, 12345

Final values of strings:

	 a = STRING A
	 b = NEWSTRING B, 112233
	 c = NEWSTRING C, 12345

*/
