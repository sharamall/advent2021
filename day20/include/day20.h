//
// Created by shara on 2021-12-25.
//

#ifndef ADVENT2021_DAY20_H
#define ADVENT2021_DAY20_H
#define ENHANCEMENT_LENGTH 512
#define IMAGE_SIZE 100
typedef struct {
    char *enhancement;
    char *image;
    int line_size;
} input;
input *alloc_input(const char *src, int iterations);
void dealloc_input(input *input);

#endif //ADVENT2021_DAY20_H
