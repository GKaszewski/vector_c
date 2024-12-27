#ifndef VECTOR_H
#define VECTOR_H

#include <stdlib.h>
#include <stdbool.h>

#define DEFINE_RESULT(T, E, NAME) \
    typedef struct { \
        bool success : 1; \
        union { \
            T result; \
            E error; \
        }; \
    } NAME;

typedef struct {
    void* data;
    size_t size;
    size_t capacity;
    size_t element_size;
} vector;

DEFINE_RESULT(void*, vector_error, vector_result)
//TODO: rewrite the vector functions to use the vector_result type

typedef enum {
    INT,
    FLOAT,
    DOUBLE,
    CHAR,
    STRING
} type;

typedef enum {
    ELEMENT_SIZE_DOES_NOT_MATCH,
    INDEX_OUT_OF_BOUNDS
} vector_error;

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
void pretty_print_vector(vector* v, const type t);

#endif