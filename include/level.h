/*
** EPITECH PROJECT, 2023
** graph.h
** File description:
** collisions
*/

#ifndef LEVEL_H
    #define LEVEL_H

    #define SWORD_COST 15
typedef struct level_template_s {
    float pv_max;
    int attack;
    float stamina_max;
    float xp_to_reach;
    float stami_per_sec;
} level_template_t;

extern level_template_t level_tab[];
#endif
