//
// Created by shara on 2021-12-13.
//

#ifndef ADVENT2021_DAY13_H
#define ADVENT2021_DAY13_H

#define DATA_ROWS 1017
#define FOLD_ROWS 1

typedef struct {
    int x, value;
} fold;

typedef struct {
    int x, y;
} point;

typedef struct {
    int max_x, max_y;
    point *dots;
    fold *folds;
    int original_width;
} input;

input *alloc_input(const char *src);
void dealloc_input(input *in);

#endif //ADVENT2021_DAY13_H

