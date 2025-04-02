/*
** EPITECH PROJECT, 2025
** lib_c
** File description:
** my_memcpy
*/

#include <stdio.h>
#include <stddef.h>
#include "my.h"

void *my_memcpy(void *dest, const void *src, size_t size)
{
    size_t count = 0;
    const unsigned char *copy_src = src;
    unsigned char *copy_dest = dest;

    for (count = 0; count < size; count++) {
        copy_dest[count] = copy_src[count];
    }
    return dest;
}
