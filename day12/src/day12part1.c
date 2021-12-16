//
// Created by shara on 2021-12-13.
//
#include "day12.h"
#include <stdio.h>

int find_paths(input *in, node *cur) {
    if (cur == in->end) {
        return 1;
    }
    int total = 0;
    for (int i = 0; i < DATA_LENGTH * 2; i++) {
        if (in->paths[i].from == cur) {
            if (in->paths[i].to != in->start) {
                if (in->paths[i].to->big || !in->paths[i].to->visited) {
                    in->paths[i].to->visited = 1;
                    total += find_paths(in, in->paths[i].to);
                    in->paths[i].to->visited = 0;
                }
            }
        }
    }
    return total;
}

int main(void) {
    input *in = alloc_input("../../day12/resources/input.txt");

    int total = find_paths(in, in->start);
    printf("total paths %d\n", total);
    dealloc_input(in);
    return 0;
}
