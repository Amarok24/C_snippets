#include <stdio.h> // printf, puts ...

int main()
{
  int *ptr = NULL; // assigning NULL manually to a pointer variable
  // int *ptr; // when no value is assigned, the compiler also assigns NULL

  // Print the memory address of `ptr`
  printf("%p\n", &ptr); // 0x7fffcfc5b9f0

  printf("%p\n", ptr); // (nil)
  printf("%x\n", ptr); // 0
  printf("%d\n", ptr); // 0

  if (ptr == NULL)
  {
    // true, so the following string will be printed
    printf("ptr is NULL\n");
  }

  if (ptr)
  {
    // a NULL value equals false, so this will not be printed
    printf("ptr is not NULL\n");
  }

  if (!ptr)
  {
    // true, because ptr is NULL which equals false, and !false == true
    printf("ptr is NULL\n");
  }

  // Trying to use a NULL pointer raises an error:

  // printf("%d\n", *ptr); // 939 segmentation fault (core dumped)

  return 0;
}
