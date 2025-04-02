/*
** EPITECH PROJECT, 2025
** lib_vectors
** File description:
** vector_insert_at
*/

#include "my.h"
#include "vectors.h"

int vector_insert_at(vector_t **vector, const void *new_elem, size_t index)
{
    if (index > (*vector)->nb_elems) {
        return FAIL_INT;
    }
    if ((*vector)->nb_elems >= (*vector)->capacity) {
        (*vector)->capacity *= 2;
        (*vector)->data = my_realloc((*vector)->data,
            (*vector)->capacity * (*vector)->size_elems);
        if (!(*vector)->data) {
            return FAIL_INT;
        }
    }
    my_memcpy((char *)(*vector)->data + ((index + 1) * (*vector)->size_elems),
        (char *)(*vector)->data + (index * (*vector)->size_elems),
        ((*vector)->nb_elems - index) * (*vector)->size_elems);
    my_memcpy((char *)(*vector)->data + (index * (*vector)->size_elems),
        new_elem, (*vector)->size_elems);
    (*vector)->nb_elems++;
    return 0;
}
