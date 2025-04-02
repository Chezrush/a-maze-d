/*
** EPITECH PROJECT, 2025
** my_strcpy.c
** File description:
** my_strcpy.c
*/

#include "stdio.h"

char *my_strcpy(char *dest, char const *src)
{
    int i = 0;

    for (; src[i] != '\0'; ++i) {
        dest[i] = src[i];
    }
    dest[i] = '\0';
    return dest;
}
