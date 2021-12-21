//
// Created by shara on 2021-12-13.
//

#ifndef ADVENT2021_DAY14_H
#define ADVENT2021_DAY14_H

#define FIRST_LINE 20
#define IN_LENGTH 100

#include <stdlib.h>

typedef struct {
    int16_t key;
    char val;
} mapping;

typedef struct {
    char *start;
    mapping **mappings;
} input;

int16_t chars_to_key(char a, char b);
int *map_rules(input *in);
input *alloc_input(const char *file);
void dealloc_input(input *in);

#endif //ADVENT2021_DAY14_H
