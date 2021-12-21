//
// Created by shara on 2021-12-21.
//

#include "day21.h"
#include <stdio.h>

int roll_die(int *die, int *die_rolls) {
    int _1, _2, _3;
    _1 = (*die)++;
    if (*die > 100) {
        *die %= 100;
    }
    _2 = (*die)++;
    if (*die > 100) {
        *die %= 100;
    }
    _3 = (*die)++;
    if (*die > 100) {
        *die %= 100;
    }
    *die_rolls += 3;
    return _1 + _2 + _3;
}

int main(void) {
    int64_t in = read_input("../../day21/resources/input.txt");
    int p1 = in >> 32;
    int p2 = in & 0xFFFFFFFF;
    int p1_score = 0, p2_score = 0;
    int die = 1;
    int die_rolls = 0;
    while (p1_score < 1000 && p2_score < 1000) {
        int die_roll = roll_die(&die, &die_rolls);
        if (die_roll > 10) {
            die_roll %= 10;
        }
        p1 += die_roll;
        if (p1 > 10) {
            p1 %= 10;
        }
        p1_score += p1;
        if (p1_score >= 1000) {
            break;
        }
        die_roll = roll_die(&die, &die_rolls);
        if (die_roll > 10) {
            die_roll %= 10;
        }
        p2 += die_roll;
        if (p2 > 10) {
            p2 %= 10;
        }
        p2_score += p2;
    }
    int loser_score = p1_score > p2_score ? p2_score : p1_score;
    printf("loser %d, rolls %d, product %d", loser_score, die_rolls, die_rolls * loser_score);
    return 0;
}