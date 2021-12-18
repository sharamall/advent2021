//
// Created by shara on 2021-12-18.
//

#include "day18.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "shared.h"

input *alloc_input(const char *file) {
    FILE *f = fopen(file, "r");
    if (f) {
        input *in = malloc(sizeof(input));
        in->lines = malloc(sizeof(char *) * LENGTH);
        for (int i = 0; i < LENGTH; i++) {
            list *l = 0;
            char c = 0;
            int line_length = 0;
            while (c != '\n') {
                if (fscanf(f, "%c", &c) != 1) {
                    printf("Bad input at line %d char %d\n", i, line_length);
                    fclose(f);
                    exit(1);
                }
                if (c != '\n') {
                    push_back(&l, c);
                }
            }
            in->lines[i] = malloc(sizeof(char) * l->size + 1);
            int j = 0;
            for (; j < l->size; j++) {
                in->lines[i][j] = (char)l->items[j];
            }
            in->lines[i][j] = 0;
            dealloc_list(&l, 0);
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
        if (in->lines) {
            for (int i = 0; i < LENGTH; i++) {
                free(in->lines[i]);
            }
            free(in->lines);
        }
        free(in);
    }
}