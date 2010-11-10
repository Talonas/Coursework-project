#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "catmap.h"

extern int size;
extern int matrix[4][4];

/**
 * Fills content of matrix.
 */
void
cat_map_matrix_init(void)
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

/**
 * Transforms content of matrix by
 * Arnold's Cat Map algorithm
 */
void
cat_map_transform(void)
{
	int i, j;
	int x, y;
	int temp_matrix[size][size];

	memcpy(temp_matrix, matrix, sizeof(temp_matrix));

	for (i = 0; i < size; i++)
	{
		for (j = 0; j < size; j++)
		{
			x = i + j;
			y = i + 2 * j;

			x = x % size;
			y = y % size;
			
			matrix[x][y] = temp_matrix[i][j];
		}
	}
}

/**
 * Prints matrix
 */
void
cat_map_print(void)
{
	int i, j;

	for (i = 0; i < size; i++)
	{
		for (j = 0; j < size; j++)
		{
			printf("%d ", matrix[i][j]);
		}
		printf("\n");
	}
}
