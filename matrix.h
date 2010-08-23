#ifndef _MATRIX_H
#define _MATRIX_H

struct matrix_s {
	int size;
	char **content;
};

struct matrix_s *matrix_init(int size);

void matrix_deinit(struct matrix_s *matrix);
void matrix_print(struct matrix_s *matrix);
void matrix_fill_content(struct matrix_s *matrix);

#endif /* _MATRIX_H */
