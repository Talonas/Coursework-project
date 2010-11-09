#include <stdio.h>
#include <stdlib.h>

#include "protection.h"

int
main(void)
{
	int i;

	/**
	 * Initialize protection
	 */
	protection_get_license();
	
	/**
	 * Program is running
	 */
	for (i = 0; i < 20; i++)
	{
		protection_check();
		// Program is working ...
	}

	/**
	 * Deinit
	 */
	protection_free();

	return 0;
}

