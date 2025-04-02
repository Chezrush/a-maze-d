/*
** EPITECH PROJECT, 2025
** lib_vectors
** File description:
** vector_destroy
*/

#include "vectors.h"

void vector_destroy(vector_t *vector)
{
    if (vector) {
        free(vector->data);
        free(vector);
    }
}
