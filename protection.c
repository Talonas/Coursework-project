#include <stdio.h>
#include <stdlib.h>

#include "protection.h"
#include "catmap.h"
#include "matrix.h"
#include "license_gen.h"

struct matrix_s *matrix = NULL;

static void set_license(void);
static int protection_check(void);


void
init_license(void)
{
	generate(0);
	set_license();
}

int
get_license(void)
{
	return protection_check();
}

static void
set_license(void)
{
	matrix = matrix_init("license");
}

/**
 * Checking if program's license is valid
 */
static int
protection_check(void)
{
	int ret = 1;
	cat_map_transform(matrix);

	if (matrix->content[0][1] != 1)
	{
		printf("You don't have rights to use this program!\n");
		protection_free();
		//exit(-1);
		ret = 0;
		goto done;
	}

done:
	return ret;
}

/**
 * Release memory of matrix
 */
void
protection_free(void)
{
	cat_map_matrix_deinit(matrix);
}
