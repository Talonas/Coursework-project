#include <stdio.h>
#include <stdlib.h>

#include "protection.h"

int
main(void)
{
	init_license();

	// while (...)
	// {

	if (get_license() != 1)
	{
		printf("You can't use this program!\n");
		protection_free();
		exit(-1);
	}

	// Program is working ...
	printf("Program is working\n");

	// }

	protection_free();

	return 0;
}

