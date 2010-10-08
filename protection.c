#include <stdio.h>
#include <stdlib.h>

#include "protection.h"
#include "Components/catmap.h"
#include "Components/matrix.h"

struct matrix_s *matrix = NULL;

/**
 * Gets license from file
 */
void
protection_get_license()
{
	const char *file_name;
	file_name = "license";
	matrix = matrix_init(file_name);
}

/**
 * Checking if program's license is valid
 */
void
protection_check()
{
	cat_map_transform(matrix, 1);

	if (matrix->content[0][1] != 1)
	{
		printf("You don't have rights to use this program!\n");
		exit(-1);
	}
}

/**
 * Release memory of matrix
 */
void
protection_free()
{
	matrix_deinit(matrix);
}
