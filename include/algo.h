/*
** EPITECH PROJECT, 2025
** algo.h
** File description:
** e
*/

#ifndef ALGO_H
    #define ALGO_H
    #include "vectors.h"
    #include "amazed.h"


typedef struct node_s {
    char *name;
    struct node_s *parent;
    int g;
    int h;
    int f;
} node_t;

typedef struct edge_s {
    char *from;
    char *to;
} edge_t;

typedef struct graph_s {
    vector_t *nodes;
    vector_t *edges;
} graph_t;

typedef struct astar_ctx_s {
    graph_t *graph;
    vector_t *queue;
    vector_t *visited;
    const char *start;
    const char *end;
} astar_ctx_t;

typedef struct robot_state_s {
    int nb_robots;
    char *start;
    char *end;
    vector_t **paths;
    char **current;
    int *pos;
    int *occupied;
    int finished;
} robot_state_t;


robot_state_t init_robot_state(maze_t *maze);
void free_robot_state(robot_state_t *state);
void display_moves(maze_t *maze);

#endif /* ALGO_H */
