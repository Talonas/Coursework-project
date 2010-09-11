#include <stdio.h>
#include <stdlib.h>

#include "protection.h"
#include "file.h"
#include "catmap.h"
#include "matrix.h"

struct cat_map_s *matrix = NULL;

/**
 * Gets license from file
 */
int
protection_get_license()
{
	int retval = -1;
	struct matrix_s *_matrix = NULL;
	const char *file_name;
	
	file_name = "license";

	_matrix = matrix_init(file_name);
	if (_matrix == NULL)
	{
		printf("ERROR: couldn't initialize matrix\n");
		goto done;
	}

	matrix = cat_map_init(_matrix);
	if (matrix == NULL)
	{
		printf("ERROR: could'nt init cat map\n");
		goto done;
	}

	retval = 0;

done:
	if (_matrix != NULL)
	{
		free(_matrix);
		_matrix = NULL;
	}

	return retval;
}

/**
 * Print error message
 */
void
protection_message()
{
	printf("You don't have rights to use this program!\n");
	exit(-1);
}

/**
 * Mixing matrix one time
 */
void
protection_mix()
{
	cat_map_transform(matrix, 1);
}

/**
 * Checking if program's license is valid
 */
void
protection_check()
{
	cat_map_print(matrix);
	protection_mix();

	if (matrix->content[0][1] != 1)
	{
		protection_message();
	}
}

/**
 * Release memory of matrix
 */
void
protection_free()
{
	cat_map_deinit(matrix);
}
