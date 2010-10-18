#include <stdio.h>
#include <stdlib.h>

/**
 * 1 - good
 * 0 - bad
 */
static int protection = 0;

int
main(void)
{
	if (protection != 1)
	{
		printf("You can't use this program!\n");
		exit(-1);
	}

	// Program is working
	// ...
	printf("Working...\n");

	return 0;
}
