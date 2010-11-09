#ifndef _MATRIX_H
#define _MATRIX_H


struct matrix_s {
	int size;
	int **content;
};

struct matrix_s *matrix_initialize(int size);
void matrix_fill_content(struct matrix_s *matrix);

void matrix_deinit(struct matrix_s *matrix);
void matrix_print(struct matrix_s *matrix);

#endif /* _MATRIX_H */
