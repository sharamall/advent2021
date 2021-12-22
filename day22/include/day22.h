//
// Created by shara on 2021-12-22.
//

#ifndef ADVENT2021_DAY22_H
#define ADVENT2021_DAY22_H

typedef struct {
    int x_min, x_max, y_min, y_max, z_min, z_max, on;
} input_line;

input_line *alloc_input(const char *file, int length);
void dealloc_input(input_line *input);

#endif //ADVENT2021_DAY22_H
