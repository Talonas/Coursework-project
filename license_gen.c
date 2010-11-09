#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "license_gen.h"
#include "file.h"

static char *file_name;
static int size = 4;

static void prepare(void);
static void add(int *matrix);

static void
prepare(void)
{
	file_name = "license";
	file_reset(file_name);
	file_add_int(file_name, size);
}

void
generate(int mode)
{
	int i, j;
	int *matrix;

	prepare();

	matrix = malloc(sizeof(matrix[0]) * size * size);
	for (i = 0; i < size; i++)
	{
		for (j = 0; j < size; j++)
		{
			matrix[i * size + j] = 1;
		}
	}
	matrix[1 * size + 2] = mode;

	add(matrix);
}

static void
add(int *matrix)
{
	int i, j;

	for (i = 0; i < size; i++)
	{
		for (j = 0; j < size; j++)
		{
			file_add_int(file_name, matrix[i * size + j]);
		}
	}
}
