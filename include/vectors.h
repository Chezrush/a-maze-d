/*
** EPITECH PROJECT, 2025
** lib_vectors
** File description:
** vectors
*/

#ifndef VECTORS_H
    #define VECTORS_H
    #include <stdlib.h>
    #include <stdio.h>
    #include <string.h>
    #include <unistd.h>
    #include "my.h"
    #define AUTOFREE __attribute__((cleanup(autofree_func)))
    #define FAIL_INT -1

typedef struct vector_s {
    void *data;
    size_t capacity;
    size_t nb_elems;
    size_t size_elems;
} vector_t;

vector_t *vector_create(size_t capacity, size_t size_elems);
void vector_destroy(vector_t *vector);
void *vector_get_at(vector_t const *vector, size_t index);
size_t vector_getlength(vector_t const *vector);
int vector_npushback(vector_t **vector, const void *new_elems, size_t n);
int vector_popback(vector_t *vector);
int vector_pushback(vector_t **vector, const void *new_elem);
int vector_pushback_dynamic(vector_t **vector, const void *new_elem);
void autofree_func(vector_t **ptr);
size_t vector_find(vector_t *vector, const void *target,
    int (*compar)(const void *, const void *));
int vector_insert_at(vector_t **vector, const void *new_elem, size_t index);
int vector_pop_at(vector_t *vector, size_t index);
vector_t *split_word_array(char const *str, char const sep);

#endif /* VECTORS_H */
