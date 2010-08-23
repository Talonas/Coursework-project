#include <stdio.h>
#include <stdlib.h>

#include "matrix.h"

static int
matrix_allocate_memory(struct matrix_s *matrix);


struct matrix_s *
matrix_init(int size)
{
	struct matrix_s *matrix = NULL;
	int ret;


	matrix = malloc(sizeof(matrix));	
	if (matrix == NULL)
	{
		printf("ERROR: low memory\n");
		goto done;
	}

	matrix->size = size;
	ret = matrix_allocate_memory(matrix);
	if (ret != 0)
	{
		printf("ERROR: matrix could not be initialized\n");
		matrix_deinit(matrix);
		matrix = NULL;
		goto done;
	}

	matrix_fill_content(matrix);

done:
	return matrix;
}

void
matrix_deinit(struct matrix_s *matrix)
{
	int i;


	if (matrix == NULL)
	{
		return;
	}

	if (matrix->content != NULL)
	{
		for (i = 0; i < matrix->size; i++)
		{
			if (matrix->content[i] != NULL)
			{
				free(matrix->content[i]);
				matrix->content[i] = NULL;
			}
		}
		free(matrix->content);
	}
}

static int
matrix_allocate_memory(struct matrix_s *matrix)
{
	int retval = -1;
	int i;


	if (matrix == NULL)
	{
		printf("ERROR: matrix is NULL\n");
		goto done;
	}

	matrix->content = malloc(matrix->size * sizeof(char *));
	if (matrix->content == NULL)
	{
		printf("ERROR: low memory\n");
		goto done;
	}

	for (i = 0; i < matrix->size; i++)
	{
		matrix->content[i] = malloc(matrix->size);
		if (matrix->content[i] == NULL)
		{
			printf("ERROR: low memory\n");
			goto done;
		}
	}

	retval = 0;

done:
	return retval;
}

void
matrix_print(struct matrix_s *matrix)
{
	int i;
	int j;


	for (i = 0; i < matrix->size; i++)
	{
		for (j = 0; j < matrix->size; j++)
		{
			printf("%c ", matrix->content[i][j]);
		}
		printf("\n");
	}
}

void
matrix_fill_content(struct matrix_s *matrix)
{
	int i;
	int j;

	for (i = 0; i < matrix->size; i++)
	{
		for (j = 0; j < matrix->size; j++)
		{
			matrix->content[i][j] = '0';
		}
	}
}
