//
// Created by shara on 2021-12-16.
//
#include "day16.h"
#include <stdlib.h>
#include <stdio.h>

void read_operator(int *in, int *i, int *version);

void read_packet(int *in, int *i, int *version) {
    int packet_version = in[*i] << 2 | in[*i + 1] << 1 | in[*i + 2] << 0;
    *version += packet_version;
    *i += 3;
    int packet_type_id = in[*i] << 2 | in[*i + 1] << 1 | in[*i + 2] << 0;
    *i += 3;
    if (packet_type_id == 4) {
        // literal
        list *l = 0;
        int first;
        do {
            first = in[*i];
            int val = in[*i + 1] << 3 | in[*i + 2] << 2 | in[*i + 3] << 1 | in[*i + 4] << 0;
            *i += 5;
            push_back(&l, val);
        } while (first);
        int val = 0;
        for (int j = 0; j < l->size; j++) {
            val <<= 4;
            val |= (int)l->items[j];
        }
        printf("got literal %d, remain %d, i %d\n", val, *i % 4, *i);
    } else {
        read_operator(in, i, version);
    }

}

void read_operator(int *in, int *i, int *version) {
    //operator
    int len_bit = in[*i];
    *i += 1;
    if (len_bit) {
        //11 bits, total number of subpackets
        int length = 0;
        for (int j = 0; j < 11; j++) {
            length <<= 1;
            length |= in[*i + j];
        }
        *i += 11;
        printf("operator packet, num packets %d\n", length);
        int sub_packets = 0;
        for (int j = 0; j < length; j++) {
            printf("reading sub packet at off %d, num %d\n", *i, sub_packets++);
            read_packet(in, i, version);
        }
    } else {
        //15 bits to read sub packets
        int length = 0;
        for (int j = 0; j < 15; j++) {
            length <<= 1;
            length |= in[*i + j];
        }
        *i += 15;
        printf("operator packet, bit length %d\n", length);
        int initial_i = *i;
        int sub_packets = 0;
        while (*i - initial_i < length) {
            printf("reading sub packet at off %d, num %d\n", *i, sub_packets++);
            read_packet(in, i, version);
        }
    }
}

int main(void) {
    int *in = alloc_input("../../day16/resources/input.txt");
    int i = 0;
    for (i = 0; i < LENGTH * 4; i++) {
        printf("%d", in[i]);
    }
    i = 0;
    printf("\n");
    int version = 0;
    read_packet(in, &i, &version);
//    while (i < LENGTH * 4) {
//        printf("packet version %d, packet_type_id %d\n", packet_version, packet_type_id);
//    }
    printf("version_numbers %d\n", version);
    dealloc_input(in);
    return 0;
}