//
// Created by shara on 2021-12-16.
//
#include "day16.h"
#include <stdlib.h>
#include <stdio.h>

int main(void) {
    int *in = alloc_input("../../day16/resources/input.txt");
    int i = 0;
    for (i = 0; i < LENGTH * 4; i++) {
        printf("%d", in[i]);
    }
    i = 0;
    printf("\n");
    while (i < LENGTH * 4) {
        int packet_version = in[i] << 2 | in[i + 1] << 1 | in[i + 2] << 0;
        i += 3;
        int packet_type_id = in[i] << 2 | in[i + 1] << 1 | in[i + 2] << 0;
        i += 3;
        if (packet_type_id == 4) {
            // literal
            list *l = 0;
            int first;
            do {
                first = in[i];
                int val = in[i + 1] << 3 | in[i + 2] << 2 | in[i + 3] << 1 | in[i + 4] << 0;
                i += 5;
                push_back(&l, val);
            } while (first);
            int val = 0;
            for (int j = 0; j < l->size; j++) {
                val <<= 4;
                val |= (int)l->items[j];
            }
            printf("got literal %d, remain %d, i %d\n", val, i % 4, i);
            break;
        } else {
            //operator
            int len_bit = in[i++];
            if (len_bit == 0) {
                //15 bits
                int length = 0;
                for (int j = 0; j < 15; j++) {
                    length <<= 1;
                    length |= in[i + j];
                }
                printf("operator packet, length %d\n", length);
                break;
            } else {
                //11 bits
                int length = 0;
                for (int j = 0; j < 11; j++) {
                    length <<= 1;
                    length |= in[i + j];
                }
                printf("operator packet, length %d\n", length);
                break;
            }
        }
        printf("packet version %d, packet_type_id %d\n", packet_version, packet_type_id);

    }
    dealloc_input(in);
    return 0;
}