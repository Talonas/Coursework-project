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
	protection_init_license();
	
	/**
	 * Program is running
	 */
	// while (...)
	// {

	// Program is working ...
	protection_check();

	// }

	/**
	 * Deinit
	 */
	protection_free();

	return 0;
}

