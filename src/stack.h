#ifndef STACK_H
#define STACK_H

struct node {
    int value;
    struct node *next_node;
};

struct stack {
    struct node *begin_node;
};

struct stack *init_my(int value);

void push(struct stack *my_st, int value);

int pop(struct stack *my_st);

void destroy(struct stack *my_st);
#endif