#include <stddef.h>

typedef struct {
	size_t size;
	char *data;
} CharArray;

typedef struct {
	size_t size;
	unsigned char *data;
} UCharArray;

typedef struct {
	size_t size;
	short int *data;
} ShortArray;

typedef struct {
	size_t size;
	unsigned short int *data;
} UShortArray;

typedef struct {
	size_t size;
	int *data;
} IntArray;

typedef struct {
	size_t size;
	unsigned int *data;
} UIntArray;

typedef struct {
	size_t size;
	long int *data;
} LongArray;

typedef struct {
	size_t size;
	unsigned long int *data;
} ULongArray;

typedef struct {
	size_t size;
	float *data;
} FloatArray;

typedef struct {
	size_t size;
	double *data;
} DoubleArray;
