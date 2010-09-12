#include <stdio.h>
#include <stdlib.h>

#include "helper.h"
#include "matrix.h"

static int **allocate_memory(struct matrix_s *matrix);

static int **
allocate_memory(struct matrix_s *matrix)
{
	int **temp_content = NULL;
	int i;

	temp_content = malloc(matrix->size * sizeof(int *));
	if (temp_content == NULL)
	{
		printf("ERROR: low memory\n");
		goto fail;
	}

	for (i = 0; i < matrix->size; i++)
	{
		temp_content[i] = malloc(matrix->size * sizeof(int));
		if (temp_content[i] == NULL)
		{
			printf("ERROR: low memory\n");
			goto fail;
		}
	}

done:
	return temp_content;

fail:
	free_temp_content(matrix, temp_content);
	goto done;
}

int **
generate_temp_content(struct matrix_s *matrix)
{
	int **temp_content = NULL;
	int i, j;

	temp_content = allocate_memory(matrix);
	if (temp_content == NULL)
	{
		printf("Could not generate temp content\n");
		goto done;
	}

	for (i = 0; i < matrix->size; i++)
	{
		for (j = 0; j < matrix->size; j++)
		{
			temp_content[i][j] = matrix->content[i][j];
		}
	}

done:
	return temp_content;
}

void
free_temp_content(struct matrix_s *matrix, int **temp_content)
{
	int i;

	for (i = 0; i < matrix->size; i++)
	{
		if (temp_content[i] != NULL)
		{
			free(temp_content[i]);
			temp_content[i] = NULL;
		}
	}

	if (temp_content != NULL)
	{
		free(temp_content);
		temp_content = NULL;
	}
}
