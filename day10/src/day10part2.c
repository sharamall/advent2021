//
// Created by shara on 2021-12-13.
//

#include "day10.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "shared.h"

int main(void) {
    char **lines = alloc_input("../../day10/resources/input.txt");
    list *scores = 0;
    int illegal_sum = 0;
    for (int i = 0; i < IN_LENGTH; i++) {
        list *l = 0;
        int c_off = 0;
        while (lines[i][c_off]) {
            char c = lines[i][c_off];
            if (c == '(' || c == '[' || c == '{' || c == '<') {
                push_back(&l, lines[i][c_off]);
            } else {
                char back_char = (char)(l->items[l->size - 1]);
                if (c == ')') {
                    if (back_char == '(') {
                        l->size--;
                    } else {
                        illegal_sum += 3;
                        break;
                    }
                } else if (c == ']') {
                    if (back_char == '[') {
                        l->size--;
                    } else {
                        illegal_sum += 57;
                        break;
                    }
                } else if (c == '}') {
                    if (back_char == '{') {
                        l->size--;
                    } else {
                        illegal_sum += 1197;
                        break;
                    }
                } else if (c == '>') {
                    if (back_char == '<') {
                        l->size--;
                    } else {
                        illegal_sum += 25137;
                        break;
                    }
                }
            }
            c_off++;
        }
        if (!lines[i][c_off] && l->size > 0) {
            int64_t score = 0;
            for (int j = l->size - 1; j >= 0; j--) {
                char back_char = (char)(l->items[j]);
                if (back_char == '(') {
                    score *= 5;
                    score += 1;
                } else if (back_char == '[') {
                    score *= 5;
                    score += 2;
                } else if (back_char == '{') {
                    score *= 5;
                    score += 3;
                } else if (back_char == '<') {
                    score *= 5;
                    score += 4;
                }
            }
            push_back(&scores, score);
            int j;
            for (j = 0; j < scores->size; j++) {
                long long int bigger_score = (long long)(scores->items[j]);
                if (bigger_score > score) {
                    memcpy(scores->items + j + 1, scores->items + j, sizeof(void *) * (scores->size - j - 1));
                    scores->items[j] = score;
                    break;
                }
            }
        }
        free(l->items);
        free(l);
    }
    printf("middle sum %lld\n", (long long)(scores->items[scores->size / 2]));
    free(scores->items);
    free(scores);
    dealloc_input(lines);
    return 0;
}
