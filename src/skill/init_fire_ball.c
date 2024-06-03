/*
** EPITECH PROJECT, 2023
** game
** File description:
** rpg.h
*/

#include "rpg.h"

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

fire_ball_t *init_fire_ball(void)
{
    fire_ball_t *fire_ball = malloc(sizeof(fire_ball_t));

    fire_ball->level = 0;
    fire_ball->projectil = NULL;
    fire_ball->stamina = 0;
    return (fire_ball);
}
