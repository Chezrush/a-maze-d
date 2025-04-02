/*
** EPITECH PROJECT, 2025
** lib_vectors
** File description:
** vector_popback
*/

#include "vectors.h"

int vector_popback(vector_t *vector)
{
    if (vector->nb_elems == 0)
        return FAIL_INT;
    vector->nb_elems--;
    return 0;
}
