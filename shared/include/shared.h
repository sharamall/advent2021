//
// Created by shara on 2021-12-15.
//

#ifndef ADVENT2021_SHARED_H
#define ADVENT2021_SHARED_H

typedef struct {
    void **items;
    int size;
    int capacity;
} list;

void push_back(list **pp_l, void *item);

#endif //ADVENT2021_SHARED_H
