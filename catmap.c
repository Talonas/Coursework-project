#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "catmap.h"
#include "matrix.h"

static void free_temp_content(struct cat_map_s *cat_map, int **temp_content);
static int **generate_temp_content(struct cat_map_s *cat_map);
static void transform(struct cat_map_s *cat_map);
static void fill_content(struct cat_map_s *cat_map, struct matrix_s *matrix);
static int allocate_memory(struct cat_map_s *cat_map);

/**
 * Deallocates temp content
 */
static void
free_temp_content(struct cat_map_s *cat_map, int **temp_content)
{
	int i;

	if (cat_map == NULL)
	{
		return;
	}

	for (i = 0; i < cat_map->size; i++)
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

/**
 * Generates temp content
 */
static int**
generate_temp_content(struct cat_map_s *cat_map)
{
	int **temp_content = NULL;
	int i, j;

	temp_content = malloc(cat_map->size * sizeof(int *));
	if (temp_content == NULL)
	{
		printf("ERROR: low memory");
		goto done;
	}
	for (i = 0; i < cat_map->size; i++)
	{
		temp_content[i] = malloc(cat_map->size * sizeof(int));
		if (temp_content[i] == NULL)
		{
			printf("ERROR: low memory");
			goto fail;
		}
	}

	for (i = 0; i < cat_map->size; i++)
	{
		for (j = 0; j < cat_map->size; j++)
		{
			temp_content[i][j] = cat_map->content[i][j];
		}
	}

done:
	return temp_content;

fail:
	free_temp_content(cat_map, temp_content);
	goto done;
}

/**
 * Transfroms matrix content
 * by Arnold's Cat Map algorithm
 */
void
transform(struct cat_map_s *cat_map)
{
	int i, j;
	int x, y;
	int **temp_content = NULL;

	if (cat_map == NULL)
	{
		printf("ERROR: cat_map is NULL");
		return;
	}

	temp_content = generate_temp_content(cat_map);
	if (temp_content == NULL)
	{
		printf("ERROR: could not generate temp content\n");
		goto done;
	}

	for (i = 0; i < cat_map->size; i++)
	{
		for (j = 0; j < cat_map->size; j++)
		{
			x = i + j;
			y = i + 2 * j;

			x = x % cat_map->size;
			y = y % cat_map->size;

			cat_map->content[x][y] = temp_content[i][j];
		}
	}

done:
	free_temp_content(cat_map, temp_content);
}

static void
fill_content(struct cat_map_s *cat_map, struct matrix_s *matrix)
{
	int i, j;

	for (i = 0; i < cat_map->size; i++)
	{
		for (j = 0; j < cat_map->size; j++)
		{
			cat_map->content[i][j] = matrix->content[i][j];
		}
	}
}

static int
allocate_memory(struct cat_map_s *cat_map)
{
	int ret = -1;
	int i;

	cat_map->content = malloc(cat_map->size * sizeof(int *));
	if (cat_map->content == NULL)
	{
		printf("ERROR: low memory\n");
		goto done;
	}

	for (i = 0; i < cat_map->size; i++)
	{
		cat_map->content[i] = malloc(cat_map->size);
		if (cat_map->content[i] == NULL)
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
 * Initialize Cat Map
 * @params[in] Matrix structure
 * @params[out] Cat Map structure
 */
struct cat_map_s *
cat_map_init(struct matrix_s *matrix)
{
	struct cat_map_s *cat_map = NULL;
	int ret;

	if (matrix == NULL)
	{
		printf("ERROR: matrix is NULL");
		goto done;
	}

	cat_map = malloc(sizeof(*cat_map));
	if (cat_map == NULL)
	{
		printf("ERROR: low memory");
		goto done;
	}

	cat_map->content = NULL;
	cat_map->size = matrix->size;
	cat_map->period = 0;
	cat_map->curr_step = 0;

	ret = allocate_memory(cat_map);
	if (ret != 0)
	{
		printf("ERROR: could not allocate memory\n");
		goto fail;
	}

	fill_content(cat_map, matrix);

done:
	return cat_map;

fail:
	cat_map_deinit(cat_map);
	goto done;
}

/**
 * Cat Map destructor
 * @params[in] Cat Map structure
 */
void
cat_map_deinit(struct cat_map_s *cat_map)
{
	int i;

	if (cat_map == NULL)
	{
		printf("ERROR: cat_map is NULL");
		return;
	}

	for (i = 0; i < cat_map->size; i++)
	{
		if (cat_map->content[i] != NULL)
		{
			free(cat_map->content[i]);
			cat_map->content[i] = NULL;
		}
	}
	
	if (cat_map->content != NULL)
	{
		free(cat_map->content);
		cat_map->content = NULL;
	}

	free(cat_map);
	cat_map = NULL;
}

/**
 * Prints Cat Map matrix
 * @params[in] Cat Map structure
 */
void
cat_map_print(struct cat_map_s *cat_map)
{
	int i, j;

	if (cat_map == NULL)
	{
		printf("ERROR: cat_map is NULL");
		return;
	}

	for (i = 0; i < cat_map->size; i++)
	{
		for (j = 0; j < cat_map->size; j++)
		{
			printf("%d ", cat_map->content[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

/**
 * Transforms Cat Map matrix.
 * @param[in] Cat Map structure
 * @param[in] how many times do transformation. If zero, then
 *            transform one time
 */
void
cat_map_transform(struct cat_map_s *cat_map, int steps_cnt)
{
	int i;

	if (cat_map == NULL)
	{
		printf("ERROR: cat_map is NULL");
		return;
	}

	if (steps_cnt < 1)
	{
		steps_cnt = 1;
	}

	for (i = 0; i < steps_cnt; i++)
	{
		transform(cat_map);
	}
}

