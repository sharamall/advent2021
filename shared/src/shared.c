//
// Created by shara on 2021-12-15.
//

#include "shared.h"
#include <stdlib.h>
#include <string.h>

void push_back(list **pp_l, void *item) {
    if (pp_l) {
        list *p_l = *pp_l;
        if (!p_l) {
            p_l = malloc(sizeof(list));
            p_l->items = malloc(sizeof(void *) * 1);
            p_l->capacity = 1;
            p_l->size = 0;
        } else if (p_l->size == p_l->capacity) {
            void **new_arr = malloc(sizeof(void *) * p_l->capacity * 2);
            memcpy(new_arr, p_l->items, p_l->capacity * sizeof(void *));
            memset(new_arr + p_l->size, 0, p_l->capacity);
            free(p_l->items);
            p_l->items = new_arr;
            p_l->capacity *= 2;
        }
        p_l->items[p_l->size++] = item;
        *pp_l = p_l;
    }
}