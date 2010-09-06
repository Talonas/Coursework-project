#include <stdio.h>
#include <stdlib.h>

#include "protection.h"
#include "file.h"
#include "catmap.h"

static int values[5][5] = {
	{4, 1, 1, 1, 1},
	{1, 2, 2, 2, 2},
	{3, 3, 3, 3, 3},
	{4, 4, 4, 4, 4},
	{5, 5, 5, 5, 5}
};

static int size = 5;
static int steps = 4;
static char file_name[] = "test";

void
protection_generate()
{
	int i, j;

	file_reset(file_name);
	file_add_int(file_name, size);
	for (i = 0; i < size; i++)
	{
		for (j = 0; j < size; j++)
		{
			file_add_int(file_name, values[i][j]);
		}
	}
}
