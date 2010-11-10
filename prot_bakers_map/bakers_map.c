#include <stdlib.h>

#include "bakers_map.h"

extern int size;
extern int matrix[4][4];

void
bakers_map_matrix_init(void)
{
	int i, j;

	for (i = 0; i < size; i++)
	{
		for (j = 0; j < size; j++)
		{
			matrix[i][j] = 1;
		}
	}
}

void
bakers_map_transform(void)
{

}
