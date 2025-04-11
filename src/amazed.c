/*
** EPITECH PROJECT, 2025
** B-CPE-200-PAR-2-1-amazed-valentin.mine-perso
** File description:
** amazed
*/

#include "amazed.h"
#include "algo.h"
#include <stdio.h>

int amazed(int const argc, char const *const argv[])
{
    maze_t *maze = NULL;

    if (argc != 1)
        return 84;
    (void)argv;
    maze = parse_maze();
    if (!maze)
        return 84;
    display_moves(maze);
    return 0;
}
