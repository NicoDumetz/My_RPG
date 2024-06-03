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

void run_function(heros_t *heros, rpg_t *, void *skill_data)
{
    run_t *data = (run_t *)skill_data;

    if (heros->stamina > data->stamina)
        heros->stamina -= data->stamina;
}

run_t *init_run(void)
{
    run_t *run = malloc(sizeof(run_t));

    run->level = 0;
    run->speed_multi = 1;
    run->stamina = 0;
    return (run);
}
