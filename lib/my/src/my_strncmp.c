/*
** EPITECH PROJECT, 2025
** my_strncmp.c
** File description:
** my_strncmp.c
*/

#include "my.h"

int my_strncmp(const char *s1, const char *s2, size_t n)
{
    while (n > 0 && *s1 && *s2 && *s1 == *s2) {
        s1++;
        s2++;
        n--;
    }
    if (n == 0) {
        return 0;
    } else {
        return *s1 - *s2;
    }
}
