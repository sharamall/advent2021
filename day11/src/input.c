//
// Created by shara on 2021-12-13.
//

#include "day11.h"
#include <stdlib.h>
#include <stdio.h>

int *alloc_input(const char *src) {
    FILE *file = fopen(src, "r");
    if (file) {
        int *in = malloc(sizeof(int) * SIDE_L * SIDE_L);
        for (int y = 0; y < SIDE_L; y++) {
            for (int x = 0; x < SIDE_L; x++) {
                char c;
                if (fscanf(file, "%c", &c) != 1) {
                    printf("bad input at %d, %d\n", x, y);
                    dealloc_input(in);
                    fclose(file);
                    return 0;
                } else {
                    *(in + x + y * SIDE_L) = c - 48;
                }
            }
            fscanf(file, "%*c");
        }
        fclose(file);
        return in;
    }

    return 0;
}

void dealloc_input(int *input) {
    if (input) {
        free(input);
    }
}