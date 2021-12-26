//
// Created by shara on 2021-12-25.
//
#include "day19.h"
#include <stdio.h>

void next_rot(vector3 *rot) {
    if (rot->x == 270) {
        if (rot->y == 270) {
            rot->z += 90;
            rot->y = 0;
            rot->x = 0;
        } else {
            rot->y += 90;
            rot->x = 0;
        }
    } else {
        rot->x += 90;
    }
}

void print_vector3(vector3 vec) {
    printf("[%d,%d,%d]", vec.x, vec.y, vec.z);
}

int main(void) {
    scanner *in = alloc_input("../../day19/resources/input.txt");
    for (int i = 0; i < 25; i++) {
        print_vector3(in[0].beacons[i]);
        printf("\n");
    }
    vector3 vec = {0, 0, 0};
    for (int i = 0; i < 23; i++) {
        next_rot(&vec);
        print_vector3(vec);
        printf("\n");
    }
    dealloc_input(in);
    return 0;
}