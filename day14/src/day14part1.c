//
// Created by shara on 2021-12-13.
//

#include "day14.h"
#include <stdio.h>
#include <string.h>
#include "shared.h"
#define ITERATIONS 40

void print(char *cur, int length) {
    for (int i = 0; i < length; i++) {
        printf("%c", cur[i]);
    }
    printf("\n");
}

int main(void) {
    input *in = alloc_input("../../day14/resources/input.txt");
    int *map = map_rules(in);
    int next_size = FIRST_LINE;
    char *to_process = in->start;
    print(to_process, next_size);
    for (int i = 0; i < ITERATIONS; i++) {
        list *to_insert = 0;
        for (int j = 0; j < next_size - 1; j++) {
            int next = map[chars_to_key(*(to_process + j), *(to_process + j + 1))];
            push_back(&to_insert, (char)next);
        }
        next_size += to_insert->size;
        char *next = malloc(sizeof(char) * (next_size + 1));
        next[next_size] = 0;
        for (int j = 0; j < next_size; j++) {
            if (j % 2) {
                next[j] = (char)(to_insert->items[j / 2]);
            } else {
                next[j] = to_process[j / 2];
            }
        }
        if (to_process != in->start) {
            free(to_process);
        }
        to_process = next;
        dealloc_list(&to_insert, 0);
        print(to_process, next_size);
    }
    free(map);
    int *frequency = malloc(sizeof(int) * 26);
    memset(frequency, -1, sizeof(int) * 26);
    int max = -999999999, min = 999999999;
    for (int i = 0; i < next_size; i++) {
        char cur = to_process[i];
        int index = cur - 65;
        frequency[index]++;
    }
    for (int i = 0; i < 26; i++) {
        if (frequency[i] != -1) {
            if (frequency[i] > max) {
                max = frequency[i];
            }
            if (frequency[i] < min) {
                min = frequency[i];
            }
        }
    }

    free(to_process);
    free(frequency);
    printf("max, min, %d, %d, max - min %d\n", max, min, max - min);
    dealloc_input(in);
    return 0;
}