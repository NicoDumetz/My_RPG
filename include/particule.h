/*
** EPITECH PROJECT, 2023
** graph.h
** File description:
** macro for CSFML
*/

#ifndef PARTICLE_H
    #define PARTICLE_H
    #define NUM_PARTICULES 500
    #include "lib.h"

typedef struct part_s {
    sfVector2f pos;
    sfVector2f velo;
    float lifetime;
    int active;
} part_t;

typedef struct all_part_s {
    sfVertexArray *vertex;
    sfClock *clock;
    part_t particules[NUM_PARTICULES];
    int active;
} all_part_t;

void init_particules(rpg_t *rpg);
void destroy_particules(rpg_t *rpg);
void manage_particules(rpg_t *rpg);
void launch_particules(rpg_t *rpg);
void update_part(rpg_t *rpg);



#endif
