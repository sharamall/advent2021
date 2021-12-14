//
// Created by shara on 2021-12-12.
//
#include <stdio.h>
#include "day9.h"
#include <stdlib.h>
#include "shared.h"

void calc_basin_size(location *in, int cur, int basin_offset) {
    if (in[cur].val != 9 && !in[cur].marked) {
        in[basin_offset].sum_of_basin++;
        in[cur].marked = 1;
        int y = cur / WIDTH;
        int x = cur % WIDTH;
        if (x > 0) {
            calc_basin_size(in, cur - 1, basin_offset);
        }
        if (x < WIDTH - 1) {
            calc_basin_size(in, cur + 1, basin_offset);
        }
        if (y > 0) {
            calc_basin_size(in, cur - WIDTH, basin_offset);
        }
        if (y < HEIGHT - 1) {
            calc_basin_size(in, cur + WIDTH, basin_offset);
        }
    }
}

int main(void) {
    location *in = alloc_input("../../day9/resources/input.txt");
    list *l = 0;

    int sum = 0;
    int x_max = WIDTH;
    int y_max = HEIGHT;
    for (int x = 0; x < x_max; x++) {
        for (int y = 0; y < y_max; y++) {
            int val = in[x + y * x_max].val;
            int left = -1, right = -1, up = -1, down = -1;
            if (x > 0) {
                left = in[x - 1 + y * x_max].val;
            }
            if (x < x_max - 1) {
                right = in[x + 1 + y * x_max].val;
            }
            if (y > 0) {
                up = in[x + (y - 1) * x_max].val;
            }
            if (y < y_max - 1) {
                down = in[x + (y + 1) * x_max].val;
            }
            if ((left == -1 || val < left) && (right == -1 || val < right) && (up == -1 || val < up) && (down == -1 || val < down)) {
                sum += val + 1;
                int *m_val = malloc(sizeof(int));
                *m_val = x + y * WIDTH;
                push_back(&l, m_val);
            }
        }
    }
    int top1 = 0, top2 = 0, top3 = 0;
    for (int i = 0; i < l->size; i++) {
        void *p_int = l->items[i];
        int cur = *((int *)p_int);
        calc_basin_size(in, cur, i);
        int basin_size = in[i].sum_of_basin;
        if (basin_size >= top1) {
            top3 = top2;
            top2 = top1;
            top1 = basin_size;
        } else if (basin_size >= top2) {
            top3 = top2;
            top2 = basin_size;
        } else if (basin_size >= top3) {
            top3 = basin_size;
        }
        free(l->items[i]);
    }
    free(l->items);
    free(l);
    dealloc_input(in);
    printf("product %d\n", top1 * top2 * top3);
    return 0;
}
