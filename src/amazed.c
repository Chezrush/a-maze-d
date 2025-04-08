/*
** EPITECH PROJECT, 2025
** B-CPE-200-PAR-2-1-amazed-valentin.mine-perso
** File description:
** amazed
*/

#include "amazed.h"
#include <stdio.h>

int amazed(int const argc, char const *const argv[])
{
    maze_t *maze = parse_maze();

    if (argc != 1)
        return 84;
    (void)argv;
    if (!maze)
        return 84;
    for (size_t i = 0; i < vector_getlength(maze->rooms); i++) {
        printf("- [%ld] = %s\n", i, (char *)vector_get_at(maze->rooms, i));
    }
    for (size_t i = 0; i < vector_getlength(maze->tunnels); i++) {
        printf("- [%ld] = %s\n", i, (char *)vector_get_at(maze->tunnels, i));
    }
    printf("start room %s", maze->start_room);
    printf("end room %s", maze->end_room);
    return 0;
}
