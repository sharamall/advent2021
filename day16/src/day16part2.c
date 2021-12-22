//
// Created by shara on 2021-12-16.
//
#include "day16.h"
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

int64_t read_operator(int *in, int *i, int packet_type_id);

int64_t read_packet(int *in, int *i) {
    int packet_version = in[*i] << 2 | in[*i + 1] << 1 | in[*i + 2] << 0;
    *i += 3;
    int packet_type_id = in[*i] << 2 | in[*i + 1] << 1 | in[*i + 2] << 0;
    *i += 3;
    if (packet_type_id == 4) {
        // literal
        list *l = 0;
        int first;
        do {
            first = in[*i];
            int64_t val = in[*i + 1] << 3 | in[*i + 2] << 2 | in[*i + 3] << 1 | in[*i + 4] << 0;
            *i += 5;
            push_back(&l, val);
        } while (first);
        int64_t val = 0;
        for (int j = 0; j < l->size; j++) {
            val <<= 4;
            val |= (int64_t)l->items[j];
        }
        printf(" %ld ", val);
        dealloc_list(&l, 0);
        return val;
    } else {
        return read_operator(in, i, packet_type_id);
    }
}

int64_t read_operator(int *in, int *i, int packet_type_id) {
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
        if (packet_type_id == 0) {
            // sum
            printf(" ( ");
            int64_t sum = read_packet(in, i);
            for (int j = 1; j < length; j++) {
                printf(" + ");
                sum += read_packet(in, i);
            }
            printf(" ) \n");
            return sum;
        } else if (packet_type_id == 1) {
            // product
            printf(" ( ");
            int64_t product = read_packet(in, i);
            for (int j = 1; j < length; j++) {
                printf(" * ");
                product *= read_packet(in, i);
            }
            printf(" ) \n");
            return product;
        } else if (packet_type_id == 2) {
            // min
            printf(" min( ");
            int64_t min = read_packet(in, i);
            for (int j = 1; j < length; j++) {
                printf(" , ");
                int64_t result = read_packet(in, i);
                if (result < min) {
                    min = result;
                }
            }
            printf(" ) \n");
            return min;
        } else if (packet_type_id == 3) {
            // max
            printf(" max( ");
            int64_t max = read_packet(in, i);
            for (int j = 1; j < length; j++) {
                printf(" , ");
                int64_t result = read_packet(in, i);
                if (result > max) {
                    max = result;
                }
            }
            printf(" ) \n");
            return max;
        } else if (packet_type_id == 5) {
            // gt
            printf(" ( ");
            int64_t first = read_packet(in, i);
            printf(" > ");
            int64_t second = read_packet(in, i);
            printf(" ) \n");
            return first > second;
        } else if (packet_type_id == 6) {
            // lt
            printf(" ( ");
            int64_t first = read_packet(in, i);
            printf(" < ");
            int64_t second = read_packet(in, i);
            printf(" ) \n");
            return first < second;
        } else if (packet_type_id == 7) {
            // eq
            printf(" ( ");
            int64_t first = read_packet(in, i);
            printf(" == ");
            int64_t second = read_packet(in, i);
            printf(" ) \n");
            return first == second;
        }
    } else {
        //15 bits to read sub packets
        int length = 0;
        for (int j = 0; j < 15; j++) {
            length <<= 1;
            length |= in[*i + j];
        }
        *i += 15;
        int initial_i = *i;
        if (packet_type_id == 0) {
            // sum
            printf(" ( ");
            int64_t sum = read_packet(in, i);
            while (*i - initial_i < length) {
                printf(" + ");
                sum += read_packet(in, i);
            }
            printf(" )\n ");
            return sum;
        } else if (packet_type_id == 1) {
            // product
            printf(" ( ");
            int64_t product = read_packet(in, i);
            while (*i - initial_i < length) {
                printf(" * ");
                product *= read_packet(in, i);
            }
            printf(" )\n ");
            return product;
        } else if (packet_type_id == 2) {
            // min
            printf(" min( ");
            int64_t min = read_packet(in, i);
            while (*i - initial_i < length) {
                printf(" , ");
                int64_t result = read_packet(in, i);
                if (result < min) {
                    min = result;
                }
            }
            printf(" )\n ");
            return min;
        } else if (packet_type_id == 3) {
            // max
            printf(" max( ");
            int64_t max = read_packet(in, i);
            while (*i - initial_i < length) {
                printf(" , ");
                int64_t result = read_packet(in, i);
                if (result > max) {
                    max = result;
                }
            }
            printf(" )\n ");
            return max;
        } else if (packet_type_id == 5) {
            // gt
            printf(" ( ");
            int64_t first = read_packet(in, i);
            printf(" > ");
            int64_t second = read_packet(in, i);
            printf(" )\n ");
            return first > second;
        } else if (packet_type_id == 6) {
            // lt
            printf(" ( ");
            int64_t first = read_packet(in, i);
            printf(" < ");
            int64_t second = read_packet(in, i);
            printf(" )\n ");
            return first < second;
        } else if (packet_type_id == 7) {
            // eq
            printf(" ( ");
            int64_t first = read_packet(in, i);
            printf(" == ");
            int64_t second = read_packet(in, i);
            printf(" )\n ");
            return first == second;
        }
    }
    printf("invalid packet \n");
    exit(1);
}

int main(void) {
    int *in = alloc_input("../../day16/resources/input.txt");
    int i = 0;
    printf("\n");
    int64_t result = read_packet(in, &i);
    printf("result %ld\n", result);
    dealloc_input(in);
    return 0;
}