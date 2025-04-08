/*
** EPITECH PROJECT, 2025
** B-CPE-200-PAR-2-1-amazed-valentin.mine-perso
** File description:
** parsing
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdlib.h>
#include "vectors.h"
#include "my.h"
#include "amazed.h"

static int check_rooms(char *line, maze_t *maze)
{
    if (my_strncmp(line, "##start", 7) == 0) {
        if (maze->start_room != NULL)
            maze->start_room = NULL;
        getline(&line, &(size_t){0}, stdin);
        maze->start_room = my_strdup(line);
    }
    if (my_strncmp(line, "##end", 5) == 0) {
        if (maze->end_room != NULL)
            maze->end_room = NULL;
        getline(&line, &(size_t){0}, stdin);
        maze->end_room = my_strdup(line);
        return 0;
    }
    return 0;
}

static int parse_line(char *line, maze_t *maze)
{
    if (line[0] == '#') {
        return check_rooms(line, maze);
    }
    if (my_strchr(line, '-')) {
        vector_pushback(&(maze->tunnels), &line);
    } else if (my_strchr(line, ' ')) {
        vector_pushback(&(maze->rooms), &line);
    } else {
        maze->num_robots = my_atoi(line);
    }
    return 0;
}

maze_t *parse_maze(void)
{
    char *line = NULL;
    size_t len = 0;
    maze_t *maze = malloc(sizeof(maze_t));

    if (!maze)
        return NULL;
    maze->rooms = vector_create(10, sizeof(char *));
    maze->tunnels = vector_create(10, sizeof(char *));
    maze->start_room = NULL;
    maze->end_room = NULL;
    while (getline(&line, &len, stdin) != -1)
        parse_line(line, maze);
    free(line);
    return maze;
}
