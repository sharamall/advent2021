//
// Created by shara on 2021-12-12.
//
#include "day10.h"
#include <stdio.h>
#include <stdlib.h>
#include "shared.h"
int main(void) {
    char **lines = alloc_input("../../day10/resources/input.txt");

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
        free(l->items);
        free(l);
    }
    printf("sum %d\n", illegal_sum);
    dealloc_input(lines);
    return 0;
}
