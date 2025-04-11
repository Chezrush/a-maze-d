/*
** EPITECH PROJECT, 2025
** find_path.c
** File description:
** Find path from start to end in a tunnel network
*/

#include <stdlib.h>
#include "algo.h"

vector_t *find_path(char *start, char *end, vector_t *tunnels)
{
    graph_t *g = build_graph(tunnels);

    return astar(g, start, end);
}
