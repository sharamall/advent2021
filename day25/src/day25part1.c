//
// Created by shara on 2021-12-25.
//

#include "day25.h"
#include <stdio.h>
#include "shared.h"
#include <stdlib.h>

void print(const char *in) {
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            if (in[x + y * WIDTH] == 2) {
                printf(">");
            } else if (in[x + y * WIDTH]) {
                printf("v");
            } else {
                printf(".");
            }
        }
        printf("\n");
    }
    printf("\n");
}

typedef struct {
    int index, next_index;
} to_move;

int main(void) {
    char *in = alloc_input("../../day25/resources/input.txt");
    print(in);
    int moves;
    int iterations = 0;
    do {
        moves = 0;
        iterations++;
        list *l = 0;
        for (int y = 0; y < HEIGHT; y++) {
            for (int x = 0; x < WIDTH; x++) {
                int index = x + y * WIDTH;
                if (in[index] == 2) {
                    int next_index = (x + 1) % WIDTH + y * WIDTH;
                    if (!in[next_index]) {
                        to_move *t = malloc(sizeof(to_move));
                        t->index = index;
                        t->next_index = next_index;
                        moves++;
                        push_back(&l, t);
                    }
                }
            }
        }
        if (l) {
            for (int i = 0; i < l->size; i++) {
                to_move *t = l->items[i];
                in[t->next_index] = 2;
                in[t->index] = 0;
            }
        }
        dealloc_list(&l, 1);
        l = 0;
        print(in);

        for (int y = 0; y < HEIGHT; y++) {
            for (int x = 0; x < WIDTH; x++) {
                int index = x + y * WIDTH;
                if (in[index] == 1) {
                    int next_index = x + ((y + 1) % HEIGHT) * WIDTH;
                    if (!in[next_index]) {
                        to_move *t = malloc(sizeof(to_move));
                        t->index = index;
                        t->next_index = next_index;
                        moves++;
                        push_back(&l, t);
                    }
                }
            }
        }
        if (l) {
            for (int i = 0; i < l->size; i++) {
                to_move *t = l->items[i];
                in[t->next_index] = 1;
                in[t->index] = 0;
            }
        }
        dealloc_list(&l, 1);
        print(in);

    } while (moves);
    printf("iterations %d\n", iterations);
    dealloc_input(in);
    return 0;
}