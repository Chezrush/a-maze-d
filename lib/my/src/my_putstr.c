/*
** EPITECH PROJECT, 2025
** my_putstr.c
** File description:
** my_putstr.c
*/

#include "my.h"

int my_putstr(char const *str)
{
    write(1, str, my_strlen(str));
    return my_strlen(str);
}
