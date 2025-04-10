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

static char *rm_comment(char *line)
{
    char *new_line = malloc(sizeof(char) * my_strlen(line) + 1);
    size_t i = 0;

    for (; line[i] != '\0'; i++) {
        if (line[i] == '#') {
            new_line[i] = '\0';
            return new_line;
        }
        new_line[i] = line[i];
    }
    new_line[i] = '\0';
    return new_line;
}

static int check_rooms(char *line, maze_t *maze)
{
    if (my_strncmp(line, "##start", 7) == 0) {
        getline(&line, &(size_t){0}, stdin);
        maze->start_room = my_strdup(rm_comment(line));
    }
    if (my_strncmp(line, "##end", 5) == 0) {
        getline(&line, &(size_t){0}, stdin);
        maze->end_room = my_strdup(rm_comment(line));
        return 0;
    }
    return 0;
}

static int parse_line(char *line, maze_t *maze)
{
    char *dup = my_strdup(line);

    if (dup[0] == '#') {
        return check_rooms(dup, maze);
    }
    dup = rm_comment(dup);
    if (strchr(dup, '-')) {
        vector_pushback(&(maze->tunnels), &dup);
    } else if (strchr(dup, ' '))
        vector_pushback(&(maze->rooms), &dup);
    else {
        maze->num_robots = my_atoi(dup);
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
