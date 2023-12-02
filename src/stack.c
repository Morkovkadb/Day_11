#include "stack.h"

#include <stdio.h>
#include <stdlib.h>

struct stack *init_my(int value) {
    struct stack *my_stack = malloc(sizeof(struct stack));
    my_stack->begin_node = malloc(sizeof(struct node));
    my_stack->begin_node->value = value;
    my_stack->begin_node->next_node = NULL;
    return my_stack;
}

void push(struct stack *my_st, int value) {
    struct node *temp_node = my_st->begin_node;

    while (temp_node->next_node != NULL) {
        temp_node = temp_node->next_node;
    }

    temp_node->next_node = malloc(sizeof(struct node));
    temp_node->next_node->value = value;
    temp_node->next_node->next_node = NULL;
}

int pop(struct stack *my_st) {
    struct node *temp_node = my_st->begin_node;
    struct node *last = NULL;

    while (temp_node->next_node != NULL) {
        last = temp_node;
        temp_node = temp_node->next_node;
    }

    int ret_value = temp_node->value;

    if (last != NULL) {
        last->next_node = NULL;
    } else {
        my_st->begin_node = NULL;
    }

    free(temp_node);
    return ret_value;
}

void destroy(struct stack *my_st) {
    if (my_st == NULL) {
        return;
    }

    while (my_st->begin_node != NULL) {
        struct node *temp = my_st->begin_node->next_node;
        free(my_st->begin_node);
        my_st->begin_node = temp;
    }

    free(my_st);
}
