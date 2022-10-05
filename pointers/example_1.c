#include <stdio.h>	// printf, puts ...

int main(void)
{
	unsigned int temperature = 30;
	unsigned int *ptr_temperature = &temperature;

	printf("%d\n", temperature);	// 30

	// Print the memory address of `temperature`
	printf("%p\n", (void*)&temperature);	// for example: 0x7fffe75fef8c

	printf("%p\n", (void*)ptr_temperature);	// 0x7fffe75fef8c, same as above
	
	// The following is probably the address of the pointer itself.
	printf("%p\n", (void*)&ptr_temperature);	// for example: 0x7fffe75fef80

	
	printf("%x\n", *ptr_temperature);	// 1e (== 30 in hex)
		   
	printf("%d\n", *ptr_temperature);	// 30

	printf("%d\n", *ptr_temperature);	// 30

	printf("%lu\n", sizeof(*ptr_temperature));	// 4 (32 bits), sizeof integer
	printf("%lu\n", sizeof(ptr_temperature));	// 8 (64 bits), sizeof pointer
	printf("%lu\n", sizeof(&ptr_temperature));	// 8 (64 bits), sizeof mem address

	return 0;
}
