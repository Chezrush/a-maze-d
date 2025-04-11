/*
** EPITECH PROJECT, 2025
** astar.c
** File description:
** Implementation of A* pathfinding algorithm
*/

#include <stdlib.h>
#include <string.h>
#include "algo.h"
#include "my.h"

static node_t *create_node(const char *name, node_t *parent)
{
    node_t *n = malloc(sizeof(node_t));

    n->name = strdup(name);
    n->parent = parent;
    return n;
}

static int is_in_visited(vector_t *visited, const char *neighbor)
{
    char *v = NULL;

    for (size_t j = 0; j < vector_getlength(visited); ++j) {
        v = *(char **)vector_get_at(visited, j);
        if (strcmp(v, neighbor) == 0)
            return 1;
    }
    return 0;
}

static char *get_neighbor(edge_t *e, const char *current_name)
{
    if (strcmp(e->from, current_name) == 0)
        return e->to;
    else if (strcmp(e->to, current_name) == 0)
        return e->from;
    return NULL;
}

static vector_t *build_path(node_t *current)
{
    vector_t *path = vector_create(10, sizeof(char *));

    while (current) {
        vector_insert_at(&path, &current->name, 0);
        current = current->parent;
    }
    return path;
}

static void process_neighbors(astar_ctx_t *ctx, node_t *current)
{
    char *neighbor = NULL;
    edge_t *e = NULL;
    node_t *next = NULL;

    for (size_t i = 0; i < vector_getlength(ctx->graph->edges); ++i) {
        e = *(edge_t **)vector_get_at(ctx->graph->edges, i);
        neighbor = get_neighbor(e, current->name);
        if (!neighbor || is_in_visited(ctx->visited, neighbor))
            continue;
        next = create_node(neighbor, current);
        vector_pushback(&ctx->queue, &next);
    }
}

vector_t *astar(graph_t *g, const char *start, const char *end)
{
    astar_ctx_t ctx = {g, vector_create(10, sizeof(node_t *)),
        vector_create(10, sizeof(char *)), start, end};
    node_t *start_node = create_node(start, NULL);
    node_t *current = NULL;

    vector_pushback(&ctx.queue, &start_node);
    while (vector_getlength(ctx.queue)) {
        current = *(node_t **)vector_get_at(ctx.queue, 0);
        vector_pop_at(ctx.queue, 0);
        if (strcmp(current->name, end) == 0)
            return build_path(current);
        vector_pushback(&ctx.visited, &current->name);
        process_neighbors(&ctx, current);
    }
    return vector_create(10, sizeof(char *));
}
