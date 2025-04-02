/*
** EPITECH PROJECT, 2025
** lib_vectors
** File description:
** vector_find
*/

#include "vectors.h"

size_t vector_find(vector_t *vector, const void *target,
    int (*compar)(const void *, const void *))
{
    void *elem = {};

    for (size_t i = 0; i < vector->nb_elems; i++) {
        elem = (char *)vector->data + (i * vector->size_elems);
        if (compar(elem, target) == 0) {
            return i;
        }
    }
    return FAIL_INT;
}
