//
// Created by shara on 2021-12-22.
//
#include "day17.h"
#include <stdlib.h>
#include <stdio.h>

target *alloc_input(const char *file) {
    FILE *f = fopen(file, "r");
    if (f) {
        target *in = malloc(sizeof(target));
        if (fscanf(f, "target area: x=%d..%d, y=%d..%d", &in->x_min, &in->x_max, &in->y_min, &in->y_max) != 4) {
            printf("Invalid input.\n");
            dealloc_input(in);
            exit(1);
        }
        fclose(f);
        return in;
    } else {
        printf("Unable to open file.\n");
        exit(1);
    }
}

void dealloc_input(target *in) {
    if (in) {
        free(in);
    }
}