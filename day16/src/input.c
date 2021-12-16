//
// Created by shara on 2021-12-16.
//
#include "day16.h"
#include <stdlib.h>
#include <stdio.h>

void parse_hex(int *dest, char hex) {
    switch (hex) {
        case '0':
            dest[0] = 0;
            dest[1] = 0;
            dest[2] = 0;
            dest[3] = 0;
            break;
        case '1':
            dest[0] = 0;
            dest[1] = 0;
            dest[2] = 0;
            dest[3] = 1;
            break;
        case '2':
            dest[0] = 0;
            dest[1] = 0;
            dest[2] = 1;
            dest[3] = 0;
            break;
        case '3':
            dest[0] = 0;
            dest[1] = 0;
            dest[2] = 1;
            dest[3] = 1;
            break;
        case '4':
            dest[0] = 0;
            dest[1] = 1;
            dest[2] = 0;
            dest[3] = 0;
            break;
        case '5':
            dest[0] = 0;
            dest[1] = 1;
            dest[2] = 0;
            dest[3] = 1;
            break;
        case '6':
            dest[0] = 0;
            dest[1] = 1;
            dest[2] = 1;
            dest[3] = 0;
            break;
        case '7':
            dest[0] = 0;
            dest[1] = 1;
            dest[2] = 1;
            dest[3] = 1;
            break;
        case '8':
            dest[0] = 1;
            dest[1] = 0;
            dest[2] = 0;
            dest[3] = 0;
            break;
        case '9':
            dest[0] = 1;
            dest[1] = 0;
            dest[2] = 0;
            dest[3] = 1;
            break;
        case 'A':
            dest[0] = 1;
            dest[1] = 0;
            dest[2] = 1;
            dest[3] = 0;
            break;
        case 'B':
            dest[0] = 1;
            dest[1] = 0;
            dest[2] = 1;
            dest[3] = 1;
            break;
        case 'C':
            dest[0] = 1;
            dest[1] = 1;
            dest[2] = 0;
            dest[3] = 0;
            break;
        case 'D':
            dest[0] = 1;
            dest[1] = 1;
            dest[2] = 0;
            dest[3] = 1;
            break;
        case 'E':
            dest[0] = 1;
            dest[1] = 1;
            dest[2] = 1;
            dest[3] = 0;
            break;
        case 'F':
            dest[0] = 1;
            dest[1] = 1;
            dest[2] = 1;
            dest[3] = 1;
            break;
        default:
            printf("Invalid char input %c\n", hex);
            exit(1);
    }
}

int *alloc_input(const char *file) {
    FILE *f = fopen(file, "r");
    if (f) {
        int *bits = malloc(sizeof(int) * LENGTH * 4);
        for (int i = 0; i < LENGTH / 2; i++) {
            char hex1, hex2;
            if (fscanf(f, "%c%c", &hex1, &hex2) != 2) {
                printf("Bad input at %d\n", i);
            }
            parse_hex(bits + i * 8, hex1);
            parse_hex(bits + i * 8 + 4, hex2);
        }
        fclose(f);
        return bits;
    } else {
        printf("Unable to open file.\n");
        exit(1);
    }
}

void dealloc_input(int *bits) {
    if (bits) {
        free(bits);
    }
}
