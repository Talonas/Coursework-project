#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "protection.h"
#include "file.h"
#include "catmap.h"
#include "matrix.h"

struct cat_map_s catmap = NULL;
const *char file_name = NULL;

/**
 * Gets license from file
 */
int
protection_get_license()
{
	int retval = -1;
	struct matrix_s matrix = NULL;
	file_name = "license";

	matrix = matrix_init(file_name);
	if (matrix == NULL)
	{
		printf("ERROR: couldn't initialize matrix\n");
		goto done;
	}

	catmap = cat_map_init(matrix);
	if (catmap == NULL)
	{
		printf("ERROR: could'nt init cat map\n");
		goto done;
	}

	retval = 0;

done:
	if (matrix != NULL)
	{
		free(matrix);
		matrix = NULL;
	}

	return buf;
}

/**
 * Mixing matrix one time
 */
void
protection_mix()
{

}

/**
 * Checking if program's license is valid
 */
bool
protection_get_value()
{

}
