//
// Created by shara on 2021-12-12.
//
#include <stdlib.h>
#include <stdio.h>
#include "day9.h"

location *alloc_input(const char *src) {
    FILE *file = fopen(src, "r");
    if (file) {
        location *input = malloc(sizeof(location) * WIDTH * 100);
        for (int i = 0; i < WIDTH * HEIGHT; i++) {
            input[i].marked = 0;
            input[i].sum_of_basin = 0;
            char c;
            if (i > 0 && i % WIDTH == 0) {
                fscanf(file, "%*c");
            }
            if (fscanf(file, "%c", &c) == 1) {
                input[i].val = c - 48;
            } else {
                printf("bad input at %d\n", i);
                dealloc_input(input);
                fclose(file);
                return 0;
            }
        }
        printf("\n");
        fclose(file);
        return input;
    }

    return 0;
}

void dealloc_input(location *in) {
    if (in) {
        free(in);
    }
}