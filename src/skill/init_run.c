/*
** EPITECH PROJECT, 2023
** game
** File description:
** rpg.h
*/

#include "rpg.h"

void destroy_run(run_t *run)
{
    free(run);
}

void run_function(heros_t *heros, rpg_t *rpg, void *skill_data)
{
    run_t *data = (run_t *)skill_data;

    if (heros->stamina > 1 && heros->restore == false) {
        heros->stamina -= data->stamina * rpg->time;
        if (!data->active) {
            data->active = true;
            heros->multi_speed *= data->speed_multi;
        }
    }
    if (heros->stamina < 1 && data->active) {
        heros->speed /= data->speed_multi;
        data->active = false;
    }
}

run_t *init_run(void)
{
    run_t *run = malloc(sizeof(run_t));

    run->level = 0;
    run->active = false;
    run->speed_multi = 1.5;
    run->stamina = 20;
    return (run);
}
