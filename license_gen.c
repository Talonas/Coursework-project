#include <stdio.h>
#include <stdlib.h>

#include "file.h"

static char *file_name;
static int size = 4;

static void generate_good();
static void generate_bad();
static void prepare();

int
main(int argc, char **argv)
{
	if (strcmp(argv[1], "g") == 0)
	{
		generate_good();
	}

	if (strcmp(argv[1], "b") == 0)
	{
		generate_bad();
	}

	return 0;
}

static void
prepare()
{
	file_name = "license";
	file_reset(file_name);
	file_add_int(file_name, size);
}

static void
generate_good()
{
	int i, j;

	prepare();

	for (i = 0; i < size; i++)
	{
		for (j = 0; j < size; j++)
		{
			file_add_int(file_name, 1);
		}
	}
}

static void
generate_bad()
{
	int i, j;

	prepare();

	for (i = 0; i < size; i++)
	{
		for (j = 0; j < size; j++)
		{
			if (i == 1 && j == 2)
			{
				file_add_int(file_name, 0);
				continue;
			}
			file_add_int(file_name, 1);
		}
	}
}
