#include <stdio.h>
#include <stdlib.h>

#define DEFAULT_MODE "r"

static FILE *file_open(char *file_name, void *mode);
static void file_close(FILE *file);


static FILE *
file_open(char *file_name, void *mode)
{
	FILE *file = NULL;


	if (file_name == NULL)
	{
		printf("ERROR: file name is NULL\n");
		goto done;
	}

	if (mode == NULL)
	{
		mode = DEFAULT_MODE;
	}

	file = fopen(file_name, mode);
	if (file == NULL)
	{
		printf("ERROR: could not open a file\n");
		goto done;
	}

done:
	return file;
}

static void
file_close(FILE *file)
{
	fclose(file);
}

void file_get_content(char *file_name)
{
	FILE *file = NULL;
	char *content = NULL;
	size_t size;


	if (file_name == NULL)
	{
		printf("ERROR: file name is NULL\n");
		return;
	}

	file = file_open(file_name, "r");
	if (file == NULL)
	{
		printf("ERROR: file '%s' could not be opened\n", file_name);
		return;
	}

	fseek(file, 0, SEEK_END);
	size = ftell(file);
	fseek(file, 0, SEEK_SET);
	content = malloc(size);
	fread(content, size, 1, file);

	file_close(file);

	printf("%s\n", content);
	
}
