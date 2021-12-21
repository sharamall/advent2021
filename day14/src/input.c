//
// Created by shara on 2021-12-13.
//


#include "day14.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "shared.h"

int16_t chars_to_key(char a, char b) {
    int16_t ret;
    ret = a << 8;
    ret |= b;
    return ret;
}

int *map_rules(input *in) {
    int *map = malloc(sizeof(int) * 65535);
    memset(map, 0, sizeof(int) * 65535);
    for (int i = 0; i < IN_LENGTH; i++) {
        map[in->mappings[i]->key] = in->mappings[i]->val;
    }
    return map;
}

input *alloc_input(const char *src) {
    FILE *file = fopen(src, "r");
    if (file) {
        input *in = malloc(sizeof(input));
        in->mappings = malloc(sizeof(mapping *) * IN_LENGTH);
        in->start = malloc(sizeof(char) * (FIRST_LINE + 1));
        in->start[FIRST_LINE] = 0;
        for (int i = 0; i < FIRST_LINE; i++) {
            if (fscanf(file, "%c", in->start + i) != 1) {
                printf("bad input\n");
                exit(1);
            }
        }
        fscanf(file, "%*c%*c");
        for (int i = 0; i < IN_LENGTH; i++) {
            mapping *m = malloc(sizeof(mapping));
            in->mappings[i] = m;
            char a, b;
            if (fscanf(file, "%c%c -> %c%*c", &a, &b, &m->val) != 3) {
                printf("bad input\n");
                exit(1);
            }
            m->key = (a << 8) | b;
        }
        fclose(file);
        return in;
    } else {
        return 0;
    }
}

void dealloc_input(input *in) {
    if (in) {
        for (int i = 0; i < IN_LENGTH; i++) {
            free(in->mappings[i]);
        }
        free(in->mappings);
        free(in->start);
        free(in);
    }
}