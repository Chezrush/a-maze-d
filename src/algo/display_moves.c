/*
** EPITECH PROJECT, 2025
** display_moves.c
** File description:
** Display movement commands for robots
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "algo.h"


static void debug_print_paths(vector_t **paths, int nb_robots)
{
    char *room = NULL;

    for (int i = 0; i < nb_robots; ++i) {
        printf("#path robot %d: ", i + 1);
        for (size_t j = 0; j < vector_getlength(paths[i]); ++j) {
            room = *(char **)vector_get_at(paths[i], j);
            printf("%s ", room);
        }
        printf("\n");
    }
}

static void init_robot_positions(robot_state_t *state)
{
    state->pos = malloc(sizeof(int) * state->nb_robots);
    state->current = malloc(sizeof(char *) * state->nb_robots);
    for (int i = 0; i < state->nb_robots; ++i) {
        state->pos[i] = 1;
        state->current[i] = strdup(state->start);
    }
}

static void update_occupied_rooms(robot_state_t *state)
{
    for (int i = 0; i < state->nb_robots; ++i) {
        if (strcmp(state->current[i], state->start) != 0 &&
            strcmp(state->current[i], state->end) != 0)
            state->occupied[atoi(state->current[i])] = 1;
    }
}

static int move_robot(robot_state_t *state, int i, char *next)
{
    if (strcmp(next, state->end) != 0 && state->occupied[atoi(next)])
        return 0;
    state->current[i] = next;
    state->pos[i]++;
    if (strcmp(next, state->end) != 0)
        state->occupied[atoi(next)] = 1;
    if (state->pos[i] == (int)vector_getlength(state->paths[i]))
        state->finished++;
    return 1;
}

static void print_robot_move(int moved, int i, char *next)
{
    if (moved > 0)
        printf(" ");
    printf("P%d-%s", i + 1, next);
}

static int process_robot_moves(robot_state_t *state)
{
    int moved = 0;
    char *next = NULL;

    for (int i = 0; i < state->nb_robots; ++i) {
        if (!state->paths[i] || state->pos[i] >=
            (int)vector_getlength(state->paths[i]))
            continue;
        next = *(char **)vector_get_at(state->paths[i], state->pos[i]);
        if (move_robot(state, i, next)) {
            print_robot_move(moved, i, next);
            moved++;
        }
    }
    return moved;
}

robot_state_t init_robot_state(maze_t *maze)
{
    robot_state_t state = {
        .nb_robots = maze->num_robots,
        .start = maze->start_room,
        .end = maze->end_room,
        .paths = malloc(sizeof(vector_t *) * maze->num_robots),
        .occupied = calloc(128, sizeof(int)),
        .finished = 0
    };
    for (int i = 0; i < maze->num_robots; ++i)
        state.paths[i] = find_path(maze->start_room, maze->end_room, maze->tunnels);
    return state;
}

static void free_robot_state(robot_state_t *state)
{
    for (int i = 0; i < state->nb_robots; ++i)
        free(state->current[i]);
    free(state->current);
    free(state->pos);
    free(state->paths);
    free(state->occupied);
}

void display_moves(maze_t *maze)
{
    robot_state_t state = init_robot_state(maze);
    int moved = 0;

    (void)maze->rooms;  // j'sais pas trop à quoi elle sert
    printf("#moves\n");
    debug_print_paths(state.paths, maze->num_robots);
    init_robot_positions(&state);
    while (state.finished < maze->num_robots) {
        moved = 0;
        memset(state.occupied, 0, sizeof(int) * 128);
        update_occupied_rooms(&state);
        moved = process_robot_moves(&state);
        if (moved > 0)
            printf("\n");
        else
            break;
    }
    free_robot_state(&state);
}
