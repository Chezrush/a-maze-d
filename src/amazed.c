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

    (void)argc;
    (void)argv;
    if (!maze)
        return 84;
    // là on met la gestion du lab les fratés
    return 0;
}
