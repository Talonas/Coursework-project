#include <stdio.h>
#include <stdlib.h>

#include "matrix.h"

int main(int argc, char **argv)
{
	struct matrix_s *matrix = NULL;

	matrix = matrix_init(10);
	matrix_print(matrix);
	return 1;
}
