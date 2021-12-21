//
// Created by shara on 2021-12-20.
//
#include "day14.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#define ITERATIONS 40

int64_t *get_p_for_cache(int64_t *cache, int16_t key, char c, int depth) {
    int64_t *p = cache + depth + (int64_t)key * (ITERATIONS + 1) + (c - 65) * (ITERATIONS + 1) * 65535L;
    return p;
}

void process_polymer(input *in, char a, char b, int64_t *cache, int *map, int depth) {
    int16_t key = chars_to_key(a, b);
    if (depth < ITERATIONS) {
        char c = map[key];
        if (*get_p_for_cache(cache, key, 'A' + 26, depth) == -1) {
            *get_p_for_cache(cache, key, 'A' + 26, depth) = 0;
            process_polymer(in, a, c, cache, map, depth + 1);
            process_polymer(in, c, b, cache, map, depth + 1);
            for (int i = 0; i < 26; i++) {
                int64_t *first_polymer = get_p_for_cache(cache, chars_to_key(a, c), 'A' + i, depth + 1);
                int64_t *second_polymer = get_p_for_cache(cache, chars_to_key(c, b), 'A' + i, depth + 1);
                int64_t *p = get_p_for_cache(cache, key, 'A' + i, depth);
                if (*first_polymer != -1) {
                    if (*p == -1) {
                        *p = 0;
                    }
                    *p += *first_polymer;
                }
                if (*second_polymer != -1) {
                    if (*p == -1) {
                        *p = 0;
                    }
                    *p += *second_polymer;
                }
            }
            *(get_p_for_cache(cache, key, c, depth)) -= 1;
        }
    } else {
        if (*get_p_for_cache(cache, key, 'A' + 26, depth) == -1) {
            *get_p_for_cache(cache, key, 'A' + 26, depth) = 0;

            if (*get_p_for_cache(cache, key, a, depth) == -1) {
                *get_p_for_cache(cache, key, a, depth) = 0;
            }
            if (*get_p_for_cache(cache, key, b, depth) == -1) {
                *get_p_for_cache(cache, key, b, depth) = 0;
            }
            *get_p_for_cache(cache, key, a, depth) += 1;
            *get_p_for_cache(cache, key, b, depth) += 1;
        }
    }
}

int main(void) {
    input *in = alloc_input("../../day14/resources/input.txt");
    int64_t *cache = malloc(sizeof(int64_t) * 65535 * 27 * (ITERATIONS + 1));
    memset(cache, -1, sizeof(int64_t) * 65535 * 27 * (ITERATIONS + 1));
    int *map = map_rules(in);
    for (int i = 0; i < FIRST_LINE - 1; i++) {
        char first = in->start[i];
        char second = in->start[i + 1];
        process_polymer(in, first, second, cache, map, 0);
    }
    int64_t *frequency = malloc(sizeof(int64_t) * 26);
    memset(frequency, -1, sizeof(int64_t) * 26);
    for (int i = 0; i < FIRST_LINE - 1; i++) {
        char first = in->start[i];
        char second = in->start[i + 1];
        for (int j = 0; j < 26; j++) {
            int64_t *p = get_p_for_cache(cache, chars_to_key(first, second), 'A' + j, 0);
            if (*p != -1) {
                if (frequency[j] == -1) {
                    frequency[j] = 0;
                }
                frequency[j] += *p;
            }
        }
    }
    free(map);
    int64_t max = LLONG_MIN, min = LLONG_MAX;
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

    free(cache);
    free(frequency);
    printf("max, min, %ld, %ld, max - min %ld\n", max, min, max - min);
    dealloc_input(in);
}
