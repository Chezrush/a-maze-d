/*
** EPITECH PROJECT, 2025
** B-CPE-200-PAR-2-1-amazed-valentin.mine-perso
** File description:
** amazed
*/

#ifndef AMAZED_H
    #define AMAZED_H
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include "vectors.h"

typedef struct maze_s {
    int num_robots;
    vector_t *rooms;
    vector_t *tunnels;
    char *start_room;
    char *end_room;
} maze_t;

int amazed(int const argc, char const *const argv[]);
char *read_file(void);
maze_t *parse_maze(void);
char *my_strchr(const char *s, int c);

#endif /* AMAZED_H*/
