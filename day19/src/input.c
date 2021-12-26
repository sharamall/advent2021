//
// Created by shara on 2021-12-25.
//
#include "day19.h"
#include <stdlib.h>
#include <stdio.h>
#include "shared.h"
#include <string.h>

scanner *alloc_input(const char *file) {
    FILE *f = fopen(file, "r");
    if (f) {
        scanner *s = malloc(sizeof(scanner) * SCANNERS);
        memset(s, 0, sizeof(scanner) * SCANNERS);
        for (int i = 0; i < SCANNERS; i++) {
            list *l = 0;
            fscanf(f, "--- scanner %*d ---\n");
            int x, y, z;

            int c;
            c = fgetc(f);
            while (c > 0 && c != '\n') {
                ungetc(c, f);
                if (fscanf(f, "%d,%d,%d%*c", &x, &y, &z) != 3) {
                    printf("Bad input in scanner %d\n", i);
                    dealloc_input(s);
                    fclose(f);
                    exit(1);
                }
                vector3 *beacon = malloc(sizeof(vector3));
                *beacon = (vector3){x, y, z};
                push_back(&l, beacon);
                c = fgetc(f);
            }

            vector3 *beacons = malloc(sizeof(vector3) * l->size);
            for (int b = 0; b < l->size; b++) {
                beacons[b] = *(vector3 *)l->items[b];
            }
            s[i].beacons = beacons;
            dealloc_list(&l, 1);
        }
        fclose(f);
        return s;
    } else {
        printf("Unable to open file.\n");
        exit(1);
    }
}

void dealloc_input(scanner *scanners) {
    if (scanners) {
        if (scanners->beacons) {
            for (int i = 0; i < SCANNERS; i++) {
                if (scanners[i].beacons) {
                    free(scanners[i].beacons);
                }
            }
        }
        free(scanners);
    }
}