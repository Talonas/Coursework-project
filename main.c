#include <stdio.h>
#include <stdlib.h>

#include "matrix.h"
#include "file.h"
#include "catmap.h"
#include "protection.h"

void print_instructions();

int
main(int argc, char **argv)
{
	protection_generate();

	struct matrix_s *matrix = NULL;
	struct cat_map_s *cat_map = NULL;
	const char *file_name;

	file_name = "test";	
/*
	if (argc < 4)
	{
		print_instructions();
		return -1;
	}
*/

	matrix = matrix_init(file_name);
	if (matrix == NULL)
	{
		printf("ERROR: could not initialize new matrix\n");
		return -1;
	}

	matrix_print(matrix);
	
	/*
	cat_map = cat_map_init(matrix);
	if (cat_map == NULL)
	{
		printf("ERROR: could not initialize cat map\n");
		return -1;
	}

	cat_map_transform(cat_map, 1);
	cat_map_print(cat_map);
	cat_map_transform(cat_map, 2);
	cat_map_print(cat_map);
	*/
	return 0;
}

void
print_instructions()
{
	printf("Instructions:\n");
	printf("  program <input file> <output file> <algorithm>\n");
	printf("  Arguments:\n");
	printf("  - <algorithm>:\n");
	printf("    cm - Cat Map\n");
	printf("    bm - Baker's Map\n");
	printf("  Examples:\n");
	printf("  - program i_file o_file cm\n");
	printf("  - program i_file o_file bm\n");
}
