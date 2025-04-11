/*
** EPITECH PROJECT, 2025
** put all
** File description:
** put all information
*/

#include "amazed.h"
#include "my.h"
#include "vectors.h"

static int put_room_info(maze_t *maze)
{
    char *data = NULL;
    size_t len = 0;

    if (!maze || !maze->tunnels || !maze->rooms)
        return 84;
    len = vector_getlength(maze->rooms);
    for (size_t i = 0; i < len; i++) {
        data = *(char **)vector_get_at(maze->rooms, i);
        if (!data)
            return 84;
        printf("DEBUG:[%ld] [%s]\n", i, data);
    }
    len = vector_getlength(maze->tunnels);
    for (size_t i = 0; i < len; i++) {
        data = *(char **)vector_get_at(maze->tunnels, i);
        if (!data)
            return 84;
        printf("DEBUG2:[%ld] [%s]\n", i, data);
    }
    return 0;
}

int put_first_info(maze_t *maze)
{
    if (!maze || maze->num_robots < 1 || !maze->start_room || !maze->end_room)
        return 84;
    my_put_nbr(maze->num_robots);
    my_putchar('\n');
    my_putstr("##start\n");
    my_putstr(maze->start_room);
    my_putstr("##end\n");
    my_putstr(maze->end_room);
    return put_room_info(maze);
}
