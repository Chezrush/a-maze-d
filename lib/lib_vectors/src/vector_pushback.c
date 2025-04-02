/*
** EPITECH PROJECT, 2025
** lib_vectors
** File description:
** vector_pushback
*/

#include "vectors.h"

int vector_pushback(vector_t **vector, const void *new_elem)
{
    return vector_npushback(vector, new_elem, 1);
}
