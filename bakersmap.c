#include <stdio.h>
#include <stdlib.h>

#include "bakersmap.h"
#include "matrix.h"

static void transform(struct bakersmap_s *baker);
static int allocate_memory(struct bakersmap_s *baker);
static void fill_content(struct bakersmap_s *baker, struct matrix_s *matrix);

/**
 * Transforms matrix content by
 * Baker's Map algorithm.
 */
static void
transform(struct bakersmap_s *baker)
{

}

/**
 * Allocates memory for matrix content
 */
static int
allocate_memory(struct bakersmap_s *baker)
{
	int i;
	int ret = -1;

	baker->content = malloc(baker->size * sizeof(int *));
	if (baker->content == NULL)
	{
		printf("ERROR: low memory\n");
		goto done;
	}

	for (i = 0; i < baker->size; i++)
	{
		baker->content[i] = malloc(baker->size);
		if (baker->content[i] == NULL)
		{
			printf("ERROR: low memory\n");
			goto done;
		}
	}

	ret = 0;

done:
	return ret;
}

/**
 * Fills matrix content
 */
static void
fill_content(struct bakersmap_s *baker, struct matrix_s *matrix)
{
	int i, j;

	for (i = 0; i < baker->size; i++)
	{
		for (j = 0; j < baker->size; j++)
		{
			baker->content[i][j] = matrix->content[i][j];
		}
	}
}

/**
 * Initialize Baker's Map
 */
struct bakersmap_s *
bakers_map_init(struct matrix_s *matrix)
{
	struct bakersmap_s *baker = NULL;
	int ret;

	if (matrix == NULL)
	{
		printf("ERROR: matrix is null\n");
		goto done;
	}

	baker = malloc(sizeof(*baker));
	if (baker == NULL)
	{
		printf("ERROR: low memory\n");
		goto done;
	}

	baker->content = NULL;
	baker->size = matrix->size;
	baker->current_step = 0;

	ret = allocate_memory(baker);
	if (ret != 0)
	{
		printf("ERROR: could not allocate memory\n");
		goto fail;
	}

	fill_content(baker, matrix);

done:
	if (matrix != NULL)
	{
		matrix_deinit(matrix);
		matrix = NULL;
	}

	return baker;

fail:
	bakers_map_deinit(baker);
	goto done;
}

void
bakers_map_deinit(struct bakersmap_s *baker)
{
	int i;

	for (i = 0; i < baker->size; i++)
	{
		if (baker->content[i] != NULL)
		{
			free(baker->content[i]);
			baker->content[i] = NULL;
		}
	}

	if (baker->content != NULL)
	{
		free(baker->content);
		baker->content = NULL;
	}

	if (baker != NULL)
	{
		free(baker);
		baker = NULL;
	}
}

void
bakers_map_transform(struct bakersmap_s *baker, int steps_cnt)
{
	int i;

	if (baker == NULL)
	{
		printf("ERROR: bakers map is NULL\n");
		return;
	}

	if (steps_cnt < 1)
	{
		steps_cnt = 1;
	}

	for (i = 0; i < steps_cnt; i++)
	{
		transform(baker);
	}
}
