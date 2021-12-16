//
// Created by shara on 2021-12-16.
//

#ifndef ADVENT2021_DAY16_H
#define ADVENT2021_DAY16_H
#define LENGTH 6

#include "shared.h"

typedef struct {
    int len;
    int version;
    int *bits;
} packet;

typedef struct {
    list *packets;
} input;

int *alloc_input(const char *file);
void dealloc_input(int *bits);
#endif //ADVENT2021_DAY16_H
