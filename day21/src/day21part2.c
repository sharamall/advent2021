//
// Created by shara on 2021-12-21.
//

#include "day21.h"
#include <stdio.h>
#define SCORE_LIMIT 21

typedef struct {
    int64_t p1_wins, p2_wins;
} results;

typedef struct {
    int p1_pos, p2_pos;
    int p1_score, p2_score;
    int roll_sum;
    int die_roll;
    int p1_turn;
} game;

void run_game(results *r, game g) {
    if (g.die_roll < 3) {
        for (; g.die_roll < 3;) {
            g.die_roll++;
            for (int i = 0; i < 3; i++) {
                g.roll_sum += i + 1;
                game new_game = g;
                run_game(r, new_game);
            }
        }
    } else {
        if (g.p1_turn) {
            g.p1_pos += g.roll_sum;
            if (g.p1_pos > 10) {
                g.p1_pos %= 10;
            }
            g.p1_score += g.p1_pos;
            if (g.p1_score >= SCORE_LIMIT) {
                r->p1_wins++;
                return;
            } else {
                g.p1_turn = 0;
                g.die_roll = 0;
                g.roll_sum = 0;
                run_game(r, g);
            }
        } else {
            g.p2_pos += g.roll_sum;
            if (g.p2_pos > 10) {
                g.p2_pos %= 10;
            }
            g.p2_score += g.p2_pos;
            if (g.p2_score >= SCORE_LIMIT) {
                r->p2_wins++;
                return;
            } else {
                g.p1_turn = 1;
                g.die_roll = 0;
                g.roll_sum = 0;
                run_game(r, g);
            }
        };
    }
}

int main(void) {
    int64_t in = read_input("../../day21/resources/input.txt");
    int p1 = in >> 32;
    int p2 = in & 0xFFFFFFFF;
    results r = {0, 0};
    game g = {p1, p2, 0, 0, 0, 0, 1};
    run_game(&r, g);
    printf("p1 wins %ld, p2 win %ld", r.p1_wins, r.p2_wins);
    return 0;
}