/*
** EPITECH PROJECT, 2025
** lib_vectors
** File description:
** auto_free
*/

#include "vectors.h"

void autofree_func(vector_t **ptr)
{
    if (*ptr) {
        vector_destroy(*ptr);
        *ptr = NULL;
    }
}
