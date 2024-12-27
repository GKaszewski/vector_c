#ifndef VECTOR_H
#define VECTOR_H

#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    void* data;
    size_t size;
    size_t capacity;
    size_t element_size;
} vector;

void init_vector(vector* v, size_t element_size, size_t capacity);
void free_vector(vector* v);
void push(vector* v, void* element);
void* pop(vector* v);
void* at(vector* v, size_t index);
void insert_element(vector* v, size_t index, void* element);
void remove_element(vector* v, size_t index);
void resize(vector* v, size_t new_capacity);
bool find(vector* v, void* element);
void print_vector(vector* v);
void pretty_print_vector(vector* v, const char* type);

#endif