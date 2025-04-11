/*
** EPITECH PROJECT, 2025
** B-CPE-200-PAR-2-1-amazed-valentin.mine-perso
** File description:
** main
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>
#include <stdlib.h>
#include "vectors.h"
#include "algo.h"

int main(void)
{
    int nb_robots = 3;
    char *start = "0";
    char *end = "1";

    vector_t *rooms = vector_create(4, sizeof(char *));
    char *r1 = strdup("2");
    char *r2 = strdup("3");
    vector_pushback(&rooms, &r1);
    vector_pushback(&rooms, &r2);

    vector_t *tunnels = vector_create(4, sizeof(char *));
    char *t1 = strdup("0-2");
    char *t2 = strdup("2-3");
    char *t3 = strdup("3-1");
    vector_pushback(&tunnels, &t1);
    vector_pushback(&tunnels, &t2);
    vector_pushback(&tunnels, &t3);

    printf("#number_of_robots\n%d\n", nb_robots);
    printf("#rooms\n##start\n0 1 0\n##end\n1 13 0\n2 5 0\n3 9 0\n");
    printf("#tunnels\n%s\n%s\n%s\n", t1, t2, t3);

    display_moves(nb_robots, start, end, rooms, tunnels);
    return 0;
}
