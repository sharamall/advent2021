//
// Created by shara on 2021-12-15.
//

#include "day15.h"
#include <stdio.h>
#include "shared.h"

int process_node(node *cur, node *next) {
    if (next) {
        int distance = cur->distance + next->risk;
        if (distance < next->distance) {
            next->distance = distance;
            next->prev = cur;
            return 1;
        }
        return 0;
    }
    return 0;
}

void process_next_iteration(input *in, list **l) {
    list *to_visit_next = 0, *to_visit = *l;

    for (int i = 0; i < to_visit->size; i++) {
        node *cur = to_visit->items[i];
        if (process_node(cur, cur->up)) {
            push_back(&to_visit_next, cur->up);
        }
        if (process_node(cur, cur->down)) {
            push_back(&to_visit_next, cur->down);
        }
        if (process_node(cur, cur->right)) {
            push_back(&to_visit_next, cur->right);
        }
        if (process_node(cur, cur->left)) {
            push_back(&to_visit_next, cur->left);
        }
    }
    if (!in->end->prev) {
        process_next_iteration(in, &to_visit_next);
    }
    dealloc_list(&to_visit_next, 0);
}

int main(void) {
    input *in = alloc_input("../../day15/resources/input.txt");
    in->start->distance = 0;
    list *l = 0;
    push_back(&l, in->start);
    process_next_iteration(in, &l);
    dealloc_list(&l, 0);
    printf("end dist %d\n", in->end->distance);

    dealloc_input(in);
    return 0;
}
