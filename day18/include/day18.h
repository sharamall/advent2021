//
// Created by shara on 2021-12-18.
//

#ifndef ADVENT2021_DAY18_H
#define ADVENT2021_DAY18_H
#define LENGTH 100

typedef struct {
    char **lines;
} input;

input *alloc_input(const char *file);
void dealloc_input(input *in);
#endif //ADVENT2021_DAY18_H
