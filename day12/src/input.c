//
// Created by shara on 2021-12-13.
//
#include "day12.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

void read_node(FILE *f, char *arr, int line) {
    int i = 0;
    do {
        if (fscanf(f, "%c", arr + i) != 1) {
            printf("Bad input at line %d char %d\n", line, i);
            fclose(f);
            exit(1);
        }
        i++;
    } while (arr[i - 1] != '-' && arr[i - 1] != '\n');
    arr[i - 1] = 0;
    arr[i] = 0;
    printf("read %s\n", arr);
}

input *alloc_input(const char *file) {
    FILE *f = fopen(file, "r");
    if (f) {
        input *in = malloc(sizeof(input));
        in->paths = malloc(sizeof(path) * DATA_LENGTH * 2);
        in->nodes = 0;
        in->start = 0;
        in->end = 0;
        for (int i = 0; i < DATA_LENGTH; i++) {
            char from[6], to[6];
            memset(from, 0, sizeof(char) * 6);
            read_node(f, from, i);
            read_node(f, to, i);
            node *f_node = 0, *t_node = 0;
            if (in->nodes) {
                for (int n_off = 0; n_off < in->nodes->size; n_off++) {
                    if (!strcmp(((node *)(in->nodes->items[n_off]))->name, from)) {
                        f_node = in->nodes->items[n_off];
                    }
                    if (!strcmp(((node *)(in->nodes->items[n_off]))->name, to)) {
                        t_node = in->nodes->items[n_off];
                    }
                    if (f_node && t_node) {
                        break;
                    }
                }
            }
            if (!f_node) {
                f_node = malloc(sizeof(node));
                f_node->name = malloc(sizeof(char) * 6);
                memcpy(f_node->name, from, sizeof(char) * 6);
                f_node->big = f_node->name[0] / 97 == 0;
                f_node->visited = 0;
                push_back(&in->nodes, f_node);
                if (!in->start && !strcmp(f_node->name, "start")) {
                    in->start = f_node;
                }
                if (!in->end && !strcmp(f_node->name, "end")) {
                    in->end = f_node;
                }
            }
            if (!t_node) {
                t_node = malloc(sizeof(node));
                t_node->name = malloc(sizeof(char) * 6);
                memcpy(t_node->name, to, sizeof(char) * 6);
                t_node->big = t_node->name[0] / 97 == 0;
                t_node->visited = 0;
                push_back(&in->nodes, t_node);
                if (!in->end && !strcmp(t_node->name, "end")) {
                    in->end = t_node;
                }
                if (!in->start && !strcmp(t_node->name, "start")) {
                    in->start = t_node;
                }
            }
            in->paths[i * 2].from = f_node;
            in->paths[i * 2].to = t_node;
            in->paths[i * 2 + 1].from = t_node;
            in->paths[i * 2 + 1].to = f_node;
        }
        fclose(f);
        return in;
    } else {
        printf("Unable to open file.\n");
    }
    return 0;
}

void dealloc_input(input *in) {
    if (in) {
        if (in->paths) {
            free(in->paths);
        }
        for (int i = 0; i < in->nodes->size; i++) {
            node *n = in->nodes->items[i];
            free(n->name);
            free(n);
        }
        dealloc_list(&in->nodes, 0);
        free(in);
    }
}