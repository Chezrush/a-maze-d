/*
** EPITECH PROJECT, 2025
** lib_c
** File description:
** my_realloc
*/

#include <string.h>
#include "my.h"

void *my_realloc(void *ptr, size_t size)
{
    void *reptr = NULL;

    if (ptr == NULL)
        return malloc(size);
    if (size == 0) {
        free(ptr);
        return NULL;
    }
    reptr = malloc(size);
    if (!reptr)
        return NULL;
    my_memcpy(reptr, ptr, size);
    free(ptr);
    return reptr;
}
