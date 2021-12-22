//
// Created by shara on 2021-12-22.
//
#include "day22.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define LENGTH 20
#define EXTENTS 100
#define EXTENTS_PLUS_1 101

int get_index(int x, int y, int z) {
    return (x + EXTENTS / 2) + (y + EXTENTS / 2) * EXTENTS_PLUS_1 + (z + EXTENTS / 2) * EXTENTS_PLUS_1 * EXTENTS_PLUS_1;
}

int main(void) {
    input_line *in = alloc_input("../../day22/resources/input.txt", LENGTH);
    char *arr = malloc(sizeof(char) * EXTENTS_PLUS_1 * EXTENTS_PLUS_1 * EXTENTS_PLUS_1);
    memset(arr, 0, sizeof(char) * EXTENTS_PLUS_1 * EXTENTS_PLUS_1 * EXTENTS_PLUS_1);
    for (int i = 0; i < LENGTH; i++) {
        input_line cur = in[i];
        for (int x = cur.x_min; x <= cur.x_max; x++) {
            for (int y = cur.y_min; y <= cur.y_max; y++) {
                for (int z = cur.z_min; z <= cur.z_max; z++) {
                    arr[get_index(x, y, z)] = (char)cur.on;
                }
            }
        }
    }
    int on_cubes = 0;
    for (int x = -50; x <= 50; x++) {
        for (int y = -50; y <= 50; y++) {
            for (int z = -50; z <= 50; z++) {
                if (arr[get_index(x, y, z)]) {
                    on_cubes++;
                }
            }
        }
    }
    printf("on cubes %d\n", on_cubes);
    dealloc_input(in);
    free(arr);
    return 0;
}