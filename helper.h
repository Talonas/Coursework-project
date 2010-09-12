#ifndef _HELPER_H
#define _HELPER_H

#include "matrix.h"

int **generate_temp_content(struct matrix_s *matrix);

void free_temp_content(struct matrix_s *matrix, int **temp_content);

#endif /* _HELPER_H */
