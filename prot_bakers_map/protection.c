#include <stdlib.h>
#include <unistd.h>

#include "protection.h"
#include "bakers_map.h"

int size = 4;
int matrix[4][4];

static void set_license(int mode);

static void
set_license(int mode)
{
	bakers_map_matrix_init();
	matrix[1][2] = mode;
}

void
init_license(void)
{
	int ret;

	ret = access("license", F_OK);
	set_license(ret == 0);
}

int
get_license(void)
{
	bakers_map_transform();

	return matrix[0][1];
}
