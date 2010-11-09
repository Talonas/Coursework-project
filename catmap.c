#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "catmap.h"
#include "matrix.h"
#include "helper.h"

static void transform(struct matrix_s *matrix);

/**
 * Transfroms matrix content
 * by Arnold's Cat Map algorithm
 */
void
transform(struct matrix_s *matrix)
{
	int i, j;
	int x, y;
	int **temp_content = NULL;

	temp_content = generate_temp_content(matrix);

	for (i = 0; i < matrix->size; i++)
	{
		for (j = 0; j < matrix->size; j++)
		{
			x = i + j;
			y = i + 2 * j;

			x = x % matrix->size;
			y = y % matrix->size;

			matrix->content[x][y] = temp_content[i][j];
		}
	}

	free_temp_content(matrix, temp_content);
}

/**
 * Transforms Cat Map matrix.
 * @param[in] Matrix structure
 * @param[in] how many times do transformation. If zero, then
 *            transform one time
 */
void
cat_map_transform(struct matrix_s *matrix, int steps_cnt)
{
	int i;

	if (steps_cnt < 1)
	{
		steps_cnt = 1;
	}

	for (i = 0; i < steps_cnt; i++)
	{
		transform(matrix);
	}
}

void
cat_map_matrix_deinit(struct matrix_s *matrix)
{
	matrix_deinit(matrix);
}
