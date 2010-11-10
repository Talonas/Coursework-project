#include <stdlib.h>
#include <string.h>

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
	int i, j;
	int row, col;
	int temp_matrix[size][size];
	int temp_matrix_2[size][size];

	memcpy(temp_matrix, matrix, sizeof(temp_matrix));

	row = 0;
	for (i = 0; i < size; i++)
	{
		col = size - 1;
		for (j = 0; j < size; j++)
		{
			temp_matrix_2[row][col] = temp_matrix[j][i];
			col--;
		}
		row++;
	}
	
	row = 0;
	for (i = size/2; i < size; i++)
	{
		for (j = 0; j < size; j++)
		{
			matrix[row][j] = temp_matrix_2[i][j];
		}
		row++;
	}

	for (i = 0; i < size/2; i++)
	{
		for (j = 0; j < size; j++)
		{
			matrix[row][j] = temp_matrix_2[i][j];
		}
		row++;
	}
}

