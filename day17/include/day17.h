//
// Created by shara on 2021-12-22.
//

#ifndef ADVENT2021_DAY17_H
#define ADVENT2021_DAY17_H

typedef struct {
    int x_min, x_max, y_min, y_max;
} target;

target *alloc_input(const char *file);
void dealloc_input(target *in);

#endif //ADVENT2021_DAY17_H
