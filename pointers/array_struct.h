/*
 size_t is an unsigned long, commonly used for index access,
 under the hood it's simply:
	 typedef unsigned long size_t
*/

typedef struct
{
	size_t size;
	char *data;
} CharArray;

typedef struct
{
	size_t size;
	unsigned char *data;
} UCharArray;

typedef struct
{
	size_t size;
	int *data;
} IntArray;

typedef struct
{
	size_t size;
	unsigned int *data;
} UIntArray;

typedef struct
{
	size_t size;
	long *data;
} LongArray;

typedef struct
{
	size_t size;
	unsigned long *data;
} ULongArray;

typedef struct
{
	size_t size;
	float *data;
} FloatArray;

typedef struct
{
	size_t size;
	double *data;
} DoubleArray;
