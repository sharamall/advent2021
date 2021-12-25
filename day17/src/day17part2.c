//
// Created by shara on 2021-12-22.
//

#include "day17.h"
#include <stdio.h>

int calc_x_velocity(int edge) {
    if (edge < 0) {
        edge = -edge;
    }
    int val = 0;
    int inc = 1;
    int steps = 0;
    while (val < edge) {
        steps++;
        val += inc++;
    }
    return steps;
}

typedef struct {
    int steps, max_height;
} y_step_result;

y_step_result calc_y_steps(target *in, int up_speed) {
    y_step_result result;
    int y = 0;
    int steps = 0;
    while (y > in->y_min) {
        steps++;
        if (up_speed == 0) {
            result.max_height = y;
        }
        y += up_speed--;
        if (y >= in->y_min && y <= in->y_max) {
            result.steps = steps;
            return result;
        }
    }
    return (y_step_result){-1, 0};
}

int run_sim(target *t, int x_vel, int y_vel) {
    int x = 0, y = 0;
    while (x <= t->x_max && y >= t->y_min) {
        x += x_vel;
        if (x_vel > 0) {
            x_vel--;
        }
        y += y_vel--;
        if (x >= t->x_min && x <= t->x_max && y >= t->y_min && y <= t->y_max) {
            return 1;
        }
    }
    return 0;
}

int main(void) {
    target *in = alloc_input("../../day17/resources/input.txt");
    int x_min_velocity = calc_x_velocity(in->x_min);
    int x_max_velocity = calc_x_velocity(in->x_max);
    printf("x max, min %d %d\n", x_max_velocity, x_min_velocity);
    int y_max;
    for (y_max = -in->y_min; y_max >= in->y_min; y_max--) {
        y_step_result y_step_result = calc_y_steps(in, y_max);
        if (y_step_result.steps >= x_min_velocity) {
            break;
        }
    }
    int total = 0;
    for (int y = in->y_min; y <= y_max; y++) {
        for (int x = 1; x <= in->x_max; x++) {
            if (run_sim(in, x, y)) {
                total++;
            }
        }
    }
    printf("total %d\n", total);
    dealloc_input(in);
    return 0;
}