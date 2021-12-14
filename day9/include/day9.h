//
// Created by shara on 2021-12-12.
//
#ifndef ADVENT2021_DAY9_H
#define ADVENT2021_DAY9_H
#define WIDTH 100
#define HEIGHT 100

typedef struct {
    int val;
    int marked;
    int sum_of_basin;
} location;

location *alloc_input();
void dealloc_input(location *in);

#endif //ADVENT2021_DAY9_H
