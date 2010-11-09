#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

static int protection;

static void
set_license(int status)
{
	protection = status;
}

static int 
get_license(void)
{
	return protection;
}

static void
init_license(void)
{
	int file_des;
	char *val = malloc(1);

	file_des = open("license_2", O_RDONLY);
	read(file_des, val, 1);
	set_license(atoi(val));
	free(val);
}

int
main(void)
{
	init_license();

	if (get_license() != 1)
	{
		printf("You can't use this program!\n");
		exit(-1);
	}

	// Program is working
	printf("Program is working\n");

	return 0;
}
