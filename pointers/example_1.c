#include <stdio.h> // printf, puts ...

int main()
{
  unsigned int temperature = 24;
  unsigned int *ptrTemperature = &temperature;

  printf("%d\n", temperature); // 24

  // Print the memory address of `temperature`
  printf("%p\n", &temperature); // for example: 0x7fffe75fef8c

  // Attention, the following has an address shifted by minus 12,
  // probably because of internal representation of an integer pointer?
  printf("%p\n", &ptrTemperature); // for example: 0x7fffe75fef80

  printf("%p\n", ptrTemperature); // 0x7fffe75fef8c
  printf("%x\n", ptrTemperature); // e75fef8c (hex address stripped of first 2 bytes)
  printf("%d\n", ptrTemperature); // -413143156 (like above, but as signed! integer)

  printf("%d\n", *ptrTemperature); // 24

  return 0;
}
