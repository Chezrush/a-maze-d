/*
** EPITECH PROJECT, 2025
** lib_vectors
** File description:
** split_word_array
*/

#include "my.h"
#include "vectors.h"

vector_t *split_word_array(char const *str, char const *sep)
{
    char **tab = my_str_to_word_array(str, sep);
    vector_t *vec = vector_create(10, sizeof(char *));

    if (!tab) {
        return NULL;
    }
    if (!vec) {
        for (int i = 0; tab[i] != NULL; i++)
            free(tab[i]);
        free(tab);
        return NULL;
    }
    for (int i = 0; tab[i] != NULL; i++) {
        vector_pushback(&vec, &tab[i]);
    }
    free(tab);
    return vec;
}
