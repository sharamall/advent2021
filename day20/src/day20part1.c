//
// Created by shara on 2021-12-25.
//

#include "day20.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print_board(char *in, int line_size) {
    for (int y = 0; y < line_size; y++) {
        for (int x = 0; x < line_size; x++) {
            printf("%c", in[x + y * line_size] ? '#' : '.');
        }
        printf("\n");
    }
    printf("\n");
}

int main(void) {
    int offset = 9;
    input *in = alloc_input("../../day20/resources/input.txt", offset);
    int iterations = 2;
    for (int i = 0; i < iterations; i++) {
        char *new_image = malloc(sizeof(char) * in->line_size * in->line_size);
        for (int y = 1; y < in->line_size - 1; y++) {
            for (int x = 1; x < in->line_size - 1; x++) {
                int val =
                        in->image[x - 1 + (y - 1) * in->line_size] << 8 |
                        in->image[x + 0 + (y - 1) * in->line_size] << 7 |
                        in->image[x + 1 + (y - 1) * in->line_size] << 6 |
                        in->image[x - 1 + (y + 0) * in->line_size] << 5 |
                        in->image[x + 0 + (y + 0) * in->line_size] << 4 |
                        in->image[x + 1 + (y + 0) * in->line_size] << 3 |
                        in->image[x - 1 + (y + 1) * in->line_size] << 2 |
                        in->image[x + 0 + (y + 1) * in->line_size] << 1 |
                        in->image[x + 1 + (y + 1) * in->line_size] << 0;
                if (val > 512) {
                    printf("val too big\n");
                }
                new_image[x + y * in->line_size] = in->enhancement[val];
            }
        }
        for (int j = 0; j < in->line_size; j++) {
            new_image[j] = i % 2 + 1;
            new_image[in->line_size - 1 + j * in->line_size] = i % 2 + 1;
            new_image[j * in->line_size] = i % 2 + 1;
            new_image[j + (in->line_size - 1) * in->line_size] = i % 2 + 1;
        }
        print_board(new_image, in->line_size);
        memcpy(in->image, new_image, sizeof(char) * in->line_size * in->line_size);
        free(new_image);
        offset--;
    }
    int total = 0;
    for (int y = iterations; y < in->line_size - iterations; y++) {
        for (int x = iterations; x < in->line_size - iterations; x++) {
            total += in->image[x + y * in->line_size];
        }
    }
    printf("total pixels lit %d\n", total);
    dealloc_input(in);
    return 0;
}