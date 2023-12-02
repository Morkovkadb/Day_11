#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "door_struct.h"

#define DOORS_COUNT 15
#define MAX_ID_SEED 10000

void initialize_doors(struct door *doors);
void door_sort(struct door *doors);
void swap_door(struct door *door1, struct door *door2);
void print_door(struct door doors[DOORS_COUNT]);
void close_all_door(struct door *doors);
int main() {
    struct door doors[DOORS_COUNT];

    initialize_doors(doors);

    door_sort(doors);
    close_all_door(doors);
    print_door(doors);
    return 0;
}

// Doors initialization function
// ATTENTION!!!
// DO NOT CHANGE!
void initialize_doors(struct door *doors) {
    srand(time(0));

    int seed = rand() % MAX_ID_SEED;
    for (int i = 0; i < DOORS_COUNT; i++) {
        doors[i].id = (i + seed) % DOORS_COUNT;
        doors[i].status = rand() % 2;
    }
}

void door_sort(struct door *doors) {
    for (int i = 0; i < DOORS_COUNT; ++i) {
        for (int j = 0; j < DOORS_COUNT - 1; ++j) {
            if (doors[j].id > doors[j + 1].id) {
                swap_door(&doors[j], &doors[j + 1]);
            }
        }
    }
}

void swap_door(struct door *door1, struct door *door2) {
    struct door temp = *door1;
    *door1 = *door2;
    *door2 = temp;
}

void print_door(struct door doors[DOORS_COUNT]) {
    for (int i = 0; i < DOORS_COUNT; ++i) {
        printf("%d, %d\n", doors[i].id, doors[i].status);
    }
}

void close_all_door(struct door *doors) {
    for (int i = 0; i < DOORS_COUNT; ++i) {
        if (doors[i].status == 1) {
            doors[i].status = 0;
        }
    }
}