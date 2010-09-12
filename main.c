#include <stdio.h>
#include <stdlib.h>

#include "protection.h"

int
main(int argc, char **argv)
{
	int i;
	int retval;

	retval = protection_get_license();
	if (retval != 0)
	{
		printf("Something wrong\n");
		return -1;
	}
	
	for (i = 0; i < 20; i++)
	{
		protection_check();
	}

	protection_free();

	return 0;
}

