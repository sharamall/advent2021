//
// Created by shara on 2021-12-10.
//
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "day8.h"

input_row *alloc_input(const char *src) {
    FILE *file = fopen(src, "r");
    if (file) {
        input_row *in = malloc(sizeof(input_row) * 200);
        for (int i = 0; i < 200; i++) {
            in[i].digits = malloc(sizeof(char *) * 10);
            in[i].output = malloc(sizeof(char *) * 4);
            for (int j = 0; j < 10; j++) {
                in[i].digits[j] = malloc(sizeof(char) * 8);
                char c[7];
                memset(&c, 0, sizeof(char) * 7);
                memset(in[i].digits[j], 0, sizeof(char) * 8);
                int read_letters = fscanf(file, "%s", (char *)&c);
                if (read_letters) {
                    size_t strlen_c = strlen(c);
                    memcpy(in[i].digits[j], c, strlen_c);
                    in[i].digits[j][7] = 0;
                } else {
                    printf("bad input at %d\n", i);
                    dealloc_input(in);
                    fclose(file);
                    return 0;
                }

            }
            fscanf(file, "%*c%*c");
            for (int j = 0; j < 4; j++) {
                in[i].output[j] = malloc(sizeof(char) * 8);
                char c[7];
                memset(&c, 0, sizeof(char) * 7);
                memset(in[i].output[j], 0, sizeof(char) * 8);
                int read_letters = fscanf(file, "%s", (char *)&c);
                if (read_letters) {
                    memcpy(in[i].output[j], c, strlen(c));
                    in[i].output[j][7] = 0;
                } else {
                    printf("bad input at %d\n", i);
                    dealloc_input(in);
                    fclose(file);
                    return 0;
                }

            }
        }
        fclose(file);
        return in;
    }

    return 0;
}

void dealloc_input(input_row *input) {
    if (input) {
        for (int i = 0; i < 200; i++) {
            if (input[i].digits) {
                for (int j = 0; j < 10; j++) {
                    if (input[i].digits[j]) {
                        free(input[i].digits[j]);
                    }
                }
                free(input[i].digits);
            }
            if (input[i].output) {
                for (int j = 0; j < 4; j++) {
                    if (input[i].output[j]) {
                        free(input[i].output[j]);
                    }
                }
                free(input[i].output);
            }
        }
        free(input);
    }
}