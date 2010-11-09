#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "protection.h"
#include "catmap.h"
#include "matrix.h"

struct matrix_s *matrix = NULL;
int matrix_content[4][4];
static int matrix_size = 4;

static void set_license(int mode);


static void
set_license(int mode)
{
	matrix = matrix_initialize(matrix_size);
	matrix->content[1][2] = mode;
}

void
init_license(void)
{
	int ret;

	ret = access("license_2", F_OK);
	set_license(ret == 0);
}

int
get_license(void)
{
	cat_map_transform(matrix);

	return matrix->content[0][1];
	//return matrix_content[0][1];
}

/**
 * Release memory of matrix
 */
void
protection_free(void)
{
	cat_map_matrix_deinit(matrix);
}
