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

int main(void) {
    target *in = alloc_input("../../day17/resources/input.txt");
    int x_min_velocity = calc_x_velocity(in->x_min);
    int x_max_velocity = calc_x_velocity(in->x_max);
    printf("x max, min %d %d\n", x_max_velocity, x_min_velocity);
    for (int y = -in->y_min; y >= in->y_min; y--) {
        y_step_result y_step_result = calc_y_steps(in, y);
        if (y_step_result.steps >= x_min_velocity) {
            printf("this should work [%d,%d], steps %d, height %d\n", x_max_velocity, y, y_step_result.steps, y_step_result.max_height);
            break;
        }
    }

    dealloc_input(in);
    return 0;
}