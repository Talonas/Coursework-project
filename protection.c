#include <stdio.h>
#include <stdlib.h>

#include "protection.h"
#include "file.h"
#include "catmap.h"
#include "matrix.h"

struct matrix_s *matrix = NULL;

/**
 * Gets license from file
 */
int
protection_get_license()
{
	int retval = -1;
	const char *file_name;
	
	file_name = "license";

	matrix = matrix_init(file_name);
	if (matrix == NULL)
	{
		printf("ERROR: couldn't initialize matrix\n");
		goto done;
	}

	retval = 0;

done:
	return retval;
}

/**
 * Print error message
 */
void
protection_message()
{
	exit(-1);
}

/**
 * Checking if program's license is valid
 */
void
protection_check()
{
	matrix_print(matrix);
	protection_mix();

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
