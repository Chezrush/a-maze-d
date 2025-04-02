/*
** EPITECH PROJECT, 2025
** lib_vectors
** File description:
** vector_get_at
*/

#include "vectors.h"

void *vector_get_at(vector_t const *vector, size_t index)
{
    if (index >= vector->nb_elems)
        return NULL;
    return (char *)vector->data + (index * vector->size_elems);
}
