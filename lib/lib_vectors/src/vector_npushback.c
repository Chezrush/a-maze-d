/*
** EPITECH PROJECT, 2025
** lib_vectors
** File description:
** vector_npushback
*/

#include "my.h"
#include "vectors.h"

int vector_npushback(vector_t **vector, const void *new_elems, size_t n)
{
    void *new_data = NULL;
    size_t old_capacity = (*vector)->capacity;

    while ((*vector)->capacity < (*vector)->nb_elems + n) {
        (*vector)->capacity *= 2;
    }
    if ((*vector)->capacity != old_capacity) {
        new_data = my_realloc((*vector)->data, (*vector)->capacity
            * (*vector)->size_elems);
        if (!new_data) {
            return FAIL_INT;
        }
        (*vector)->data = new_data;
    }
    my_memcpy((char *)(*vector)->data + ((*vector)->nb_elems *
        (*vector)->size_elems), new_elems, n * (*vector)->size_elems);
    (*vector)->nb_elems += n;
    return 0;
}
