//
// Created by shara on 2021-12-13.
//

#include "day13.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(void) {
    input *in = alloc_input("../../day13/resources/input.txt");
    printf("total %d\n", calc_dots(in, FOLD_ROWS));

    return 0;
}