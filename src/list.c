#include "list.h"

#include <stdio.h>
#include <stdlib.h>

struct node* init(struct door* door) {
    struct node* temp = malloc(sizeof(struct node));
    temp->current_door = door;
    temp->next_elem = NULL;
    return temp;
}

struct node* add_door(struct node* root, struct door* door) {
    struct node* temp = malloc(sizeof(struct node));
    temp->current_door = door;
    temp->next_elem = NULL;

    if (root == NULL) {
        return temp;
    }

    struct node* last_node = root;
    while (last_node->next_elem != NULL) {
        last_node = last_node->next_elem;
    }

    last_node->next_elem = temp;
    return root;
}

struct node* find_door(int door_id, struct node* root) {
    struct node* temp = root;
    while (temp != NULL) {
        if (temp->current_door->id == door_id) {
            return temp;
        }
        temp = temp->next_elem;
    }
    return NULL;
}

struct node* remove_door(struct node* elem, struct node* root) {
    if (elem == root) {
        struct node* next_elem = root->next_elem;
        free(root->current_door);
        free(root);
        return next_elem;
    }

    struct node* temp = root;
    while (temp != NULL && temp->next_elem != elem) {
        temp = temp->next_elem;
    }

    if (temp != NULL) {
        struct node* next_elem = elem->next_elem;
        free(elem->current_door);
        free(elem);
        temp->next_elem = next_elem;
    }

    return root;
}

void destroy(struct node* root) {
    while (root != NULL) {
        struct node* next_elem = root->next_elem;
        free(root->current_door);
        free(root);
        root = next_elem;
    }
}