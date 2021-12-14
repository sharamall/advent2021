//
// Created by shara on 2021-12-12.
//

#include "day10.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char **alloc_input(const char *src) {
    FILE *file = fopen(src, "r");
    if (file) {
        char **input = malloc(sizeof(char *) * IN_LENGTH);
        for (int i = 0; i < IN_LENGTH; i++) {
            char *line = malloc(sizeof(char) * 110);
            memset(line, 0, sizeof(char) * 110);
            input[i] = line;
            char cur = 0;
            int offset = 0;
            while (cur != '\n') {
                if (fscanf(file, "%c", &cur) == 1) {
                    if (cur == '\n') {
                        line[offset++] = 0;
                    } else {
                        line[offset++] = cur;
                    }
                } else {
                    printf("bad input at %d\n", i);
                    dealloc_input(input);
                    fclose(file);
                    return 0;
                }
            }
        }
        printf("\n");
        fclose(file);
        return input;
    } else {
        return 0;
    }
}

void dealloc_input(char **in) {
    if (in) {
        for (int i = 0; i < IN_LENGTH; i++) {
            free(in[i]);
        }
        free(in);
    }
}