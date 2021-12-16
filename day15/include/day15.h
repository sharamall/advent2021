//
// Created by shara on 2021-12-15.
//

#ifndef ADVENT2021_DAY15_H
#define ADVENT2021_DAY15_H
struct node;
typedef struct node node;
struct node {
    int distance;
    int risk;
    node *up, *down, *left, *right;
    node *prev;
};

typedef struct {
    node *start, *end, **arr;
    int side_length;
} input;

input *alloc_input(const char *file);
void dealloc_input(input *in);
#endif //ADVENT2021_DAY15_H
