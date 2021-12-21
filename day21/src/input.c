//
// Created by shara on 2021-12-21.
//
#include "day21.h"
#include <stdio.h>

int64_t read_input(const char *file) {
    FILE *f = fopen(file, "r");
    if (f) {
        int64_t high, low;
        fscanf(f, "Player %*d starting position: %ld%*c", &high);
        fscanf(f, "Player %*d starting position: %ld%*c", &low);
        fclose(f);
        return high << 32 | low;
    } else {
        printf("Unable to open file.\n");
        exit(1);
    }
}