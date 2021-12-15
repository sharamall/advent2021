//
// Created by shara on 2021-12-15.
//

#include "day15.h"
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

input *alloc_input(const char *file) {
    FILE *f = fopen(file, "r");
    if (f) {
        input *in = malloc(sizeof(input));
        in->arr = malloc(sizeof(node *) * SIDE_LENGTH * SIDE_LENGTH);
        for (int x = 0; x < SIDE_LENGTH; x++) {
            for (int y = 0; y < SIDE_LENGTH; y++) {
                node *n = malloc(sizeof(node));
                n->distance = INT_MAX;
                char c;
                if (fscanf(f, "%c", &c) != 1) {
                    printf("bad input at %d, %d\n", x, y);
                    fclose(f);
                    exit(1);
                }
                n->risk = c - 48;
                if (y > 0) {
                    n->up = in->arr[x + (y - 1) * SIDE_LENGTH];
                    in->arr[x + (y - 1) * SIDE_LENGTH]->down = n;
                } else {
                    n->up = 0;
                }
                n->down = 0;
                if (x > 0) {
                    n->left = in->arr[x - 1 + y * SIDE_LENGTH];
                    in->arr[x - 1 + y * SIDE_LENGTH]->right = n;
                } else {
                    n->left = 0;
                }
                n->right = 0;
                in->arr[x + y * SIDE_LENGTH] = n;
                if (!x && !y) {
                    in->start = n;
                }
                if (x + 1 == SIDE_LENGTH && y + 1 == SIDE_LENGTH) {
                    in->end = n;
                }
            }
            fscanf(f, "%*c");
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
        for (int i = 0; i < SIDE_LENGTH * SIDE_LENGTH; i++) {
            free(in->arr[i]);
        }
        free(in->arr);
        free(in);
    }
}