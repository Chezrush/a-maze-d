/*
** EPITECH PROJECT, 2025
** test.c
** File description:
** test.c
*/

#include "my.h"

char *my_revstr(char *str)
{
    int i = my_strlen(str);
    int j = 0;
    char tmp[i + 1];

    my_strcpy(tmp, str);
    for (; i >= 0; i--) {
        str[j] = tmp[i - 1];
        j++;
    }
    str[i] = '\0';
    return str;
}
