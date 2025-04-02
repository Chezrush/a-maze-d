/*
** EPITECH PROJECT, 2025
** lib_vectors
** File description:
** vector_pushback_dynamic
*/

#include "my.h"
#include "vectors.h"

int vector_pushback_dynamic(vector_t **vector, const void *new_elem)
{
    if ((*vector)->nb_elems >= (*vector)->capacity) {
        (*vector)->capacity *= 2;
        (*vector)->data = my_realloc((*vector)->data,
            (*vector)->capacity * (*vector)->size_elems);
        if (!(*vector)->data) {
            return FAIL_INT;
        }
    }
    my_memcpy((char *)(*vector)->data + ((*vector)->nb_elems *
        (*vector)->size_elems), new_elem, (*vector)->size_elems);
    (*vector)->nb_elems++;
    return 0;
}
