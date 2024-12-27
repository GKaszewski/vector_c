#include <stdio.h>
#include <string.h>
#include "vector.h"

void init_vector(vector* v, size_t element_size, size_t capacity) {
    v->data = malloc(element_size * capacity);
    v->size = 0;
    v->capacity = capacity;
    v->element_size = element_size;
}

void free_vector(vector* v) {
    free(v->data);
    v->data = NULL;
    v->size = 0;
    v->capacity = 0;
    v->element_size = 0;
}

void push(vector* v, void* element) {
    if (v->size == v->capacity) {
        resize(v, v->capacity * 2);
    }
    memcpy(v->data + v->size * v->element_size, element, v->element_size);
    v->size++;
}

void* pop(vector* v) {
    if (v->size == 0) {
        return NULL;
    }
    v->size--;
    return v->data + v->size * v->element_size;
}

void* at(vector* v, size_t index) {
    if (index >= v->size) {
        return NULL;
    }
    return v->data + index * v->element_size;
}

void insert_element(vector* v, size_t index, void* element) {
    if (index > v->size) {
        return;
    }
    if (v->size == v->capacity) {
        resize(v, v->capacity * 2);
    }
    memmove(v->data + (index + 1) * v->element_size, v->data + index * v->element_size, (v->size - index) * v->element_size);
    memcpy(v->data + index * v->element_size, element, v->element_size);
    v->size++;
}

void remove_element(vector* v, size_t index) {
    if (index >= v->size) {
        return;
    }
    memmove(v->data + index * v->element_size, v->data + (index + 1) * v->element_size, (v->size - index - 1) * v->element_size);
    v->size--;
}

void resize(vector* v, size_t new_capacity) {
    v->data = realloc(v->data, v->element_size * new_capacity);
    v->capacity = new_capacity;
}

bool find(vector* v, void* element) {
    for (size_t i = 0; i < v->size; i++) {
        if (memcmp((char*)v->data + i * v->element_size, element, v->element_size) == 0) {
            return true;
        }
    }
    return false;
}

void print_vector(vector* v) {
    for (size_t i = 0; i < v->size; i++) {
        printf("%p\n", v->data + i * v->element_size);
    }
}

void pretty_print_vector(vector* v, const type t) {
    for (size_t i = 0; i < v->size; i++) {
        switch (t) {
            case INT:
                printf("%d\n", *(int*)(v->data + i * v->element_size));
                break;
            case FLOAT:
                printf("%f\n", *(float*)(v->data + i * v->element_size));
                break;
            case DOUBLE:
                printf("%lf\n", *(double*)(v->data + i * v->element_size));
                break;
            case CHAR:
                printf("%c\n", *(char*)(v->data + i * v->element_size));
                break;
            case STRING:
                printf("%s\n", (char*)(v->data + i * v->element_size));
                break;
            default:
                break;
        }
    }
}