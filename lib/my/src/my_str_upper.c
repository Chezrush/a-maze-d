/*
** EPITECH PROJECT, 2025
** my_str_upper.c
** File description:
** my_str_upper
*/

#include <stdio.h>
#include <stdlib.h>

char *my_str_upper(char *str)
{
    for (int i = 0; str[i] != '\0'; ++i) {
        if (str[i] >= 'a' && str[i] <= 'z') {
            str[i] = str[i] - ('a' - 'A');
        }
    }
    return str;
}
