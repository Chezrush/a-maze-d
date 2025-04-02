/*
** EPITECH PROJECT, 2025
** my_strcapitalize.c
** File description:
** my_strcapitalize.c
*/

#include <stdbool.h>

char *my_strcapitalize(char *str)
{
    bool new_word = true;

    for (int i = 0; str[i] != '\0'; ++i) {
        if (new_word && str[i] >= 'a' && str[i] <= 'z') {
            str[i] = str[i] - ('a' - 'A');
            new_word = false;
        }
        if (str[i] >= 'A' && str[i] <= 'Z') {
            new_word = false;
        }
        if (str[i] == ' ' || str[i] == '\t' || str[i] == '\n') {
            new_word = true;
        } else {
            new_word = false;
        }
    }
    return str;
}
