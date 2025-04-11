/*
** EPITECH PROJECT, 2025
** check_line
** File description:
** e
*/

#include "amazed.h"
#include "my.h"

static int is_valid_tunnel_char(const char *line, int i, int *dash)
{
    if (line[i] == '-') {
        if (i > 0 && line[i - 1] == '-')
            return 0;
        (*dash)++;
    } else if (line[i] < '0' || line[i] > '9')
        return 0;
    return 1;
}

int is_valid_tunnel(const char *line)
{
    int i = 0;
    int dash = 0;

    while (line[i]) {
        if (!is_valid_tunnel_char(line, i, &dash))
            return 0;
        i++;
    }
    return dash == 1;
}

int check_file_lines(char **lines)
{
    size_t i = 0;

    if (!lines)
        return 84;
    for (; lines[i]; i++) {
        if (lines[i][0] == '#' || my_strchr(lines[i], ' '))
            continue;
        if (!is_valid_tunnel(lines[i]))
            return 84;
    }
    return 0;
}
