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
    char *room_data = NULL;
    char *tunnel_data = NULL;

    if (maze->tunnels == NULL)
        printf("ACCACA\n");
    for (size_t i = 0; i < vector_getlength(maze->rooms); i++) {
        room_data = *(char **)vector_get_at(maze->rooms, i);
        printf("DEBUG:[%ld] [%s]\n", i, room_data);
    }
    for (size_t i = 0; i < vector_getlength(maze->tunnels); i++) {
        tunnel_data = *(char **)vector_get_at(maze->tunnels, i);
        printf("DEBUG2:[%ld] [%s]\n", i, tunnel_data);
    }
    return 0;
}
int put_first_info(maze_t *maze)
{
    if (maze->num_robots < 1)
        return 84;
    my_put_nbr(maze->num_robots);
    my_putchar('\n');
    if (maze->start_room == NULL)
        return 84;
    my_putstr("##start\n");
    my_putstr(maze->start_room);
    if (maze->end_room == NULL)
        return 84;
    my_putstr("##end\n");
    my_putstr(maze->end_room);
    put_room_info(maze);
    return 0;
}
