//
// Created by shara on 2021-12-19.
//

#include "day18.h"
#include "shared.h"
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct pair;
typedef struct pair pair;
struct pair {
    int v_l, v_r;
    pair *l, *r, *parent;
};

pair *read_pair(char *in, int *offset) {
    if (in[*offset] != '[') {
        printf("bad read at offset %d for char %s", *offset, in);
    }
    (*offset)++;
    pair *p = malloc(sizeof(pair));
    if (in[*offset] == '[') {
        p->l = read_pair(in, offset);
        p->l->parent = p;
        (*offset)++;
    } else {
        int val = 0;
        while (in[*offset] != ',') {
            val *= 10;
            val += in[*offset] - 48;
            (*offset)++;
        }
        (*offset)++;
        p->v_l = val;
        p->l = 0;
    }
    if (in[*offset] == '[') {
        p->r = read_pair(in, offset);
        p->r->parent = p;
        (*offset)++;
    } else {
        int val = 0;
        while (in[*offset] != ']') {
            val *= 10;
            val += in[*offset] - 48;
            (*offset)++;
        }

        (*offset)++;
        p->v_r = val;
        p->r = 0;
    }
    return p;
}

typedef struct {
    pair *p;
    int left;
} find_result;

find_result *find_deepest_right(pair *p) {
    if (p->r) {
        return find_deepest_right(p->r);
    }
    find_result *result = malloc(sizeof(find_result));
    *result = (find_result){p, 0};
    return result;
}

find_result *find_deepest_left(pair *p) {
    if (p->l) {
        return find_deepest_left(p->l);
    }
    find_result *result = malloc(sizeof(find_result));
    *result = (find_result){p, 1};
    return result;
}

find_result *find_left(pair *parent, pair *child) {
    if (parent) {
        if (parent->l) {
            if (parent->l != child) {
                return find_deepest_right(parent->l);
            } else {
                return find_left(parent->parent, parent);
            }
        } else {
            find_result *result = malloc(sizeof(find_result));
            *result = (find_result){parent, 1};
            return result;
        }
    } else {
        return 0;
    }
}

find_result *find_right(pair *parent, pair *child) {
    if (parent) {
        if (parent->r) {
            if (parent->r != child) {
                return find_deepest_left(parent->r);
            } else {
                return find_right(parent->parent, parent);
            }
        } else {
            find_result *result = malloc(sizeof(find_result));
            *result = (find_result){parent, 0};
            return result;
        }
    } else {
        return 0;
    }
}

void print_pair(pair *p) {
    printf("[");
    if (p->l) {
        print_pair(p->l);
    } else {
        printf("%d", p->v_l);
    }
    printf(",");
    if (p->r) {
        print_pair(p->r);
    } else {
        printf("%d", p->v_r);
    }
    printf("]");
}

void process_explode(pair *root) {
    find_result *left_result = find_left(root->parent, root);
    find_result *right_result = find_right(root->parent, root);
    if (left_result) {
        if (left_result->left) {
            left_result->p->v_l += root->v_l;
        } else {
            left_result->p->v_r += root->v_l;
        }
        free(left_result);
    }
    if (right_result) {
        if (right_result->left) {
            right_result->p->v_l += root->v_r;
        } else {
            right_result->p->v_r += root->v_r;
        }
        free(right_result);
    }
    if (root->parent) {
        if (root->parent->l == root) {
            root->parent->v_l = 0;
            root->parent->l = 0;
            free(root);
        } else {
            root->parent->v_r = 0;
            root->parent->r = 0;
            free(root);
        }
    }
}

typedef struct {
    int left, depth;
    pair *p;

} split_action;

void process_split(split_action *action) {
    pair *new_pair = malloc(sizeof(pair));
    new_pair->l = 0;
    new_pair->r = 0;
    if (action->left) {
        new_pair->v_l = action->p->v_l / 2;
        new_pair->v_r = action->p->v_l / 2 + action->p->v_l % 2;
    } else {
        new_pair->v_l = action->p->v_r / 2;
        new_pair->v_r = action->p->v_r / 2 + action->p->v_r % 2;
    }

    new_pair->parent = action->p;
    if (action->left) {
        action->p->l = new_pair;
    } else {
        action->p->r = new_pair;
    }
    if (action->depth >= 4) {
        process_explode(new_pair);
    }
}

void process_for_explodes(pair *root, int depth) {
    if (depth >= 4) {
        process_explode(root);
    } else {
        if (root->l) {
            process_for_explodes(root->l, depth + 1);
        }
        if (root->r) {
            process_for_explodes(root->r, depth + 1);
        }
    }
}

int process_for_splits(pair *root, int depth) {
    int result = 0;
    if (root->l) {
        result = process_for_splits(root->l, depth + 1);
    } else if (root->v_l > 9) {
        split_action action = {1, depth + 1, root};
        process_split(&action);
        result = 1;
    }
    if (!result) {
        if (root->r) {
            result = process_for_splits(root->r, depth + 1);
        } else if (root->v_r > 9) {
            split_action action = {0, depth + 1, root};
            process_split(&action);
            result = 1;
        }
    }
    return result;
}

int calculate_magnitude(pair *root) {
    int l, r;
    if (root->l) {
        l = calculate_magnitude(root->l) * 3;
    } else {
        l = root->v_l * 3;
    }
    if (root->r) {
        r = calculate_magnitude(root->r) * 2;
    } else {
        r = root->v_r * 2;
    }
    return l + r;
}

void free_pairs(pair *p) {
    if (p->l) {
        free_pairs(p->l);
    }
    if (p->r) {
        free_pairs(p->r);
    }
    free(p);
}

pair *dup_pair(pair *p) {
    if (p) {
        pair *result = malloc(sizeof(pair));
        result->parent = 0;
        if (p->l) {
            result->l = dup_pair(p->l);
            result->l->parent = result;
        } else {
            result->v_l = p->v_l;
            result->l = 0;
        }
        if (p->r) {
            result->r = dup_pair(p->r);
            result->r->parent = result;
        } else {
            result->v_r = p->v_r;
            result->r = 0;
        }
        return result;
    } else {
        return 0;
    }
}

int main(void) {
    input *in = alloc_input("../../day18/resources/input.txt");
    pair **pairs = malloc(sizeof(pair *) * LENGTH);
    int offset;
    for (int i = 0; i < LENGTH; i++) {
        offset = 0;
        pairs[i] = read_pair(in->lines[i], &offset);
        pairs[i]->parent = 0;
    }
    int max_x, max_y;
    int max_mag = INT_MIN;
    for (int i = 0; i < LENGTH - 1; i++) {
        for (int j = i + 1; j < LENGTH; j++) {
            pair *addition_pair = malloc(sizeof(pair));
            addition_pair->l = dup_pair(pairs[i]);
            addition_pair->r = dup_pair(pairs[j]);
            addition_pair->l->parent = addition_pair;
            addition_pair->r->parent = addition_pair;
            addition_pair->parent = 0;
            int result = 1;
            while (result) {
                process_for_explodes(addition_pair, 0);
                result = process_for_splits(addition_pair, 0);
            }
            int mag = calculate_magnitude(addition_pair);
            if (mag > max_mag) {
                max_mag = mag;
                max_x = i;
                max_y = j;
            }
            free_pairs(addition_pair->l);
            free_pairs(addition_pair->r);
            addition_pair->l = dup_pair(pairs[j]);
            addition_pair->r = dup_pair(pairs[i]);
            addition_pair->l->parent = addition_pair;
            addition_pair->r->parent = addition_pair;
            result = 1;
            while (result) {
                process_for_explodes(addition_pair, 0);
                result = process_for_splits(addition_pair, 0);
            }
            mag = calculate_magnitude(addition_pair);
            if (mag > max_mag) {
                max_mag = mag;
                max_x = i;
                max_y = j;
            }
            free_pairs(addition_pair->l);
            free_pairs(addition_pair->r);
            free(addition_pair);
        }
    }
    printf("max mag %d, x %d y %d\n", max_mag, max_x, max_y);
    for (int i = 0; i < LENGTH; i++) {
        free_pairs(pairs[i]);
    }
    free(pairs);
    dealloc_input(in);
    return 0;
}