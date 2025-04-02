/*
** EPITECH PROJECT, 2025
** B-CPE-200-PAR-2-1-amazed-valentin.mine-perso
** File description:
** open_file
*/

#include <stdio.h>

char *read_file(void)
{
    char *line = NULL;
    size_t len = 0;
    ssize_t read = 0;

    while ((read = getline(&line, &len, stdin)) != EOF) {
        /*printf("Read %zd bytes, buffer is %zd bytes\n", read, len);
        printf("%s", line);*/
    }
    printf("%s\n", line);
    return line;
}
