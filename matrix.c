#include <stdio.h>
#include <stdlib.h>

#include "matrix.h"

static void matrix_allocate_memory(struct matrix_s *matrix);

struct matrix_s *
matrix_initialize(int size)
{
	struct matrix_s *matrix = NULL;

	printf("Matrix init\n");
	matrix = malloc(sizeof(*matrix));

	matrix->size = size;
	matrix_allocate_memory(matrix);
	matrix_fill_content(matrix);

	return matrix;
}

void
matrix_fill_content(struct matrix_s *matrix)
{
	int i, j;

	for (i = 0; i < matrix->size; i++)
	{
		for (j = 0; j < matrix->size; j++)
		{
			matrix->content[i][j] = 1;
		}
	}
}

void
matrix_deinit(struct matrix_s *matrix)
{
	int i;

	for (i = 0; i < matrix->size; i++)
	{
		if (matrix->content[i] != NULL)
		{
			free(matrix->content[i]);
			matrix->content[i] = NULL;
		}
	}
	
	if (matrix->content != NULL)
	{
		free(matrix->content);
		matrix->content = NULL;
	}

	if (matrix != NULL)
	{
		free(matrix);
		matrix = NULL;
	}
}

/**
 * Allocates memory for matrix content
 */
static void
matrix_allocate_memory(struct matrix_s *matrix)
{
	int i;

	matrix->content = malloc(matrix->size * sizeof(int *));

	for (i = 0; i < matrix->size; i++)
	{
		matrix->content[i] = malloc(matrix->size * sizeof(int));
	}
}

/**
 * Prints matrix content
 */
void
matrix_print(struct matrix_s *matrix)
{
	int i;
	int j;

	for (i = 0; i < matrix->size; i++)
	{
		for (j = 0; j < matrix->size; j++)
		{
			printf("%d ", matrix->content[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

