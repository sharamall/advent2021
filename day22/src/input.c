//
// Created by shara on 2021-12-22.
//

#include "day22.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

input_line *alloc_input(const char *file, int length) {
    FILE *f = fopen(file, "r");
    if (f) {
        input_line *arr = malloc(sizeof(input_line) * length);
        for (int i = 0; i < length; i++) {
            input_line *cur = arr + i;
            char _1, _2, _3;
            int on = 1;
            if (fscanf(f, "%c%c%c", &_1, &_2, &_3) != 3) {
                printf("Bad input at line %d\n", i);
                dealloc_input(arr);
                fclose(f);
                exit(1);
            }
            if (_2 == 'f') {
                fscanf(f, "%*c");
                on = 0;
            }
            if (fscanf(f, "x=%d..%d,y=%d..%d,z=%d..%d%*c", &cur->x_min, &cur->x_max, &cur->y_min, &cur->y_max, &cur->z_min, &cur->z_max) != 6) {
                printf("Bad input at line %d\n", i);
                dealloc_input(arr);
                fclose(f);
                exit(1);
            }
            cur->on = on;
        }
        fclose(f);
        return arr;
    } else {
        printf("Unable to open file.\n");
        exit(1);
    }
}

void dealloc_input(input_line *input) {
    if (input) {
        free(input);
    }
}