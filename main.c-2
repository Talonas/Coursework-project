#include <stdio.h>
#include <stdlib.h>

#include "protection.h"

int
main(int argc, char **argv)
{
	int i;

	/**
	 * Initialize protection
	 */
	protection_get_license();
	
	/**
	 * Say that program is running
	 */
	for (i = 0; i < 20; i++)
	{
		protection_check();
	}

	/**
	 * Deinit
	 */
	protection_free();

	return 0;
}

