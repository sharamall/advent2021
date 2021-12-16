//
// Created by shara on 2021-12-15.
//

#include "day15.h"
#include <stdio.h>
#include "shared.h"
#include <limits.h>

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
    if (to_visit_next && to_visit_next->size > 0) {
        process_next_iteration(in, &to_visit_next);
        dealloc_list(&to_visit_next, 0);
    }
}

void print_paths(input *in) {
    for (int x = 0; x < in->side_length; x++) {
        for (int y = 0; y < in->side_length; y++) {
            node *n = in->arr[x + y * in->side_length];
            if (n->distance < INT_MAX) {
                printf("path for node %d, distance %d: ", n->risk, n->distance);
                node *prev = n;
                while (prev != in->start) {
                    printf("%d ", prev->risk);
                    prev = prev->prev;
                }
                printf("%d \n", prev->risk);
            }
        }
    }
    printf("\n");
}

void print_nodes(input *in) {
    for (int x = 0; x < in->side_length; x++) {
        for (int y = 0; y < in->side_length; y++) {
            node *n = in->arr[x + y * in->side_length];
            if (!n) {
                printf("\n\nnull in print_node x, y [%d,%d]\n", x, y);
            }
            printf("[%d,%d]", n->risk, n->distance);
        }
        printf("\n");
    }
    printf("\n");
}

int main(void) {
    input *in = alloc_input("../../day15/resources/input.txt");
    in->start->distance = 0;
    list *l = 0;
    push_back(&l, in->start);
    process_next_iteration(in, &l);
//    print_nodes(in);
//    print_paths(in);
    dealloc_list(&l, 0);
    printf("end dist %d\n", in->end->distance);

    dealloc_input(in);
    return 0;
}
