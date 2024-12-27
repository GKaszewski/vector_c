#include "vector_test.h"

void test_init_free_vector() {
    vector v;
    init_vector(&v, sizeof(int), 10);
    assert(v.size == 0);
    assert(v.capacity == 10);
    assert(v.element_size == sizeof(int));
    free_vector(&v);
    assert(v.data == NULL);
    assert(v.size == 0);
    assert(v.capacity == 0);
    assert(v.element_size == 0);
}

void test_push_pop() {
    vector v;
    int elem = 5;
    init_vector(&v, sizeof(int), 2);
    push(&v, &elem);
    assert(v.size == 1);
    assert(*(int*)at(&v, 0) == 5);
    int* popped = (int*)pop(&v);
    assert(*popped == 5);
    assert(v.size == 0);
    free_vector(&v);
}

void test_insert_remove() {
    vector v;
    int elem1 = 1, elem2 = 2, elem3 = 3;
    init_vector(&v, sizeof(int), 2);
    push(&v, &elem1);
    push(&v, &elem3);
    insert_element(&v, 1, &elem2);
    assert(v.size == 3);
    assert(*(int*)at(&v, 1) == 2);
    remove_element(&v, 1);
    assert(v.size == 2);
    assert(*(int*)at(&v, 1) == 3);
    free_vector(&v);
}

void test_resize() {
    vector v;
    int elem = 5;
    init_vector(&v, sizeof(int), 2);
    push(&v, &elem);
    push(&v, &elem);
    resize(&v, 4);
    assert(v.capacity == 4);
    push(&v, &elem);
    assert(v.size == 3);
    free_vector(&v);
}

void test_find() {
    vector v;
    int elem1 = 1, elem2 = 2;
    init_vector(&v, sizeof(int), 2);
    push(&v, &elem1);
    push(&v, &elem2);
    assert(find(&v, &elem1) == true);
    assert(find(&v, &elem2) == true);
    int elem3 = 3;
    assert(find(&v, &elem3) == false);
    free_vector(&v);
}

void run_tests() {
    test_init_free_vector();
    test_push_pop();
    test_insert_remove();
    test_resize();
    test_find();
    printf("All tests passed!\n");
}
