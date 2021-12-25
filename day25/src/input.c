//
// Created by shara on 2021-12-25.
//

#include "day25.h"
#include <stdio.h>
#include <stdlib.h>

char *alloc_input(const char *file) {
    FILE *f = fopen(file, "r");
    if (f) {
        char *in = malloc(sizeof(char) * WIDTH * HEIGHT);
        for (int y = 0; y < HEIGHT; y++) {
            for (int x = 0; x < WIDTH; x++) {
                char c;
                if (fscanf(f, "%c", &c) != 1) {
                    printf("Bad input at x,y %d,%d\n", x, y);
                    dealloc_input(in);
                    exit(1);
                }
                if (c == 'v') {
                    in[x + y * WIDTH] = 1;
                } else if (c == '>') {
                    in[x + y * WIDTH] = 2;
                } else {
                    in[x + y * WIDTH] = 0;
                }
            }
            fscanf(f, "\n");
        }
        fclose(f);
        return in;
    } else {
        printf("Unable to open file.\n");
        exit(1);
    }
}

void dealloc_input(char *in) {
    if (in) {
        free(in);
    }
}