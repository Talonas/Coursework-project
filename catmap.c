#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "catmap.h"
#include "matrix.h"

static void transform(struct cat_map_s *cat_map);

void
transform(struct cat_map_s *cat_map)
{
	int i, j;
	int x, y;
	char **temp_content = NULL;

	if (cat_map == NULL)
	{
		printf("ERROR: cat_map is NULL");
		return;
	}

	temp_content = malloc(cat_map->size * sizeof(char *));
	if (temp_content == NULL)
	{
		printf("ERROR: low memory");
		goto done;
	}
	for (i = 0; i < cat_map->size; i++)
	{
		temp_content[i] = malloc(cat_map->size);
		if (temp_content[i] == NULL)
		{
			printf("ERROR: low memory");
			goto done;
		}
	}

	for (i = 0; i < cat_map->size; i++)
	{
		memcpy(temp_content[i], cat_map->content[i], cat_map->size);
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

struct cat_map_s *
cat_map_init(struct matrix_s *matrix)
{
	struct cat_map_s *cat_map = NULL;
	int i;

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

	cat_map->content = malloc(cat_map->size * sizeof(char *));
	if (cat_map->content == NULL)
	{
		printf("ERROR: low memory\n");
		goto fail;
	}
	for (i = 0; i < cat_map->size; i++)
	{
		cat_map->content[i] = malloc(cat_map->size);
		if (cat_map->content[i] == NULL)
		{
			printf("ERROR: low memory\n");
			goto fail;
		}
	}

	for (i = 0; i < cat_map->size; i++)
	{
		memcpy(cat_map->content[i], matrix->content[i], matrix->size);
	}

done:
	return cat_map;

fail:
	cat_map_deinit(cat_map);
	goto done;
}

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
			printf("%c ", cat_map->content[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

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

/*
void
cat_map_start_transform(struct cat_map_s *cat_map)
{
	if (cat_map == NULL)
	{
		printf("[%s] ERROR: cat map is NULL", __func__);
		return;
	}
	
	cat_map_transform(cat_map);
}

*/
