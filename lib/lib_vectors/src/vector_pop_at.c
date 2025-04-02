/*
** EPITECH PROJECT, 2025
** lib_vectors
** File description:
** vector_pop_at
*/

#include "my.h"
#include "vectors.h"

int vector_pop_at(vector_t *vector, size_t index)
{
    if (index >= vector->nb_elems) {
        return FAIL_INT;
    }
    my_memcpy((char *)vector->data + (index * vector->size_elems),
        (char *)vector->data + ((index + 1) * vector->size_elems),
        (vector->nb_elems - index - 1) * vector->size_elems);
    vector->nb_elems--;
    return 0;
}
