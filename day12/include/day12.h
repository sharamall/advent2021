//
// Created by shara on 2021-12-13.
//

#ifndef ADVENT2021_DAY12_H
#define ADVENT2021_DAY12_H
#define DATA_LENGTH 21

#include "shared.h"
typedef struct {
    char *name;
    int big;
    int visited;
} node;

typedef struct {
    node *from, *to;
} path;

typedef struct {
    path *paths;
    list *nodes;
    node *start, *end;
    int small_cave_visited;
} input;

input *alloc_input(const char *file);
void dealloc_input(input *in);
#endif //ADVENT2021_DAY12_H
