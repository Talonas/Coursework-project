#include <stdio.h>
#include <stdlib.h>

#include "matrix.h"
#include "file.h"

static int
matrix_allocate_memory(struct matrix_s *matrix);


struct matrix_s *
matrix_init(const char *file_name)
{
	struct matrix_s *matrix = NULL;
	int ret;
	struct buf_s *buf = NULL;

	matrix = malloc(sizeof(matrix));	
	if (matrix == NULL)
	{
		printf("ERROR: low memory\n");
		goto done;
	}

	buf = buf_init(file_name);
	if (buf == NULL)
	{
		printf("ERROR: could not initialize buffer\n");
		goto done;
	}

	matrix->buf = buf;
	matrix->size = file_get_int(buf);

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
/*
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
*/
	matrix->content = malloc(matrix->size * sizeof(int *));
	if (matrix->content == NULL)
	{
		printf("ERROR: low memory\n");
		goto fail;
	}

	for (i = 0; i < matrix->size; i++)
	{
		matrix->content[i] = malloc(matrix->size);
		if (matrix->content[i] == NULL)
		{
			printf("ERROR: low memory\n");
			goto fail;
		}
	}

	retval = 0;

done:
	return retval;

fail:
	matrix_deinit(matrix);
	goto done;
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
			printf("%d ", matrix->content[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

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
