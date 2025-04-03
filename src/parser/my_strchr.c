/*
** EPITECH PROJECT, 2025
** my_strchr.c
** File description:
** my_strchr
*/

#include <string.h>

char *my_strchr(const char *s, int c)
{
    while (*s) {
        if (*s == (char)c)
            return (char *)s;
        s++;
    }
    if ((char)c == '\0')
        return (char *)s;
    return NULL;
}
