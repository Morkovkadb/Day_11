#include "stack.h"

#include <stdio.h>
#include <stdlib.h>

#define SUCCESS 0
#define FAIL -1

int test_push() {
    struct stack *my_stack = init_my(5);

    if (my_stack->begin_node == NULL || my_stack->begin_node->value != 5) {
        printf("Ошибка: Неправильная инициализация стека.\nFAIL\n");
        destroy(my_stack);
        return FAIL;
    }

    push(my_stack, 10);
    push(my_stack, 15);
    push(my_stack, 20);

    if (my_stack->begin_node->next_node == NULL || my_stack->begin_node->next_node->value != 10 ||
        my_stack->begin_node->next_node->next_node == NULL ||
        my_stack->begin_node->next_node->next_node->value != 15 ||
        my_stack->begin_node->next_node->next_node->next_node == NULL ||
        my_stack->begin_node->next_node->next_node->next_node->value != 20) {
        printf("Ошибка: Неправильное добавление элементов в стек.\nFAIL\n");
        destroy(my_stack);
        return FAIL;
    }

    destroy(my_stack);
    printf("Тест push пройден успешно.\nSUCCES\n");
    return SUCCESS;
}

int test_pop() {
    struct stack *my_stack = init_my(5);

    push(my_stack, 10);
    push(my_stack, 15);
    push(my_stack, 20);

    int popped_value1 = pop(my_stack);
    int popped_value2 = pop(my_stack);
    int popped_value3 = pop(my_stack);

    if (popped_value1 != 20 || popped_value2 != 15 || popped_value3 != 10) {
        printf("Ошибка: Неправильное удаление элементов из стека.\nFAIL\n");
        destroy(my_stack);
        return FAIL;
    }

    if (my_stack->begin_node == NULL || my_stack->begin_node->value != 5) {
        printf("Ошибка: Неправильное состояние стека после удаления элементов.\nFAIL\n");
        destroy(my_stack);
        return FAIL;
    }

    destroy(my_stack);
    printf("Тест pop пройден успешно.\nSUCCES\n");
    return SUCCESS;
}

int main() {
    int push_result = test_push();
    int pop_result = test_pop();

    if (push_result == SUCCESS && pop_result == SUCCESS) {
        printf("Все тесты пройдены успешно.\n");
        return EXIT_SUCCESS;
    } else {
        printf("Произошла ошибка: не все тесты пройдены.\n");
        return EXIT_FAILURE;
    }
}