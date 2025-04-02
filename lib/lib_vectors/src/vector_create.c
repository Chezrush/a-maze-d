/*
** EPITECH PROJECT, 2025
** lib_vectors
** File description:
** vector_create
*/

#include "vectors.h"

vector_t *vector_create(size_t capacity, size_t size_elems)
{
    vector_t *vector = (vector_t *)malloc(sizeof(vector_t));

    if (!vector) {
        return NULL;
    }
    vector->data = malloc(size_elems * capacity);
    if (!vector->data) {
        free(vector);
        return NULL;
    }
    vector->capacity = capacity;
    vector->nb_elems = 0;
    vector->size_elems = size_elems;
    return vector;
}
