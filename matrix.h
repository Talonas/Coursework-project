#ifndef _MATRIX_H
#define _MATRIX_H

#include "file.h"

struct matrix_s {
	int size;
	char **content;
	struct buf_s *buf;
};

struct matrix_s *matrix_init(char *file_name);

void matrix_deinit(struct matrix_s *matrix);
void matrix_print(struct matrix_s *matrix);
void matrix_fill_content(struct matrix_s *matrix);

#endif /* _MATRIX_H */
