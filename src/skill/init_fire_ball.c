/*
** EPITECH PROJECT, 2023
** game
** File description:
** rpg.h
*/

#include "rpg.h"

/*
typedef struct fire_ball_s {
    int level;
    int stamina;
} fire_ball_t;
*/

fire_ball_t fireball_tab[] = {
    {0},
    {15},
    {13},
    {10},
};

void destroy_fire_ball(fire_ball_t *fire_ball)
{
    free(fire_ball);
}

void fire_ball_function(heros_t *heros, rpg_t *, void *skill_data)
{
    fire_ball_t *data = (fire_ball_t *)skill_data;

    if (heros->stamina > data->stamina)
        heros->stamina -= data->stamina;
}
