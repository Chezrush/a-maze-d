/*
** EPITECH PROJECT, 2025
** build_graph.c
** File description:
** Function to build a graph from tunnel data
*/

#include <stdlib.h>
#include <string.h>
#include "algo.h"

static edge_t *create_edge(const char *line)
{
    char *sep = strchr(line, '-');
    edge_t *edge = NULL;

    if (!sep)
        return NULL;
    edge = malloc(sizeof(edge_t));
    edge->from = strndup(line, sep - line);
    edge->to = strdup(sep + 1);
    return edge;
}

graph_t *build_graph(vector_t *tunnels)
{
    graph_t *graph = malloc(sizeof(graph_t));
    edge_t *e = NULL;
    char *line = "";

    graph->nodes = vector_create(10, sizeof(char *));
    graph->edges = vector_create(10, sizeof(edge_t *));
    for (size_t i = 0; i < vector_getlength(tunnels); ++i) {
        line = *(char **)vector_get_at(tunnels, i);
        e = create_edge(line);
        if (e)
            vector_pushback(&graph->edges, &e);
    }
    return graph;
}
