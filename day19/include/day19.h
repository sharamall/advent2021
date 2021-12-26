//
// Created by shara on 2021-12-25.
//

#ifndef ADVENT2021_DAY19_H
#define ADVENT2021_DAY19_H
#define SCANNERS 5
#define OVERLAP 12

typedef struct {
    int x, y, z;
} vector3;

typedef struct {
    vector3 pos;
    vector3 rot;
    vector3 *beacons;
} scanner;

scanner *alloc_input(const char *file);
void dealloc_input(scanner *scanners);

#endif //ADVENT2021_DAY19_H
