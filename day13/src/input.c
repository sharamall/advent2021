//
// Created by shara on 2021-12-13.
//
#include "day13.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <limits.h>

input *alloc_input(const char *src) {
    FILE *f = fopen(src, "r");
    if (f) {
        input *in = malloc(sizeof(input));
        in->max_x = 0;
        in->max_y = 0;
        in->dots = malloc(sizeof(point) * DATA_ROWS);
        in->folds = malloc(sizeof(fold) * FOLD_ROWS);
        for (int i = 0; i < DATA_ROWS; i++) {
            int x, y;
            if (fscanf(f, "%d,%d\n", &x, &y) != 2) {
                printf("Bad input at %d\n", i);
                fclose(f);
                exit(1);
            }
            if (x > in->max_x) {
                in->max_x = x;
            }
            if (y > in->max_y) {
                in->max_y = y;
            }
            in->dots[i] = (point){x, y};
        }
        in->max_x++;
        in->max_y++;
        in->original_width = in->max_x;
        for (int i = 0; i < FOLD_ROWS; i++) {
            char x_or_y;
            int fold_index;
            if (fscanf(f, "fold along %c=%d\n", &x_or_y, &fold_index) != 2) {
                printf("Bad fold input at %d\n", i);
                fclose(f);
                exit(1);
            }
            in->folds[i] = (fold){x_or_y == 'x', fold_index};
        }
        fclose(f);
        return in;
    } else {
        printf("Unable to open file.\n");
        exit(1);
    }
}

void dealloc_input(input *in) {
    if (in) {
        if (in->dots) {
            free(in->dots);
        }
        if (in->folds) {
            free(in->folds);
        }
        free(in);
    }
}