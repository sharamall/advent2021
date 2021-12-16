//
// Created by shara on 2021-12-15.
//

#include "day15.h"
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define DATA_WIDTH 100
#define NUM_X_TILES 5

input *alloc_input(const char *file) {
    FILE *f = fopen(file, "r");
    if (f) {
        input *in = malloc(sizeof(input));
        in->side_length = DATA_WIDTH * NUM_X_TILES;
        in->arr = malloc(sizeof(node *) * in->side_length * in->side_length);
        for (int x = 0; x < in->side_length; x++) {
            for (int y = 0; y < in->side_length; y++) {
                node *n = malloc(sizeof(node));
                n->distance = INT_MAX;
                int index = x + y * in->side_length;
                int risk;
                if (x < DATA_WIDTH && y < DATA_WIDTH) {
                    char c;
                    if (fscanf(f, "%c", &c) != 1) {
                        printf("bad input at %d, %d\n", x, y);
                        fclose(f);
                        exit(1);
                    }
                    risk = c - 48;
                } else {
                    int tlx_index = x % DATA_WIDTH;
                    int tly_index = y % DATA_WIDTH;

                    int tl_index = tlx_index + tly_index * in->side_length;
                    int temp_risk = in->arr[tl_index]->risk + x / DATA_WIDTH + y / DATA_WIDTH;
                    if (temp_risk > 9) {
                        temp_risk %= 9;
                    }
                    risk = temp_risk;
                }
                if (y > 0) {
                    n->up = in->arr[x + (y - 1) * in->side_length];
                    in->arr[x + (y - 1) * in->side_length]->down = n;
                } else {
                    n->up = 0;
                }
                n->down = 0;
                if (x > 0) {
                    n->left = in->arr[x - 1 + y * in->side_length];
                    in->arr[x - 1 + y * in->side_length]->right = n;
                } else {
                    n->left = 0;
                }
                n->right = 0;
                n->risk = risk;
                in->arr[index] = n;
                if (!x && !y) {
                    in->start = n;
                }
                if (x + 1 == in->side_length && y + 1 == in->side_length) {
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
        for (int i = 0; i < in->side_length * in->side_length; i++) {
            free(in->arr[i]);
        }
        free(in->arr);
        free(in);
    }
}