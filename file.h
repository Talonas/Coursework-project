#ifndef _FILE_H
#define _FILE_H

struct buf_s {
	size_t pos;
	size_t size;
	char *buf;
};

struct buf_s *buf_init(char *file_name);

int file_add(const char *file_name, const void *val, const size_t size);
int file_add_str(const char *file_name, const char *str);
int file_add_int(const char *file_name, const int val);
int file_reset(char *file_name);

int file_get_int(struct buf_s *buf);
char *file_get_str(struct buf_s *buf);

#endif /* _FILE_H */
