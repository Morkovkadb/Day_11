#include "list.h"

#include <stdio.h>
#include <stdlib.h>

int doors_equal(struct door* door1, struct door* door2) {
    if (door1->id == door2->id && door1->status == door2->status) {
        return 1;
    }
    return 0;
}

int validate_door_list(struct node* root, struct door** doors, int num_doors) {
    struct node* temp = root;
    int i = 0;

    while (temp != NULL && i < num_doors) {
        if (!doors_equal(temp->current_door, doors[i])) {
            return 0;
        }
        temp = temp->next_elem;
        i++;
    }

    return (temp == NULL && i == num_doors);
}

int test_add_door() {
    struct door* door1 = malloc(sizeof(struct door));
    door1->id = 1;
    door1->status = 0;
    struct node* root = init(door1);

    struct door* new_door = malloc(sizeof(struct door));
    new_door->id = 2;
    new_door->status = 0;
    root = add_door(root, new_door);

    struct door* expected_doors[2] = {door1, new_door};

    int result = validate_door_list(root, expected_doors, 2);

    destroy(root);

    return result;
}

int test_remove_door() {
    struct door* door1 = malloc(sizeof(struct door));
    door1->id = 1;
    door1->status = 0;

    struct door* door2 = malloc(sizeof(struct door));
    door2->id = 2;
    door2->status = 0;

    struct door* door3 = malloc(sizeof(struct door));
    door3->id = 3;
    door3->status = 0;

    struct node* root = init(door1);
    root = add_door(root, door2);
    root = add_door(root, door3);

    root = remove_door(find_door(2, root), root);

    struct door* expected_doors[2] = {door1, door3};

    int result = validate_door_list(root, expected_doors, 2);

    destroy(root);

    return result;
}

int main() {
    int add_door_result = test_add_door();
    printf("add_door test: %s\n", add_door_result ? "SUCCESS" : "FAIL");

    int remove_door_result = test_remove_door();
    printf("remove_door test: %s\n", remove_door_result ? "SUCCESS" : "FAIL");

    if (add_door_result && remove_door_result) {
        return 0;
    } else {
        return 1;
    }
}