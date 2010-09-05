#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

#include "file.h"

struct buf_s *
buf_init(const char *file_name)
{
	struct buf_s *buf = NULL;
	size_t size;
	int file_des;

	buf = malloc(sizeof(*buf));
	if (buf == NULL)
	{
		printf("ERROR: low mem\n");
		goto fail;
	}

	file_des = open(file_name, O_RDONLY);
	if (file_des < 0)
	{
		printf("ERROR: opening \"%s\" file\n", file_name);
		goto fail;
	}

	buf = malloc(sizeof(*buf));
	if (buf == NULL)
	{
		printf("ERROR: low memory\n");
		goto fail;
	}

	buf->size = lseek(file_des, 0L, 2);
	buf->buf = NULL;
	buf->pos = 0;

	lseek(file_des, 0L, 0);

	buf->buf = malloc(buf->size);
	if (buf->buf == NULL)
	{
		printf("ERROR: low memory\n");
		goto fail;
	}

	size = read(file_des, buf->buf, buf->size);
	if (size != buf->size)
	{
		printf("ERROR: reading file \"%s\"", file_name);
		goto fail;
	}

done:
	if (file_des > -1)
	{
		close(file_des);
	}

	return buf;

fail:
	if (buf->buf != NULL)
	{
		free(buf->buf);
		buf->buf = NULL;
	}

	if (buf != NULL)
	{
		free(buf);
		buf = NULL;
	}

	goto done;
}

int
file_add(const char *file_name, const void *val, const size_t size)
{
	size_t added;
	int retval = -1;
	FILE *file = NULL;

	file = fopen(file_name, "a");
	if (file == NULL)
	{
		printf("ERROR: \"%s\" could not be open\n", file_name);
		goto done;
	}

	added = fwrite(val, 1, size, file);
	if (added != size)
	{
		printf("ERROR: couldn't write all content\n");
		goto done;
	}
	
	retval = 0;

done:
	if (file != NULL)
	{
		fclose(file);
	}

	return retval;
}

int
file_add_str(const char *file_name, const char *str)
{
	int retval;
	size_t size;

	size = strlen(str) + 1;
	retval = file_add(file_name, str, size);

	return retval;
}

int
file_add_int(const char *file_name, const int val)
{
	int retval;

	retval = file_add(file_name, &val, sizeof(int));

	return retval;
}

int
file_reset(char *file_name)
{
	int retval = -1;
	FILE *file = NULL;

	file = fopen(file_name, "w+");
	if (file == NULL)
	{
		printf("ERROR: \"%s\" could not be open\n", file_name);
		goto done;
	}

	fwrite("", 1, 0, file);

	retval = 0;

done:
	if (file != NULL)
	{
		fclose(file);
	}

	return retval;
}

int
file_get_int(struct buf_s *buf)
{
	int retval = -1;
	int ret;

	if (buf->size < buf->pos + sizeof(int))
	{
		printf("ERROR: out of bounds\n");
		goto done;
	}
	
	memcpy(&ret, buf->buf + buf->pos, sizeof(int));
	buf->pos += sizeof(int);

	retval = ret;

done:
	return retval;
}

char *
file_get_str(struct buf_s *buf)
{
	char *retval = NULL;
	size_t size = 1024;

	retval = malloc(size);

	strcat(retval, buf->buf + buf->pos);
	buf->pos += strlen(retval) + 1;

	return retval;
}
