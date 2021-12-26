//
// Created by shara on 2021-12-25.
//

#include "day20.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

input *alloc_input(const char *src, int iterations) {
    FILE *f = fopen(src, "r");
    if (f) {
        input *in = malloc(sizeof(input));
        in->enhancement = malloc(sizeof(char) * 512);
        in->line_size = IMAGE_SIZE + iterations * 2;
        in->image = malloc(sizeof(char) * in->line_size * in->line_size);
        memset(in->enhancement, 0, sizeof(char) * 512);
        memset(in->image, 0, sizeof(char) * in->line_size * in->line_size);
        for (int i = 0; i < ENHANCEMENT_LENGTH; i++) {
            char c;
            if (fscanf(f, "%c", &c) != 1) {
                printf("Bad input at char %d\n", i);
                dealloc_input(in);
                exit(1);
            }
            if (c == '#') {
                in->enhancement[i] = 1;
            }
        }
        fscanf(f, "%*c%*c");
        for (int y = iterations; y < IMAGE_SIZE + iterations; y++) {
            for (int x = iterations; x < IMAGE_SIZE + iterations; x++) {
                char c;
                if (fscanf(f, "%c", &c) != 1) {
                    printf("Bad input at index %d\n", x + y * IMAGE_SIZE);
                    dealloc_input(in);
                    exit(1);
                }
                if (c == '#') {
                    in->image[x + y * in->line_size] = 1;
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

void dealloc_input(input *input) {
    if (input) {
        if (input->enhancement) {
            free(input->enhancement);
        }
        if (input->image) {
            free(input->image);
        }
        free(input);
    }
}