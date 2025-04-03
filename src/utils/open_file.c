/*
** EPITECH PROJECT, 2025
** B-CPE-200-PAR-2-1-amazed-valentin.mine-perso
** File description:
** open_file
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

char *read_file(void)
{
    char *line = NULL;
    size_t len = 0;
    ssize_t read;

    printf("Reading input...\n");
    read = getline(&line, &len, stdin);
    while (read != -1) {
        read = getline(&line, &len, stdin);
        printf("Read %zd bytes: %s", read, line);
    }
    if (line)
        printf("Final line: %s\n", line);
    return line;
}
