#ifndef _CAT_MAP_H
#define _CAT_MAP_H

#include "matrix.h"

struct cat_map_s {
	char **content;
	int size;
	int period;
	int curr_step;
};

struct cat_map_s *cat_map_init(struct matrix_s *matrix);

void cat_map_deinit();
void cat_map_transform(struct cat_map_s *cat_map, int steps_cnt);
void cat_map_print(struct cat_map_s *cat_map);

#endif /* _CAT_MAP_H */
