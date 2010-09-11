#ifndef _BAKERS_MAP_H
#define _BAKERS_MAP_H

#include "matrix.h"

struct bakersmap_s {
	int **content;
	int size;
	int current_step;
};

struct bakersmap_s *bakers_map_init(struct matrix_s *matrix);

void bakers_map_deinit(struct bakersmap_s *baker);
void bakers_map_transform(struct bakersmap_s *baker, int steps_cnt);

#endif /* _BAKERS_MAP_H */
