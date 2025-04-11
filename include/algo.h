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
void debug_print_paths(vector_t **paths, int nb_robots);
void init_robot_positions(robot_state_t *state);
void update_occupied_rooms(robot_state_t *state);
int process_robot_moves(robot_state_t *state);
void free_robot_state(robot_state_t *state);
void display_moves(maze_t *maze);

#endif /* ALGO_H */
