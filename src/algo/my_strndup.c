/*
** EPITECH PROJECT, 2025
** my_strndup.c
** File description:
** e
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>
#include <stdlib.h>
#include "vectors.h"
#include "algo.h"

char *my_strndup(const char *src, size_t n)
{
    size_t len;
    char *dest;

    if (src == NULL)
        return NULL;
    len = 0;
    while (len < n && src[len] != '\0')
        len++;
    dest = (char *)malloc(len + 1);
    if (dest == NULL)
        return NULL;
    my_memcpy(dest, src, len);
    dest[len] = '\0';
    return dest;
}
