#include <stdio.h>
#include <stdlib.h>

#include "matrix.h"
#include "file.h"

static void matrix_allocate_memory(struct matrix_s *matrix);

/**
 * Matrix constructor
 * @params[in] file's name
 * @params[out] structure of Matrix
 */
struct matrix_s *
matrix_init(const char *file_name)
{
	struct matrix_s *matrix = NULL;
	struct buf_s *buf = NULL;

	matrix = malloc(sizeof(matrix));	

	buf = buf_init(file_name);

	matrix->buf = buf;
	matrix->size = file_get_int(buf);	
	matrix_allocate_memory(matrix);
	matrix_fill_content(matrix);

	return matrix;
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

/**
 * Generates content of matrix from file
 */
void
matrix_fill_content(struct matrix_s *matrix)
{
	int i, j;

	for (i = 0; i < matrix->size; i++)
	{
		for (j = 0; j < matrix->size; j++)
		{	
			matrix->content[i][j] = file_get_int(matrix->buf);
		}
	}
}
