/*
** EPITECH PROJECT, 2025
** my_str_to_word_array.c
** File description:
** my_str_to_word_array.c
*/

#include <stdio.h>
#include <stdlib.h>
#include "my.h"

int is_delimiteur(char const str, char const *sep)
{
    if (str == '\0')
        return 0;
    for (int i = 0; sep[i] != '\0'; i++) {
        if (sep[i] == str)
            return 0;
    }
    return -1;
}

int count_words(char const *str, char const *sep)
{
    int word = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (is_delimiteur(str[i], sep) < 0
        && is_delimiteur(str[i + 1], sep) == 0)
            word++;
    }
    if (word > 0) {
        word++;
        return word;
    }
    return 0;
}

int get_len(char const *str, char const *sep)
{
    int i = 0;

    while (is_delimiteur(str[i], sep) < 0) {
        i++;
    }
    return i;
}

char **str_to_word_array(char const *str, char const *sep)
{
    int j = 0;
    int k = 0;
    int nbr_lines = count_words(str, sep);
    char **array = malloc(sizeof(char *) * (nbr_lines + 1));

    for (int i = 0; str[i] != '\0'; i++) {
        if (is_delimiteur(str[i], sep) == 0 || str[i] == '\0') {
            continue;
        }
        j = get_len(str + i, sep);
        array[k] = malloc(sizeof(char) * (j + 1));
        my_strncpy(array[k], str + i, j);
        i += j - 1;
        j = 0;
        k++;
    }
    array[k] = NULL;
    return array;
}
