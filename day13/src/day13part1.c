//
// Created by shara on 2021-12-13.
//

#include "day13.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void print(input *in, int *grid) {
    for (int y = 0; y < in->max_y; y++) {
        for (int x = 0; x < in->max_x; x++) {
            if (grid[x + y * in->original_width]) {
                printf("#");
            } else {
                printf(".");
            }
        }
        printf("\n");
    }
    printf("\n");
}

int main(void) {
    input *in = alloc_input("../../day13/resources/input.txt");
    int *grid = malloc(sizeof(int) * in->max_x * in->max_y);
    memset(grid, 0, sizeof(int) * in->max_x * in->max_y);
    for (int i = 0; i < DATA_ROWS; i++) {
        point p = in->dots[i];
        int index = p.x + p.y * in->max_x;
        grid[index] = 1;
    }

    for (int i = 0; i < FOLD_ROWS; i++) {
        fold f = in->folds[i];
        if (f.x) {
            for (int y = 0; y < in->max_y; y++) {
                for (int x = f.value + 1; x < in->max_x; x++) {
                    if (grid[x + y * in->original_width]) {
                        int index = f.value + (f.value - x) + y * in->original_width;
                        grid[index] = 1;
                    }
                }
            }
            in->max_x = f.value;
        } else {
            for (int y = f.value + 1; y < in->max_y; y++) {
                for (int x = 0; x < in->max_x; x++) {
                    if (grid[x + y * in->original_width]) {
                        int index = x + (f.value + (f.value - y)) * in->original_width;
                        grid[index] = 1;
                    }
                }
            }
            in->max_y = f.value;
        }
    }
    print(in, grid);
    int total = 0;
    for (int i = 0; i < in->max_x * in->max_y; i++) {
        total += grid[i % in->max_x + (i / in->max_x) * in->original_width];
    }
    dealloc_input(in);
    free(grid);
    printf("total %d\n", total);

    return 0;
}