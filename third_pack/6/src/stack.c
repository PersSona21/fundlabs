#include "../include/stack.h"
#include <stdlib.h>
#include <stdio.h>


Stack* createStack(size_t capacity) {
    Stack *s = malloc(sizeof(Stack));
    if (!s) return NULL;
    s->data = malloc(sizeof(char) * capacity);
    if (!s->data) {
        free(s);
        return NULL;
    }
    s->index = -1;
    s->capacity = capacity;
    return s;
}

void push(Stack *s, char value) {
    if (!s) return;

    if (s->index + 1 >= s->capacity) {
        size_t new_capacity = s->capacity ? s->capacity * 2 : 16;
        char *tmp = realloc(s->data, new_capacity * sizeof(char));
        if (!tmp) return;
        s->data = tmp;
        s->capacity = new_capacity;
    }

    s->index++;
    s->data[s->index] = value;
}

char pop(Stack *s) {
    if (!s || s->index < 0) {
        return '\0';
    }
    char value = s->data[s->index];
    s->index--;
    return value;
}

char top(Stack *s) {
    if (!s || s->index < 0) {
        return '\0';
    }
    return s->data[s->index];
}

int isEmpty(Stack *s){
    if (!s) return 1;
    return s->index < 0;
}

void eraseStack(Stack *s){
    if (!s) return;
    free(s->data);
    free(s);
}