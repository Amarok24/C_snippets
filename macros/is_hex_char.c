#include <stdio.h>
#include <ctype.h> // isxdigit

#define CASE_NUMBER \
  case '0': \
  case '1': \
  case '2': \
  case '3': \
  case '4': \
  case '5': \
  case '6': \
  case '7': \
  case '8': \
  case '9':

#define CASE_HEX_AF_LOWER \
  case 'a': \
  case 'b': \
  case 'c': \
  case 'd': \
  case 'e': \
  case 'f':

#define CASE_HEX_AF_UPPER \
  case 'A': \
  case 'B': \
  case 'C': \
  case 'D': \
  case 'E': \
  case 'F':

// hex digits (/[0-9a-fA-F]/)
#define CASE_HEX \
  CASE_NUMBER \
  CASE_HEX_AF_LOWER \
  CASE_HEX_AF_UPPER

// C already has a similar built-in function: isxdigit
int ishexchar(const char c)
{
	switch (c) {
		CASE_HEX
		return 1;

	default:
		return 0;
	}
}

int main(void)
{
	char c = 'f';

	if (ishexchar(c))
		printf("%c is a valid hex character\n", c);
	else
		printf("%c is NOT a valid hex character\n", c);

	c = 'g';

	if (ishexchar(c))
		printf("%c is a valid hex character\n", c);
	else
		printf("%c is NOT a valid hex character\n", c);

	c = '5';

	if (isxdigit(c))
		printf("%c is a valid hex character\n", c);
	else
		printf("%c is NOT a valid hex character\n", c);


	return 0;
}

/*
f is a valid hex character
g is NOT a valid hex character
5 is a valid hex character 
*/
