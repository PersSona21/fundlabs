#include "../include/validation.h"
#include "../include/vector.h"
#include <stddef.h>


Vector create_vector(size_t initial_capacity, 
    void *(*CopyFunc)(void *), void (*DeleteFunc)(void *)){
        Vector v;
        v.capacity = initial_capacity;
        v.size = 0;
        v.CopyVoidPtr = CopyFunc;
        v.DeleteVoidPtr = DeleteFunc;
        v.data = malloc(initial_capacity * sizeof(void *));
        if (!v.data) exit(EXIT_FAILURE);
        return v;
}


void erase_vector(Vector *v){
    if (!v->DeleteVoidPtr){
        exit(FUNCTION_ERROR);
    }
    for(size_t i = 0; i < v->size; i++){
        v->DeleteVoidPtr(((void**)v->data)[i]);
    }
    free(v->data);
    v->size = 0;
    v->capacity = 0;
    v->data = NULL;
}

int is_equal_vector(const Vector *v1, const Vector *v2){
    if(v1->size != v2->size) return 0;
    for (size_t i = 0; i < v1->size; i++){
        void *a = ((void**)v1->data)[i];
        void *b = ((void**)v2->data)[i];
        if (*(int*)a != *(int*)b) return 0;
    }
    return 1;
}

void copy_vector(Vector *dest, const Vector *src){
    dest->CopyVoidPtr = src->CopyVoidPtr;
    dest->DeleteVoidPtr = src->DeleteVoidPtr;
    dest->size = src->size;
    dest->capacity = src->capacity;
    dest->data = malloc(sizeof(void *) * src->capacity);
    if (!dest->data) exit(EXIT_FAILURE);
    if (!dest->CopyVoidPtr) exit(FUNCTION_ERROR);
    for (size_t i = 0; i < src->size; i++){
        void *elem = ((void **)src->data)[i];
        ((void **)dest->data)[i] = src->CopyVoidPtr(elem);
    }
}

Vector *copy_vector_new(const Vector *src){
    Vector *v = malloc(sizeof(Vector));
    if (!v) exit(EXIT_FAILURE);
    copy_vector(v, src);
    return v;
}

void push_back_vector(Vector *v, void *value){
    if (v->size >= v->capacity){
        size_t new_capacity = v->capacity * 2 + 1;
        void *new_data = realloc(v->data, new_capacity * sizeof(void *));
        if (!new_data) exit(EXIT_FAILURE);
        v->data = new_data;
        v->capacity = new_capacity;
    }
    if (!v->CopyVoidPtr) exit(FUNCTION_ERROR);
    ((void **)v->data)[v->size++] = v->CopyVoidPtr(value);
}

void delete_at_vector(Vector *v, size_t index) {
    if (index >= v->size) return;
    void *elem = ((void **)v->data)[index];
    if (v->DeleteVoidPtr) v->DeleteVoidPtr(elem);
    memmove(&((void **)v->data)[index],
        &((void **)v->data)[index + 1],
        (v->size - index - 1) * sizeof(void *));
    v->size--;
}

void *get_at_vector(const Vector *v, size_t index) {
    if (index >= v->size) return NULL;
    return ((void **)v->data)[index];
}

void delete_vector(Vector *v){
    erase_vector(v);
}