//
// Created by shara on 2021-12-13.
//
#include "day12.h"
#include <stdio.h>

int find_paths(input *in, node *cur) {
    if (cur == in->end) {
        printf(" end");
        return 1;
    }
    int total = 0;
    for (int i = 0; i < DATA_LENGTH * 2; i++) {
        if (in->paths[i].from == cur) {
            if (in->paths[i].to != in->start) {
                if (in->paths[i].to->big || in->paths[i].to->visited < 2) {
                    int small_cave_visit = 0;
                    if (!in->paths[i].to->big && in->paths[i].to->visited == 1) {
                        if (in->small_cave_visited) {
                            continue;
                        } else {
                            in->small_cave_visited = 1;
                            small_cave_visit = 1;
                        }
                    }
                    in->paths[i].to->visited++;
                    int paths = find_paths(in, in->paths[i].to);
                    if (paths) {
                        printf(" %s", cur->name);
                    }
                    total += paths;
                    in->paths[i].to->visited--;
                    if (small_cave_visit) {
                        in->small_cave_visited--;
                    }
                }
            }
        }
    }
    return total;
}

int main(void) {
    input *in = alloc_input("../../day12/resources/input.txt");

    int total = find_paths(in, in->start);
    printf("\ntotal paths %d\n", total);
    dealloc_input(in);
    return 0;
}
